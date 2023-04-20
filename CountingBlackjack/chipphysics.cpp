/**
 * @class ChipPhysics
 * @file chipphysics.cpp
 * @brief Set parameters and initialize values of the chip body and other factors
 * to create chips that fall and bounce.
 */
#include "chipphysics.h"

ChipPhysics::ChipPhysics(QObject *parent)
    : QObject(parent)
{
    setupBodies();
}

ChipPhysics::~ChipPhysics()
{
    delete world;
}

void ChipPhysics::setupBodies()
{
    //World setup
    world = new b2World(b2Vec2(0.0f, 0.1f));

    //Body setup for ground
    float labelWidth = 101 * 2;//30 pixels per meter
    float labelHeight = 211 * 2;//30 pixels per meter

    b2Vec2 vertices[4];
    vertices[0].Set(0 , 0 );
    vertices[1].Set(0 , labelHeight);//101 is the label width 211 is height
    vertices[2].Set(labelWidth , labelHeight );
    vertices[3].Set(labelWidth , 0 );
    b2ChainShape boundry;
    boundry.CreateLoop(vertices, 4);

    // body for the bounding body
    b2BodyDef boundryBodyDef;
    boundryBodyDef.type = b2_staticBody;
    boundryBodyDef.position.Set(0, 0);
    b2Body* body = world->CreateBody(&boundryBodyDef);

    // fixture for bounding body
    b2FixtureDef boundryFixtureDef;
    boundryFixtureDef.shape = &boundry;
    boundryFixtureDef.density = 1.0f;
    boundryFixtureDef.friction = 0.3f;
    body->CreateFixture(&boundryFixtureDef);


    float xDisplacement = (labelWidth - body->GetPosition().x) / 2.0f;
    float yDisplacement = (labelHeight - body->GetPosition().y) / 2.0f;
    body->SetTransform(body->GetPosition() + b2Vec2(xDisplacement, yDisplacement), body->GetAngle());

}


void ChipPhysics::createChips(int betAmt)//bet amt will determine number/color of chips
{
    for(int i = 0; i < betAmt/5; i++)//one chip for every $5 bet
    {
        b2BodyDef chipBodyDef;
        chipBodyDef.type = b2_dynamicBody; //Dynamic bodies move when colliding with static objects
        chipBodyDef.position.Set(10.0f + i * 25, 0.0f); //Starting position of the body (i*25 is an offset for creating multiple chips to avoid overlap)
        chipBodyDef.angle = 0.0f; //Starting angle of the body
        chipBodyDef.allowSleep = true; //When bodies are at rest they are put into a sleep state to improve performance

        b2Body *worldChipBody = world->CreateBody(&chipBodyDef);

        b2FixtureDef chipFixtureDef;
        b2CircleShape chipShape;
        chipShape.m_radius = 5.0f; //Set radius
        chipFixtureDef.shape = &chipShape;
        chipFixtureDef.density = 1.0f;
        chipFixtureDef.restitution = 1.0f; //Makes the chip bounce
        worldChipBody->CreateFixture(&chipFixtureDef);
        b2Fixture *chipFixture = worldChipBody->CreateFixture(&chipFixtureDef);
        chipFixture->SetDensity(5.0f);
    }
}

void ChipPhysics::updateAnimation()
{
    world->Step(100.0f, 6, 2);
}

b2Body* ChipPhysics::getWorldChip()
{
    return world->GetBodyList();
}

