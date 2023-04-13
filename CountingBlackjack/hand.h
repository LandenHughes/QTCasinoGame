#ifndef HAND_H
#define HAND_H

#include <QVector>
#include "card.h"

class Hand
{
public:
    Hand();

    /**
     * @brief Insures the hand.
     * @return Cost of insuring the hand.
     */
    int insureHand();

    /**
     * @brief getScore
     * @return Total score of hand
     */
    int getScore();

    void addCard(Card card);

    void doubleDown();

    bool insured;
    bool doubledDown;
    int bet;
    QVector<Card> cards;
};

#endif // HAND_H
