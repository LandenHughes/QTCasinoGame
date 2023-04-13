#include "deckmodel.h"

DeckModel::DeckModel(int numberOfDecks)
{
   for (int i = 0; i < numberOfDecks; i++)
       for (int rank = 1; rank <= 13; rank++)
           for (int suit = 0; suit < 4; suit++)
               cardsInDeck.push_back(Card(rank, suit));

   shuffle();
}

void DeckModel::reshuffle()
{
    cardsInDeck.append(cardsDiscarded);
    cardsDiscarded.clear();
    shuffle();
}

void DeckModel::shuffle()
{
    //TODO: Implement shuffle.
}

void DeckModel::clearCardsOnField()
{
    cardsDiscarded.append(cardsOnField);
    cardsOnField.clear();
    if (cardsInDeck.empty())
        reshuffle();
}

Card DeckModel::dealCard()
{
    if (cardsInDeck.empty())
        reshuffle();

    Card dealtCard = cardsInDeck.back();
    cardsOnField.push_back(dealtCard);
    cardsInDeck.pop_back();
    return dealtCard;
}
