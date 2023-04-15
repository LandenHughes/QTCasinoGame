#include "controller.h"

Controller::Controller()
    :deckModel(DeckModel(2))
{

}

bool Controller::bet(int hand, int betAmount)
{
    //TODO: Test that the player has enough money to make bet
    //TODO: Determine correct hand, for now we are working with only one hand
    Hand newHand(betAmount);
    fieldModel.playerHands.push_back(newHand);
    return true;
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
    emit hitAction(false, hand, cardHit.getSuit(), cardHit.getRank());
    return fieldModel.getPlayerHand(hand).getScore() > 21;
}

void Controller::dealerHit()
{
    Card cardHit = deckModel.dealCard();
    fieldModel.dealerHand.push_back(cardHit);
    if(fieldModel.isDealerCardHidden)
    {
        emit hitAction(true, -1, cardHit.getSuit(), cardHit.getRank());
        fieldModel.isDealerCardHidden = false;
    }
    else emit hitAction(false, -1, cardHit.getSuit(), cardHit.getRank());
}

void Controller::stand()
{
    currentHand++;
    if (currentHand > fieldModel.getPlayerHands().size())
        dealerTurn();
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
    fieldModel.playerChips -= fieldModel.insurePlayer();
}

void Controller::doubleDown()
{
    fieldModel.getPlayerHand(currentHand).doubleDown();
    hit();
    stand();
}

void Controller::dealOutCards()
{
    bet(currentHand, currentBet);
    //Deal card to player
    hit();
    //Deal card to dealer
    dealerHit();
    //Deal card to player
    hit();
    //Deal card to dealer
    dealerHit();
}

void Controller::dealerTurn()
{
    //Hit until above 17.
//    while (fieldModel.getDealerScore() < 17)
//    {
//        Card cardHit = deckModel.dealCard();
//        fieldModel.dealerHand.push_back(cardHit);
//    }
//    endRound();
}

void Controller::endRound()
{
    //Let deck and field models calculate payouts, etc.
    deckModel.clearCardsOnField();
    fieldModel.endRound();
}

void Controller::setBet(int newBet)
{
    currentBet = newBet;
}
