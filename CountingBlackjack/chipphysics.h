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
     * @brief createChips - creates a specified number of chips given the users bet amount
     */
    void createChips(int);

    /**
     * @brief updateAnimation - Updates the world state through a wrold step so animation can continue
     */
    void updateAnimation();

    /**
     * @brief getWorldChip - gets a chip body from the world list and returns it to the controller
     * @return a pointer pointing to the chipBody in the world
     */
    b2Body* getWorldChip();

private slots:

};

#endif // CHIPPHYSICS_H
