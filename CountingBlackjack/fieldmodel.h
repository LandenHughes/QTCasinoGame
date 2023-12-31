#ifndef FIELDMODEL_H
#define FIELDMODEL_H

#include <QVector>
#include "hand.h"
#include "deckmodel.h"

class FieldModel
{
public:
    FieldModel(int playerChips);

    /**
     * @brief getPlayerHands
     * @return All player hands
     */
    QVector<Hand> getPlayerHands();

    /**
     * @brief Deals a new hand for the dealer, discarding the dealer's old hand
     * @return The cards that make up the dealer's hand
     */
    QVector<Card> dealDealerHand(DeckModel& deck);

    /**
     * @brief Deals a new hand for the player. Appends the new hand to the end of playerHands
     * @param bet - The bet for the given hand
     * @return The player's hand
     */
    QVector<Card> dealPlayerHand(DeckModel& deck, int bet);

    /**
     * @brief Returns a QVector of the cards in the current hand.
     * @param currentHand - Hand to perform this action on
     * @return QVector of the cards in the current hand
     */
    Hand getPlayerHand(int currentHand);

    /**
     * @brief Doubles down on the given hand.
     * @param deck - The deck to deal the new cards from
     * @param currentHand - Hand to double down
     */
    Card doubleDownHand(DeckModel& deck, int handIndex);

    /**
     * @brief Adds a given card to a given hand.
     * @param currentHand - Determines which hand to add a card to. -1 refers to the dealers hand. [0-cards.size()) are the players hands
     * @param card - The card to add to
     */
    Card dealToHand(DeckModel& deck, int currentHand);

    /**
     * @brief getDealerHiddenCard
     * @return The first card in dealerHand
     */
    Card getDealerHiddenCard();

    /**
     * @brief Splits the current hand into two new hands, with the new hand going to the end of the hands list.
     * @param deck - The deck to deal the new cards from
     * @param currentHand - hand to split
     * @return Index of the new split hand.
     */
    int splitHand(DeckModel& deck, int handIndex);

    /**
     * @brief Insures the player's hand
     * @param hand
     */
    void insureHand(int hand);

    /**
     * @brief Since the dealer's hand differs fundementally from a player's hand, it's score will be calculated here.
     * @return Score of the dealer.
     */
    int getDealerScore();

    /**
     * @brief getPlayerChips
     * @return playerChips
     */
    int getPlayerChips();

    /**
     * @brief setPlayerChips
     * @param newChipAmount
     */
    void setPlayerChips(int newChipAmount);

    /**
     * @brief isDealerCardHidden
     * @return whether or not the dealer card should be hidden. True if there are two cards or less cards and the hand is not blackjack
     */
    bool isDealerCardHidden();

    /**
     * @brief isHandBlackjack
     * @param hand - The hand to be checked. -1 is dealer's hand [0, playerHands.size()) are player hands.
     * @return whether or not the given hand is blackjack
     */
    bool isDealerHandBlackjack();

    /**
     * @brief canOfferInsurance
     * @param hand - the hand which will be insured
     * @return Whether or not insurance should be offered for the current hand
     */
    bool canOfferInsurance(int hand);

    /**
     * @brief Ends the round, gives payouts, clears everything up (reset).
     */
    void endRound();

    bool playerWin;//used for the box2d to determine how many chips to generate
    bool isWinBlackjack;

private:
    //How many chips are in the player's has left to bet with. Does not include chips in play.
    int playerChips;
    //Dealer's hand.  The dealer's hand is fundementally different than the players (they can't split, etc.
    QVector<Card> dealerHand;
    //Represents the hands of the player.  Needs to be layered like this to represent splits.
    QVector<Hand> playerHands;
};

#endif // FIELDMODEL_H
