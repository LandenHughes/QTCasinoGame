#include "deckmodel.h"

DeckModel::DeckModel(int numberOfDecks)
{
   for (int i = 0; i < numberOfDecks; i++)
       for (int rank = 1; rank <= 13; rank++)
           for (int suit = 0; suit < 4; suit++)
               cardsInDeck.push_back(Card(rank, suit));

   cardsInDeck.
}

void DeckModel::dealOutCards()
{

}

void DeckModel::reshuffle()
{

}

void DeckModel::endRound()
{

}

bool DeckModel::hit()
{

}

void DeckModel::stay()
{

}

void DeckModel::split()
{

}

void DeckModel::insurance()
{

}

void DeckModel::doubleDown()
{

}
