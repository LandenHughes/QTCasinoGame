#include "hand.h"

Hand::Hand(int initialBet) :
    bet(initialBet)
{ }

Hand::Hand(QVector<Card> initialCards, int initialBet) :
    bet(initialBet),
    cards(initialCards)
{ }

Hand Hand::split()
{
    Hand result(bet);
    result.addCard(cards.back());
    cards.pop_back();
    return result;
}

QVector<Card> Hand::asList()
{
    return cards;
}

int Hand::getScore()
{
    int scoreTotal = 0;
    int acesTotal = 0;
    for (int i = 0; i < cards.size(); i++)
    {
        Card card = cards.at(i);
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

int Hand::getBet()
{
    return bet;
}

int Hand::numberOfCards()
{
    return cards.size();
}

void Hand::addCard(Card card)
{
    cards.push_back(card);
}

bool Hand::canHit()
{
    return !doubledDown && getScore() < 21;
}

bool Hand::canDouble()
{
    return !doubledDown && cards.size() == 2 && getScore() >= 9 && getScore() <= 11;
}

bool Hand::canSplit()
{
    return !doubledDown && cards.size() == 2 && cards[0].getRank() == cards[1].getRank();
}

bool Hand::isBlackjack()
{
    return cards.size() == 2 && getScore() == 21;
}

void Hand::doubleDown()
{
    doubledDown = true;
    bet *= 2;
}

void Hand::insure()
{
    insured = true;
}

bool Hand::isInsured()
{
    return insured;
}

