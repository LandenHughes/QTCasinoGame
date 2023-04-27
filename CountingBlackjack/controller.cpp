#include "controller.h"

Controller::Controller()
    :fieldModel(FieldModel(0)),
    deckModel(DeckModel(0))
{
    chipTimer = new QTimer(this);
    connect(chipTimer, &QTimer::timeout, this, &Controller::updateChips);
}

bool Controller::hit()
{
    return hit(currentHand);
}

bool Controller::hit(int hand)
{
    Card card = fieldModel.dealToHand(deckModel, hand);

    emit hitAction(card, hand == -1);

    emit setDoubleButtonEnabled(false);
    emit setSplitButtonEnabled(false);
    emit setHitButtonEnabled(fieldModel.getPlayerHand(hand).canHit());
    emit setPlayerTotal(fieldModel.getPlayerHand(hand).getScore());

    return fieldModel.getPlayerHand(hand).getScore() > 21;
}

int Controller::cardsInDeck()
{
    return deckModel.numCardsInDeck();
}

void Controller::initalizeGame(int playerChips, int numberDecks)
{
    fieldModel = FieldModel(playerChips);
    deckModel = DeckModel(numberDecks);

    emit setChipTotal(playerChips);
}

void Controller::initalizeGame(int playerChips, Card cards[], int numCards)
{
    fieldModel = FieldModel(playerChips);
    deckModel = DeckModel(cards, numCards);

    emit setChipTotal(playerChips);
}

void Controller::burnCards(int numCards)
{
    deckModel.burnCards(numCards);
}

void Controller::dealerHit()
{
    Card card = fieldModel.dealToHand(deckModel, -1);
    emit hitAction(card, true, false);
    emit setDealerTotal(fieldModel.getDealerScore());
}

void Controller::endTurn()
{
    if(fieldModel.canOfferInsurance(currentHand)) emit offerInsurance();
    else stand();
}

void Controller::stand()
{
    currentHand++;
    if (currentHand >= fieldModel.getPlayerHands().size())
        dealerTurn();
    else
        playOnHand(currentHand);
}

void Controller::split()
{
    //DOES NOT CHECK IF THIS CAN BE DONE.
    fieldModel.splitHand(deckModel, currentHand);

    emit setChipTotal(fieldModel.getPlayerChips());

    playOnHand(currentHand);
}

void Controller::acceptInsurance()
{
    emit showInsuranceButtons(false);
    fieldModel.insureHand(currentHand);
    emit setChipTotal(fieldModel.getPlayerChips());
    stand();
}

void Controller::denyInsurance()
{
    emit showInsuranceButtons(false);
    stand();
}

void Controller::doubleDown()
{
    Card card = fieldModel.doubleDownHand(deckModel, currentHand);
    chip.addWinningChips(false);//double the chips displayed
    emit hitAction(card);
    emit setChipTotal(fieldModel.getPlayerChips());
    emit setDoubleButtonEnabled(false);
    emit setSplitButtonEnabled(false);
    emit setHitButtonEnabled(false);
    emit setPlayerTotal(fieldModel.getPlayerHand(currentHand).getScore());
}

void Controller::dealOutCards(int numberHands, int bet)
{
    if(bet > fieldModel.getPlayerChips())
        emit insufficientChips();
    QVector<Card> playerHands;
    for(int i = 0; i < numberHands; i++)
        playerHands.append(fieldModel.dealPlayerHand(deckModel, bet));
    QVector<Card> dealerHand = fieldModel.dealDealerHand(deckModel);

    emit initialDeal(dealerHand, playerHands, fieldModel.getPlayerChips());

    currentHand = 0;
    playOnHand(currentHand);
    emit setPlayerTotal(fieldModel.getPlayerHand(currentHand).getScore());
    emit setDealerTotal(fieldModel.getDealerScore() - fieldModel.getDealerHiddenCard().getValue());
}

void Controller::dealerTurn()
{
    emit showCard(fieldModel.getDealerHiddenCard(), true, 0);
    emit setDealerTotal(fieldModel.getDealerScore());
    //Hit until above 17.
    while (fieldModel.getDealerScore() < 17)
        dealerHit();
    endRound();
}

void Controller::endRound()
{
    //Let deck and field models calculate payouts, etc.
    deckModel.clearCardsOnField();
    fieldModel.endRound();
    emit setChipTotal(fieldModel.getPlayerChips());
    emit roundFinished();

    if(fieldModel.playerWin)
    {
        if(fieldModel.isWinBlackjack)
        {
            chip.addWinningChips(true);
            return;
        }
        chip.addWinningChips(false);
    }
    else//player lost so remove chips
    {
        chip.clearWorld();
    }

}

void Controller::playOnHand(int handPos)
{
    Hand hand = fieldModel.getPlayerHand(handPos);
    emit setPlayerTotal(hand.getScore());
    emit setDoubleButtonEnabled(hand.canDouble());
    emit setSplitButtonEnabled(hand.canSplit());
    emit setHitButtonEnabled(hand.canHit());
    emit setStandButtonEnabled(true);
    emit displayCardsInPlayerArea(hand.asList());
}

void Controller::updateChips()
{
    chip.updateAnimation(); //Tells the world to step
    emit notifyUpdateChipView(chip.getWorldChip());
}

void Controller::createChips(int betAmt)
{
    chip.clearWorld();
    chip.createChips(betAmt, 0);
    chipTimer->start(10); //16ms is 60 frames a second
}

void Controller::setPlayerChips(int newChipAmount)
{
    fieldModel.setPlayerChips(newChipAmount);
    emit setChipTotal(newChipAmount);
}
