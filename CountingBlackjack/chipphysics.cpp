/**
 * @class chipPhysics
 * @file chipphysics.cpp
 * @brief Set parameters and initialize values of the chip body and other factors
 * to create chips that fall and bounce.
 */
#include "chipphysics.h"

chipPhysics::chipPhysics(Controller &control, QObject *parent)
    : QObject(parent)
    , controller(control)
{

}

