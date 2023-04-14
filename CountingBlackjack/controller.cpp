#include "controller.h"

Controller::Controller()
    :deckModel(DeckModel(2))
{
}

bool Controller::bet(int hand)
{
    //TODO
}

bool Controller::hit()
{
    Card cardHit = deckModel.dealCard();
    fieldModel.addToHand(currentHand, cardHit);
    return fieldModel.getPlayerHand(currentHand).getScore() > 21;
}

bool Controller::hit(int hand)
{
    Card cardHit = deckModel.dealCard();
    fieldModel.addToHand(hand, cardHit);
    emit hitAction(false, currentHand, cardHit.getSuit(), cardHit.getRank());
    return fieldModel.getPlayerHand(hand).getScore() > 21;
}

void Controller::dealerHit()
{
    Card cardHit = deckModel.dealCard();
    fieldModel.dealerHand.push_back(cardHit);
    if(fieldModel.isDealerCardHidden) emit hitAction(true, -1, cardHit.getSuit(), cardHit.getRank());
    else emit hitAction(false, -1, cardHit.getSuit(), cardHit.getRank());
}

void Controller::stay()
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
    fieldModel.playerChips -= fieldModel.getPlayerHand(currentHand).insureHand();
}

void Controller::doubleDown()
{
    fieldModel.getPlayerHand(currentHand).doubleDown();
    hit();
    stay();
}

void Controller::dealOutCards()
{
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
    //TODO
    //Please PLEASE put the dealer stuff in here.
    //Eventually...
    endRound();
}

void Controller::endRound()
{
    //Let deck and field models calculate payouts, etc.
    deckModel.clearCardsOnField();
    fieldModel.endRound();
}
