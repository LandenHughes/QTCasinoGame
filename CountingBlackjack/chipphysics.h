/**
 * @class chipPhysics
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


class chipPhysics : public QObject
{
    Q_OBJECT

public:
    explicit chipPhysics(Controller& control, QObject *parent = nullptr);

public slots:

signals:

private:
    Controller &controller; //Controller can send signals to be recieved and such
    b2BodyDef chipBody; //Body of the chip(s)
    b2AABB world; //Axis aligned bounding box to represent the "world" (our frame)

};

#endif // CHIPPHYSICS_H
