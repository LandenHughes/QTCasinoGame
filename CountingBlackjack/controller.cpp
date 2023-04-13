#include "controller.h"

Controller::Controller()
    :deckModel(DeckModel(2))
{
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
    return fieldModel.getPlayerHand(hand).getScore() > 21;
}

void Controller::stay()
{
    currentHand++;
    if (currentHand > fieldModel.getPlayerHands().size())
        /* TODO, GO TO DEALER's TURN*/;
}

void Controller::split()
{
    //DOES NOT CHECK IF THIS CAN BE DONE.
    int newHandIndex = fieldModel.splitHand(currentHand);
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
    hit();
    fieldModel.dealerHand.push_back(deckModel.dealCard());
    hit();
    fieldModel.dealerHand.push_back(deckModel.dealCard());
}

void Controller::endRound()
{
    deckModel.clearCardsOnField();
    fieldModel.endRound();
}
