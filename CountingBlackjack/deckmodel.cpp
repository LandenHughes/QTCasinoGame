#include "deckmodel.h"
#include <cstdlib>

DeckModel::DeckModel(int numberOfDecks)
{
   for (int i = 0; i < numberOfDecks; i++)
       for (int rank = 1; rank <= 13; rank++)
           for (int suit = 0; suit < 4; suit++)
               cardsInDeck.push_back(Card(suit, rank));

   shuffle();
}

DeckModel::DeckModel(Card cardsToAdd[], int numCards)
{
   for (int i = 0; i < numCards; i++)
        cardsInDeck.push_front(cardsToAdd[i]);
}

void DeckModel::reshuffle()
{
    cardsInDeck.append(cardsDiscarded);
    cardsDiscarded.clear();
    shuffle();
}

void DeckModel::shuffle()
{
    //Sets seed for rand() ~ ensures truly random numbers every time
    srand((unsigned int)time(NULL));
    int cardsToShuffle = cardsInDeck.size();
    for (int swapFrom = 0; swapFrom < cardsToShuffle; swapFrom++)
    {
        Card swappedCard = cardsInDeck[swapFrom];
        int swapTo = rand() % cardsToShuffle;
        cardsInDeck[swapFrom] = cardsInDeck[swapTo];
        cardsInDeck[swapTo] = swappedCard;
    }
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
