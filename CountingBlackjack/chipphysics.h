/**
 * @class ChipPhysics
 * @file chipphysics.h
 * @brief Header file to setup Box 2D related objects in order to simulate chips
 * falling.
 */
#ifndef CHIPPHYSICS_H
#define CHIPPHYSICS_H

//#include "controller.h"
#include <Box2D/Box2D.h>
#include <QObject>
#include <QWidget>
#include <QPainter>

class ChipPhysics : public QObject
{
    Q_OBJECT

public:
    explicit ChipPhysics(QObject *parent = nullptr);

    ~ChipPhysics();

public slots:

signals:

public:

    b2World* world;

    /**
     * @brief initializes all the components to make chips and their functionality such as
     * position, bouncability, etc.
     */
    void setupBodies();

    /**
     * @brief createChips - creates a specified number of chips given the user's bet amount
     * @param betAmt - how much the user is betting (each chips is worth 5)
     * @param offset - axis offset if needed so chips don't clip
     */
    void createChips(int betAmt, int offset);

    /**
     * @brief updateAnimation - Updates the world state through a wrold step so animation can continue
     */
    void updateAnimation();

    /**
     * @brief getWorldChip - gets a chip body from the world list and returns it to the controller
     * @return a pointer pointing to the chipBody in the world
     */
    b2Body* getWorldChip();

    /**
     * @brief clearWorld - Clears all the bodies from the world to start with an empty world
     */
    void clearWorld();

    /**
     * @brief addWinningChips - If player winds create that number of chips in the box before clearing
     * @param isBlackjackWin - Add more chips if the win is a blackjack
     */
    void addWinningChips(bool isBlackjackWin);

    /**
     * @brief setupBoundries - sets up the boundries when needed
     */
    void setupBoundries();

private:
    float ppm = 10.0f; //Pixels per Meter ration since Box2D is 1m per 1 pixel
};

#endif // CHIPPHYSICS_H
