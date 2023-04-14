#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "fieldmodel.h"
#include "deckmodel.h"
#include <QObject>
#include <QWidget>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();
public slots:
    /**
     * @brief Place a bet on the given hand.
     * @param hand
     * @return
     */
    bool bet(int hand);

    /**
     * @brief Request a hit from the deck for the currently playing had.
     * @param currentHand - Hand to perform this action on
     * @return False if the hit does not result in a bust.  True if the hit results in a bust.
     */
    bool hit();

    bool hit(int hand);

    /**
     * @brief Adds a card to the dealer's hand
     */
    void dealerHit();

    /**
     * @brief Requests a stay for the current hand.
     * @param currentHand - Hand to perform this action on
     */
    void stay();

    /**
     * @brief Set the player to split their current hand.
     * @param currentHand - Hand to perform this action on
     */
    void split();

    /**
     * @brief Add an insurance to the player's bets.
     */
    void insurance();

    /**
     * @brief Do a double down.  Allows for only one hit, then returns.
     * @param currentHand - Hand to perform this action on
     * @return False if the hit does not result in a bust.  True if the hit results in a bust.
     */
    void doubleDown();

    /**
     * @brief Deal out a starting hand to the player and dealer
     */
    void dealOutCards();

    /**
     * @brief Begins the turn of the dealer, where they reveal their card and hit to 17+.
     */
    void dealerTurn();

    /**
     * @brief End the round, give the player any chips they've won, send cards on the field to the discard pile.
     */
    void endRound();

signals:
    /**
     * @brief Used to tell the view that either the dealer or the player has 'hit'.
     * @param faceDown - True if card is to be dealt face down. False otherwise.
     * @param hand - Represents the hand that a card will be added to. -1 for dealer, 0-infinity for player hands.
     * @param suit - Represents the suit of the card given: 0-Heart, 1-Club, 2-Diamond, 3-Spade.
     * @param rank - Rank of the card: 1 is A, 11 is J, 12 is Q, 13 is K.  0 is Joker, but blackjack isn't palyed with Jokers.
     */
    void hitAction(bool faceDown, int hand, int suit, int rank);
private:
    int currentHand = 0;
    FieldModel fieldModel;
    DeckModel deckModel;
};

#endif // CONTROLLER_H
