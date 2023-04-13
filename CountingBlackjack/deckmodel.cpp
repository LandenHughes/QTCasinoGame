#include "deckmodel.h"

DeckModel::DeckModel(int numberOfDecks)
{
   for (int i = 0; i < numberOfDecks; i++)
       for (int rank = 1; rank <= 13; rank++)
           for (int suit = 0; suit < 4; suit++)
               cardsInDeck.push_back(Card(rank, suit));

   shuffle();
}

void DeckModel::dealOutCards()
{
    for (int i = 0; i < 2; i++)
    {
        getPlayerHand(0).push_back(cardsInDeck.last());
        cardsInDeck.pop_back();
        cardsOnField.push_back(cardsInDeck.last());
        fieldModel.dealerHand.push_back(cardsInDeck.last());
        cardsInDeck.pop_back();
        cardsOnField.push_back(cardsInDeck.last());
    }
}

void DeckModel::reshuffle()
{
    cardsInDeck.append(cardsDiscarded);
    cardsDiscarded.clear();
    shuffle();
}

void DeckModel::endRound()
{
    cardsDiscarded.append(cardsOnField);
    cardsOnField.clear();
    fieldModel.endRound();
}

bool DeckModel::hit(int currentHand)
{
    getPlayerHand(currentHand).push_back(cardsInDeck.last());
    cardsOnField.push_back(cardsInDeck.last());
    cardsInDeck.pop_back();
    return fieldModel.getHandScore(currentHand) > 21;
}

void DeckModel::stay(int currentHand)
{
    //TODO: Implement.  I'm not sure yet what this is supposed to do? It just seemed important to have for later.  If I'm wrong, delete this later. -Lucas
}

void DeckModel::split(int currentHand)
{
    //Check if split can be done with current hand.  Must be a fresh hand with matching rank cards.
    if (getPlayerHand(currentHand).size() != 2)
        return;
    Card card1 = getPlayerHand(currentHand).at(0);
    Card card2 = getPlayerHand(currentHand).at(1);
    if (card1.getRank() != card2.getRank())
        return;
    //Turn split hand into 2 new hands.
    //Create a new hand.

    //TODO: Complete implementation.
}

void DeckModel::insurance()
{
    fieldModel.insurePlayer();
}

bool DeckModel::doubleDown(int currentHand)
{
    //Make sure the plater can double down (total of the 2 cards is 9, 10, or 11)
    if (getPlayerHand(currentHand).size() != 2)
        return false;
    Card card1 = getPlayerHand(currentHand).at(0);
    Card card2 = getPlayerHand(currentHand).at(1);
    if (9 > card1.getRank() + card2.getRank() || card1.getRank() + card2.getRank() > 11)
        return false;

    //On double down, you get 1 hit, that's it.
    hit(currentHand);
    stay(currentHand);
    fieldModel.doubledDownHands.push_back(currentHand);

    //Return if it busted or not.
    return fieldModel.getHandScore(currentHand) > 21;
}

void DeckModel::shuffle()
{
    //TODO: Implement shuffle.
}

QVector<Card> DeckModel::getPlayerHand(int currentHand)
{
    if (0 <= currentHand && currentHand < fieldModel.getPlayerHands().size())
        return fieldModel.getPlayerHands().at(currentHand);
    return QVector<Card>();
}
