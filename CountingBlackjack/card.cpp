
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
