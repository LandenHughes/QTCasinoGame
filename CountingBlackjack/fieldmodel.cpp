//This class is the model for the field, or the currently visible playable area.
//It includes...
//Chip totals
//Hands for the round
//Dealer
//dealers hidden card

#include "fieldmodel.h"

FieldModel::FieldModel()
{

}

QVector<Hand> FieldModel::getPlayerHands()
{
    return playerHands;
}

Hand& FieldModel::getPlayerHand(int handIndex)
{
    return playerHands[handIndex];
}

void FieldModel::endRound()
{
    //TODO: Give Payouts

    //Clear all variables to a 0 state (except chips)
    playerHands.clear();
    dealerHand.clear();
    isDealerCardHidden = true;
}

void FieldModel::addToHand(int currentHand, Card card)
{
    playerHands[currentHand].addCard(card);
}

int FieldModel::splitHand(int handIndex)
{
    //Assumes the hand is valid
    //Copy the hand.
    playerHands.push_back(Hand(playerHands.at(handIndex)));
    //Remove the last card from the original hand.
    playerHands[handIndex].cards.pop_back();
    //Remove the first card from the original hand.
    playerHands.back().cards.pop_front();
    //Return index of the new hand (at the end).
    return playerHands.size()-1;
}
