#ifndef FIELDMODEL_H
#define FIELDMODEL_H

#include <QVector>
#include "hand.h"

class FieldModel
{
public:
    FieldModel();

    /**
     * @brief getPlayerHands
     * @return All player hands
     */
    QVector<Hand> getPlayerHands();

    /**
     * @brief Returns a QVector of the cards in the current hand.
     * @param currentHand - Hand to perform this action on
     * @return QVector of the cards in the current hand
     */
    Hand& getPlayerHand(int currentHand);

    /**
     * @brief Ends the round, gives payouts, clears everything up (reset).
     */
    void endRound();

    /**
     * @brief Splits the current hand into two new hands, with the new hand going to the end of the hands list.
     * @param currentHand
     * @return Index of the new split hand.
     */
    int splitHand(int currentHand);

    /**
     * @brief Adds a given card to a given hand.
     * @param currentHand
     * @param card
     */
    void addToHand(int currentHand, Card card);

    /**
     * @brief Since the dealer's hand differs fundementally from a player's hand, it's score will be calculated here.
     * @return Score of the dealer.
     */
    int getDealerScore();

    //How many chips the player has altogether.
    int playerChips;
    //Determines wether or not the dealer's first card should be displayed or not.
    bool isDealerCardHidden;
    //Dealer's hand.  Tthe dealer's hand is fundementally different than the players (they can't split, etc.
    QVector<Card> dealerHand;
    //Represents the hands of the player.  Needs to be layered like this to represent splits.
    QVector<Hand> playerHands;
};

#endif // FIELDMODEL_H
