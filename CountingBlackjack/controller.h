#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "fieldmodel.h"
#include "deckmodel.h"

class Controller
{
public:
    Controller();

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
     * @brief End the round, give the player any chips they've won, send cards on the field to the discard pile.
     */
    void endRound();

private:
    int currentHand = 0;
    FieldModel fieldModel;
    DeckModel deckModel;
};

#endif // CONTROLLER_H
