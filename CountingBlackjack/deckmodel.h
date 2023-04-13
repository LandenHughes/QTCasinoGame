//Is responsible for the dealing andd management of all cards.

#ifndef DECKMODEL_H
#define DECKMODEL_H

#include "fieldmodel.h"

class DeckModel
{
public:
    /**
     * @brief Constructor, creates a BlackJack using numberOfDeck 52 card standard decks.  Shuffles them.
     * @param numberOfDecks
     */
    DeckModel(int numberOfDecks);

    /**
     * @brief Deal out a starting hand to the player and dealer
     */
    void dealOutCards();

    /**
     * @brief Shuffles all cards from the discard pile back into the deck.
     */
    void reshuffle();

    /**
     * @brief End the round, give the player any chips they've won, send cards on the field to the discard pile.
     */
    void endRound();

    /**
     * @brief Request a hit from the deck for the currently playing had.
     * @param currentHand - Hand to perform this action on
     * @return False if the hit does not result in a bust.  True if the hit results in a bust.
     */
    bool hit(int currentHand);

    /**
     * @brief Requests a stay for the current hand.
     * @param currentHand - Hand to perform this action on
     */
    void stay(int currentHand);

    /**
     * @brief Set the player to split their current hand.
     * @param currentHand - Hand to perform this action on
     */
    void split(int currentHand);

    /**
     * @brief Add an insurance to the player's bets.
     */
    void insurance();

    /**
     * @brief Do a double down.  Allows for only one hit, then returns.
     * @param currentHand - Hand to perform this action on
     * @return False if the hit does not result in a bust.  True if the hit results in a bust.
     */
    bool doubleDown(int currentHand);

    /**
     * @brief Shuffles all cards in cardsInDeck
     */
    void shuffle();

    /**
     * @brief Returns a QVector of the cards in the current hand.
     * @param currentHand - Hand to perform this action on
     * @return QVector of the cards in the current hand
     */
    QVector<Card> getPlayerHand(int currentHand);

private:
    FieldModel fieldModel;
    //These arrays should hold all cards in the initial deck.  Size(all) should = 52 * numberOfDecks at almost all times (not when moving cards between them).
    QVector<Card> cardsInDeck;
    QVector<Card> cardsOnField;
    QVector<Card> cardsDiscarded;
};

#endif // DECKMODEL_H
