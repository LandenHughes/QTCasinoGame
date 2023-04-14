#include "hand.h"

Hand::Hand()
{

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

void Hand::addCard(Card card)
{
    cards.push_back(card);
}

void Hand::doubleDown()
{
    doubledDown = true;
}
