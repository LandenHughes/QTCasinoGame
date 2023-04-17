
#include "card.h"

Card::Card(int suit, int rank)
    :suit(suit)
    ,rank(rank)
{
}

int Card::getSuit()
{
    return suit;
}

int Card::getRank()
{
    return rank;
}

int Card::getValue()
{
    if (this->getRank() >= 10)
        return 10;
    else if (this->getRank() == 1)
        return 11;
    else
        return this->getRank();
}
