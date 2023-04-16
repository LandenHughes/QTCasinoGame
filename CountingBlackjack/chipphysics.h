/**
 * @class ChipPhysics
 * @file chipphysics.h
 * @brief Header file to setup Box 2D related objects in order to simulate chips
 * falling.
 */
#ifndef CHIPPHYSICS_H
#define CHIPPHYSICS_H

#include "controller.h"
#include <Box2D/Box2D.h>
#include <QObject>
#include <QWidget>


class ChipPhysics : public QObject
{
    Q_OBJECT

public:
    explicit ChipPhysics(Controller& control, QObject *parent = nullptr);
    ~ChipPhysics();

public slots:

signals:

private:
    Controller &controller; //Controller can send signals to be recieved and such

    //b2AABB world; //Axis aligned bounding box to represent the "world" (our frame)
    b2World* world;

    /**
     * @brief initializes all the components to make chips and their functionality such as
     * position, bouncability, etc.
     */
    void setupBodies();

private slots:

};

#endif // CHIPPHYSICS_H
