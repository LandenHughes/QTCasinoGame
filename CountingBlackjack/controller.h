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
     * @brief Request a hit from the deck for the currently playing had.
     * @param currentHand - Hand to perform this action on
     * @return False if the hit does not result in a bust.  True if the hit results in a bust.
     */
    bool hit();

    bool hit(int hand);

    /**
     * @brief Initalizes the game
     * @param The player's starting chips
     * @param The number of decks in the game
     */
    void initalizeGame(int playerChips, int numberDecks);

    /**
     * @brief Adds a card to the dealer's hand
     */
    void dealerHit();

    /**
     * @brief Requests a stand for the current hand.
     * @param currentHand - Hand to perform this action on
     */
    void stand();

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
    void dealOutCards(int numberHands, int bet);

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
     * @brief Used to tell the view to deal out the initial hands and update the chip counter
     * @param dealerHand - The dealer's current hand
     * @param playerHands - The player's current hands
     * @param totalChips - The total number of chips that the player has after bets
     */
    void initalDeal(QVector<Card> dealerHand, QVector<Card> playerCards, int totalChips);

    /**
     * @brief Used to tell the view that either the dealer or the player has 'hit'.
     * @param hand - Represents the hand that a card will be added to. -1 for dealer, 0-infinity for player hands.
     * @param suit - Represents the suit of the card given: 0-Heart, 1-Club, 2-Diamond, 3-Spade.
     * @param rank - Rank of the card: 1 is A, 11 is J, 12 is Q, 13 is K.  0 is Joker, but blackjack isn't palyed with Jokers.
     */
    void hitAction(int hand, int suit, int rank, bool hideCard = false);

    /**
     * @brief Used to tell the view to flip over a card
     * @param hand - the hand in which to flip the card. -1 for dealer, 0-infinity for player hands.
     * @param card - the card to flip.
     */
    void showCard(int hand, int cardPos, Card card);

    /**
     * @brief Pulls up given hand to act on
     * @param hand - the hand to focus. Note: only works for player hands, -1 in will result in an execption
     */
    void focusHand(QVector<Card> hand);

    /**
     * @brief Updates the chip counter, setting to parameter
     * @param totalChips - The total number of chips that the player has
     */
    void setChipTotal(int totalChips);

    /**
     * @brief A signal to indicate that the round is over
     */
    void roundFinished();

private:
    int currentHand = 0;
    FieldModel fieldModel;
    DeckModel deckModel;
};

#endif // CONTROLLER_H
