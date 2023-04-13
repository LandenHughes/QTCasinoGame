#ifndef FIELDMODEL_H
#define FIELDMODEL_H

#include <QVector>
#include "card.h"

class FieldModel
{
public:
    //Gets the indexes of the hands that have been doubled down.
    QVector<int> doubledDownHands;
    //The first card is the hidden card.
    QVector<Card> dealerHand;

    FieldModel();
    QVector<QVector<Card>> getPlayerHands();

    /**
     * @brief Insures the player, and removes chips accordingly (half the bet, rounded down).
     */
    void insurePlayer();

    /**
     * @brief Calculates and returns the value of a hand.
     * @param handIndex - Index of hand to calculate
     * @return Score of hand at Index.
     */
    int getHandScore(int handIndex);

    /**
     * @brief Calculates and returns the value of the dealer's hand.
     * @return Score of hand.
     */
    int getDealerScore();

    /**
     * @brief Ends the round, gives payouts, clears everything up (reset).
     */
    void endRound();

protected:
    //Does the player have insurance?
    int isInsured;
    //How many chips the player has altogether.
    int playerChips;
    //How many chips the player has bet this round.
    int betChips;
    //Determines wether or not the dealer's first card should be displayed or not.
    bool isDealerCardHidden;

    //Represents the hands of the player.  Needs to be layered like this to represent splits.
    QVector<QVector<Card>> playerHands;
};

#endif // FIELDMODEL_H
