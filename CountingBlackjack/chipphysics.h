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

    //b2AABB world; //Axis aligned bounding box to represent the "world" (our frame)
    b2World* world;
    bool animationDone;


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
     * @brief placeChipsOnMap - uses a qpainter to draw all the chips on the pixmap representing the chip area in the UI
     */
    void placeChipsOnMap(QPixmap*);

private slots:

};

#endif // CHIPPHYSICS_H
