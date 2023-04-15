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
    playerHands.push_back(playerHands[handIndex].split());
    return playerHands.size()-1;
}

int FieldModel::insurePlayer()
{
    //TODO
    return 0;
}
