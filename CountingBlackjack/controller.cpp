#include "controller.h"

Controller::Controller()
    :fieldModel(FieldModel(0)),
    deckModel(DeckModel(0))
{
}

bool Controller::hit()
{
    return hit(currentHand);
}

bool Controller::hit(int hand)
{
    Card cardHit = deckModel.dealCard();
    fieldModel.addToHand(hand, cardHit);
    qDebug()<<cardHit.getSuit();
    qDebug()<<cardHit.getRank();
    emit hitAction(hand, cardHit.getSuit(), cardHit.getRank());

    bool isBust = fieldModel.getPlayerHand(hand).getScore() > 21;

    if(isBust)
        stand();
    return isBust;
}

void Controller::initalizeGame(int playerChips, int numberDecks)
{
    fieldModel = FieldModel(playerChips);
    deckModel = DeckModel(numberDecks);

    emit setChipTotal(playerChips);
}

void Controller::dealerHit()
{
    Card cardHit = deckModel.dealCard();
    fieldModel.addToHand(-1, cardHit);
    emit hitAction(-1, cardHit.getSuit(), cardHit.getRank());
}

void Controller::stand()
{
    currentHand++;
    if (currentHand >= fieldModel.getPlayerHands().size())
        dealerTurn();
    else
        emit focusHand(fieldModel.getPlayerHand(currentHand).asList());
}

void Controller::split()
{
    //DOES NOT CHECK IF THIS CAN BE DONE.
    int newHandIndex = fieldModel.splitHand(currentHand);
    //Give each new hand a new card
    hit(currentHand);
    hit(newHandIndex);
}

void Controller::insurance()
{
    //Insures the hand, and subtracts cost from chips.  DOES NOT CHECK IF THIS CAN BE DONE.
    fieldModel.insurePlayer();
}

void Controller::doubleDown()
{
    fieldModel.getPlayerHand(currentHand).doubleDown();
    hit();
    stand();
}

void Controller::dealOutCards(int numberHands, int bet)
{
    QVector<Card> playerHands;
    for(int i = 0; i < numberHands; i++)
        playerHands.append(fieldModel.dealPlayerHand(deckModel, bet));
    QVector<Card> dealerHand = fieldModel.dealDealerHand(deckModel);

    emit initalDeal(dealerHand, playerHands, fieldModel.getPlayerChips());

    currentHand = 0;
    emit focusHand(fieldModel.getPlayerHand(currentHand).asList());

}

void Controller::dealerTurn()
{
    emit showCard(-1, 0, fieldModel.getDealerHiddenCard());
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
}

