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

QVector<QVector<Card>> FieldModel::getPlayerHands()
{
    return playerHands;
}

void FieldModel::insurePlayer()
{
    playerChips -= betChips/2;
    isInsured = true;
}

int FieldModel::getHandScore(int handIndex)
{
    int scoreTotal = 0;
    int acesTotal = 0;
    for (int i = 0; i < playerHands.at(handIndex).size(); i++)
    {
        Card card = playerHands.at(handIndex).at(i);
        if (card.getRank() >= 10)
            scoreTotal += 10;
        else
            scoreTotal += card.getRank();

        if (card.getRank() == 1)
            acesTotal++;
    }

    //Add aces bonus for 1 or 11
    while (scoreTotal <= 11 && acesTotal > 0)
    {
        scoreTotal += 10;
        acesTotal--;
    }

    return scoreTotal;
}

void FieldModel::endRound()
{
    //TODO: Give Payouts



}
