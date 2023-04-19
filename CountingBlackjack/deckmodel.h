//Is responsible for the dealing andd management of all cards.

#ifndef DECKMODEL_H
#define DECKMODEL_H

#include "card.h"
#include <QVector>
#include <ctime>

class DeckModel
{
public:
    /**
     * @brief Constructor, creates a BlackJack using numberOfDeck 52 card standard decks.  Shuffles them.
     * @param numberOfDecks
     */
    DeckModel(int numberOfDecks);

    /**
     * @brief Constructor, creates a BlackJack with exactly the cards in cardInDeck.
     * Order of cards is preserved, with the first card in cardsToAdd dealt first.
     * @param cardsToAdd
     * @param numCards
     */
    DeckModel(Card cardsToAdd[], int numCards);

    /**
     * @brief Shuffles all cards in cardsInDeck.
     */
    void shuffle();

    /**
     * @brief Shuffles all cards from the discard pile back into the deck.
     */
    void reshuffle();

    /**
     * @brief Moves a card from cardsInDeck to cardsOnField.
     */
    Card dealCard();

    /**
     * @brief Removes all the cards on the field and discards them.
     */
    void clearCardsOnField();

private:
    //These arrays should hold all cards in the initial deck.  Size(all) should = 52 * numberOfDecks at almost all times (not when moving cards between them).
    QVector<Card> cardsInDeck;
    QVector<Card> cardsOnField;
    QVector<Card> cardsDiscarded;
};

#endif // DECKMODEL_H
