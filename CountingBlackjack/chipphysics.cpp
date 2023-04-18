/**
 * @class ChipPhysics
 * @file chipphysics.cpp
 * @brief Set parameters and initialize values of the chip body and other factors
 * to create chips that fall and bounce.
 */
#include "chipphysics.h"

ChipPhysics::ChipPhysics(Controller &control, QObject *parent)
    : QObject(parent)
    , controller(control)
{
    setupBodies();


    //Connections
}

ChipPhysics::~ChipPhysics()
{
    delete world;
}

void ChipPhysics::setupBodies()
{
    //TODO: values are just placeholders for now!!! fix later

    b2BodyDef chipBodyDef; //Body of the chip(s)

    //World setup
    world = new b2World(b2Vec2(0.0f, -9.8)); //-9.8m/s^2 is Earth's gravity

    //Body setup - https://box2d.org/documentation/md__d_1__git_hub_box2d_docs_dynamics.html#autotoc_md56
    chipBodyDef.type = b2_dynamicBody; //Dynamic bodies move when colliding with static objects
    chipBodyDef.position.Set(0,20); //Starting position of the body
    chipBodyDef.angle = 0; //Starting angle of the body
    chipBodyDef.allowSleep = true; //When bodies are at rest they are put into a sleep state to improve performance

    //body factory
    b2Body *worldChipBody = world->CreateBody(&chipBodyDef);

    //Chip Shape & Fixture
    b2FixtureDef chipFixtureDef;
    b2CircleShape chipShape;
    chipShape.m_radius = 5.0f; //Set radius
    chipFixtureDef.shape = &chipShape;
    chipFixtureDef.density = 1.0f;
    b2Fixture *chipFixture = worldChipBody->CreateFixture(&chipFixtureDef);
    chipFixture->SetDensity(5.0f);
    //worldChipBody->DestroyFixture(chipFixture); //Can destroy to model a breakable object if wished

    chipFixture->SetRestitution(1.0f); //Restitution is used to make objects bounce
}

void ChipPhysics::placeChipsOnMap(QPixmap* map)
{
    QPainter painter(map);
    painter.setBrush(QColorConstants::Black);

    for(b2Body* currentChip = world->GetBodyList(); currentChip != nullptr; currentChip->GetNext())//foreach body convery body info to something that can be drawn on a label
    {
        QPointF centerPoint(currentChip->GetWorldCenter().x, currentChip->GetWorldCenter().y);
        painter.drawEllipse(centerPoint,
                            currentChip->GetFixtureList()->GetShape()->m_radius, currentChip->GetFixtureList()->GetShape()->m_radius);
        //notify the view to update the lable with the new elipse on the pixmap
    }
}

void ChipPhysics::createChips(int betAmt)//bet amt will determine number/color of chips
{
    b2BodyDef chipBodyDef;
    chipBodyDef.type = b2_dynamicBody; //Dynamic bodies move when colliding with static objects
    chipBodyDef.position.Set(0,20); //Starting position of the body
    chipBodyDef.angle = 0; //Starting angle of the body
    chipBodyDef.allowSleep = true; //When bodies are at rest they are put into a sleep state to improve performance

    b2Body *worldChipBody = world->CreateBody(&chipBodyDef);

    b2FixtureDef chipFixtureDef;
    b2CircleShape chipShape;
    chipShape.m_radius = 5.0f; //Set radius
    chipFixtureDef.shape = &chipShape;
    chipFixtureDef.density = 1.0f;
    b2Fixture *chipFixture = worldChipBody->CreateFixture(&chipFixtureDef);
    chipFixture->SetDensity(5.0f);
}

