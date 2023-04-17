#ifndef CARD_H
#define CARD_H


class Card
{
public:
    Card(int suit, int rank);
    int getSuit();
    int getRank();
    int getValue();
private:
    //Suit: 0-Heart, 1-Club, 2-Diamond, 3-Spade.  Odds are black if that helps.
    int suit;
    //Rank of the card: 1 is A, 11 is J, 12 is Q, 13 is K.  0 is Joker, but blackjack isn't palyed with Jokers.
    int rank;
};

#endif // CARD_H
