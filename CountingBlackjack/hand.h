#ifndef HAND_H
#define HAND_H

#include <QVector>
#include "card.h"

class Hand
{
public:
    /**
     * @brief Creates a new hand with a given inital bet
     * @param The initial bet
     */
    Hand(int initialBet);

    /**
     * @brief Creates a new hand with the given cards and the given inital bet
     * @param The initalCards
     * @param The initial bet
     */
    Hand(QVector<Card> initialCards, int initialBet);

    /**
     * @brief splits the hand into 2 hands
     * @return
     */
    Hand split();

    /**
     * @brief asList
     * @return The cards in the hand as a QVector
     */
    QVector<Card> asList();

    /**
     * @brief getScore
     * @return Total score of hand
     */
    int getScore();

    /**
     * @brief getBet
     * @return Current bet
     */
    int getBet();

    /**
     * @brief getNumCards
     * @return
     */
    int numberOfCards();

    /**
     * @brief canHit
     * @return Whether the can hand can be hit
     */
    bool canHit();

    /**
     * @brief canSplit
     * @return Whether the current hand can be split
     */
    bool canSplit();

    /**
     * @brief canDouble
     * @return Whether the current hand can be doubled down
     */
    bool canDouble();

    /**
     * @brief isBlackjack
     * @return
     */
    bool isBlackjack();

    /**
     * @brief isInsured
     * @return Whether the current hand is insured
     */
    bool isInsured();

    /**
     * @brief Adds a card to the hand
     * @param The card to add to the hand
     */
    void addCard(Card card);

    /**
     * @brief Doubles the current bet, and blocks future hits
     */
    void doubleDown();

    /**
     * @brief Insures the hand against blackjack
     */
    void insure();

private:
    bool insured;
    bool doubledDown;
    int bet;
    QVector<Card> cards;
};

#endif // HAND_H
