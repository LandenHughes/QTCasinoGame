#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "chipphysics.h"
#include "fieldmodel.h"
#include "deckmodel.h"
#include <QObject>
#include <QWidget>
#include <QTimer>

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

    /**
     * @brief Initalizes the game
     * @param The player's starting chips
     * @param The number of decks in the game
     */
    void initalizeGame(int playerChips, int numberDecks);

    /**
     * @brief Initalizes the game
     * @param The player's starting chips
     * @param The number of decks in the game
     */
    void initalizeGame(int playerChips, Card cards[], int numCards);

    /**
     * @brief Adds a card to the dealer's hand
     */
    void dealerHit();

    /**
     * @brief Plays through insurance if necessary, then calls stand()
     */
    void endTurn();

    /**
     * @brief Requests a stand for the current hand.
     */
    void stand();

    /**
     * @brief Set the player to split their current hand.
     * @param currentHand - Hand to perform this action on
     */
    void split();

    /**
     * @brief acceptInsurance
     */
    void acceptInsurance();

    /**
     * @brief denyInsurance
     */
    void denyInsurance();


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

//    /**
//     * @brief doChipPhysics - sends
//     */
//    void doChipPhysics(QPixmap*);

    /**
     * @brief Method runs on a timer, tells the world to update, and the view to draw
     */
    void updateChips();

    /**
     * @brief createChips
     * @param betAmt
     */
    void createChips(int betAmt);

signals:
    /**
     * @brief Used to tell the view to deal out the initial hands and update the chip counter
     * @param dealerHand - The dealer's current hand
     * @param playerHands - The player's current hands
     * @param totalChips - The total number of chips that the player has after bets
     */
    void initialDeal(QVector<Card> dealerHand, QVector<Card> playerCards, int totalChips);

    /**
     * @brief Used to tell the view that either the dealer or the player has 'hit'.
     * @param card - The card to add to view
     * @param toDealerHand - Whether to add the card to the dealer's hand.
     * @param faceDown - Whether the card will be dealt face down
     */
    void hitAction(Card card, bool toDealerHand = false, bool faceDown = false);

    /**
     * @brief Used to tell the view to flip over a card
     * @param hand - the hand in which to flip the card. -1 for dealer, 0-infinity for player hands.
     * @param card - the card to flip.
     */
    void showCard(Card card, int inDealerHand, int cardPos);

    /**
     * @brief Pulls up given hand to act on
     * @param hand - the hand to focus. Note: only works for player hands, -1 in will result in an execption
     */
    void displayCardsInPlayerArea(QVector<Card> hand);

    /**
     * @brief Use to tell the view to update the chip counter
     * @param totalChips - The total number of chips that the player has
     */
    void setChipTotal(int totalChips);

    /**
     * @brief Use to tell the view to enables/disables split button
     * @param enabled - If true, the button is enabled. Otherwise, it is disabled
     */
    void setSplitButtonEnabled(bool enabled);

    /**
     * @brief Use to tell the view to enables/disables double up button
     * @param enabled - If true, the button is enabled. Otherwise, it is disabled
     */
    void setDoubleButtonEnabled(bool enabled);

    /**
     * @brief Use to tell the view to enables/disables hit button
     * @param enabled - If true, the button is enabled. Otherwise, it is disabled
     */
    void setHitButtonEnabled(bool enabled);

    /**
     * @brief Use to tell the view to enables/disables Stand button.  Used for lessons.
     * @param enabled - If true, the button is enabled. Otherwise, it is disabled
     */
    void setStandButtonEnabled(bool enabled);

    void setDenyInsuranceButtonEnabled(bool enabled);

    /**
     * @brief Sets the label which tells the player their current total to newTotal
     * @param newTotal
     */
    void setPlayerTotal(int newTotal);

    /**
     * @brief Sets the label which tells the player the dealer's current total to newDTotal
     * @param newDTotal
     */
    void setDealerTotal(int newDTotal);

    /**
     * @brief Use to tell the view to offer insurance
     */
    void offerInsurance();
    /**
     * @brief Signal to indicate that the round is over
     */
    void roundFinished();

    /**
     * @brief Clear the table of all cards
     */
    void clearTable();

    /**
     * @brief signal to tell view to update the chip label
     * @param chipBodyList - world sends chip information to the view so it can be drawn
     */
    void notifyUpdateChipView(b2Body *chipBodyList);

    /**
     * @brief notifyUpdateChipAnimationDone - chip animation is done
     */
    void notifyUpdateChipAnimationDone();

    /**
     * @brief signal to tell view to either show or hide insurance buttons
     * @param show
     */
    void showInsuranceButtons(bool show);

private:
    /**
     * @brief Moves plays to given hand
     * @param hand - hand to move play to
     */
    void playOnHand(int hand);

    /**
     * @brief Displays hand and offers insurance on it
     * @param hand - hand to offer insurance on it
     */
    void offerInuranceOnHand(int hand);

    bool hit(int hand);

    int currentHand = 0;
    FieldModel fieldModel;
    DeckModel deckModel;
    ChipPhysics chip;
    QTimer *chipTimer;
};

#endif // CONTROLLER_H
