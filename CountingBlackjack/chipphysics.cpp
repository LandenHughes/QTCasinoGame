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
    world = new b2World(b2Vec2(0.0f, 9.8f));
    setupBoundries();
}


void ChipPhysics::createChips(int betAmt, int offset)//bet amt will determine number/color of chips
{
    int yOffset = offset;
    int xOffset = offset;

    for(int i = 0; i < betAmt/5; i++)//one chip for every $5 bet
    {
        b2BodyDef chipBodyDef;
        chipBodyDef.type = b2_dynamicBody; //Dynamic bodies move when colliding with static objects

        //Done so chips don't run off the screen at bets >20
        if(i%5 == 0 && i != 0)
        {
            xOffset = 0; //Resets chips spawning to the left side of box
            yOffset = 1; //Makes chips spawn higher to avoid clipping with other chips
        }

        chipBodyDef.position.Set((10.0f + xOffset * 25), (yOffset * 25)); //Starting position of the body (i*25 is an offset for creating multiple chips to avoid overlap)
        chipBodyDef.angle = 0.0f; //Starting angle of the body
        chipBodyDef.allowSleep = true; //When bodies are at rest they are put into a sleep state to improve performance
        b2Body *worldChipBody = world->CreateBody(&chipBodyDef);

        b2FixtureDef chipFixtureDef;
        b2CircleShape chipShape;
        chipShape.m_radius = 10.0f; //Set radius
        chipFixtureDef.shape = &chipShape;
        chipFixtureDef.density = 0.009f; //Chips are 9g in real life
        chipFixtureDef.restitution = 0.0f; //Makes the chip bounce
        worldChipBody->CreateFixture(&chipFixtureDef);
        b2Fixture *chipFixture = worldChipBody->CreateFixture(&chipFixtureDef);
        chipFixture->SetDensity(0.009f);

        yOffset++;
        xOffset++;
        qDebug() << "body mass" << worldChipBody->GetMass();
    }
}

void ChipPhysics::updateAnimation()
{
    world->Step(100.0f, 6.0f, 2.0f);
}

b2Body* ChipPhysics::getWorldChip()
{
    return world->GetBodyList();
}

void ChipPhysics::clearWorld()
{
    for(b2Body* currentChip = world->GetBodyList(); currentChip != nullptr; currentChip = currentChip->GetNext())
    {
        world->DestroyBody(currentChip);
    }
    setupBoundries();
}

void ChipPhysics::setupBoundries()
{
    //Body setup for boundary
    float labelWidth = 90; //101; //Box2D 1 pixel = 1 meter
    float labelHeight = 205; //211;
    //setup boundaries, each call to createFixture adds a new edge, edges cover the outside of the label
    b2BodyDef boundaryDef;
    boundaryDef.type = b2_staticBody;
    b2Body *boundaryBody = world->CreateBody(&boundaryDef);

    b2EdgeShape boundaryEdge;
    boundaryEdge.Set(b2Vec2(0, 0), b2Vec2(0, labelHeight));//top left -> bottom left
    boundaryBody->CreateFixture(&boundaryEdge, 0);

    boundaryEdge.Set(b2Vec2(0, labelHeight), b2Vec2(labelWidth, labelHeight));//bottom left -> bottom right
    boundaryBody->CreateFixture(&boundaryEdge, 0);

    boundaryEdge.Set(b2Vec2(labelWidth, labelHeight), b2Vec2(labelWidth, 0));//bottom left -> top right
    boundaryBody->CreateFixture(&boundaryEdge, 0);

    boundaryEdge.Set(b2Vec2(0, 0), b2Vec2(labelWidth, 0));//top left -> top right
    boundaryBody->CreateFixture(&boundaryEdge, 0);
}

void ChipPhysics::addWinningChips(bool isBlackjackWin)
{
    //NOTE: 0 counts as even in c++
    int evenCounter = 1; //even counter is so we can to 2.5x for the blackjack win (every other chip is also added to get 0.5 more)

    //Skip the Boundary body
    b2Body* chipList = world->GetBodyList();
    chipList = chipList->GetNext();

    int offset = 0;
    for(b2Body* currentChip = chipList; currentChip != nullptr; currentChip = currentChip->GetNext())//foreach body convery body info to something that can be drawn on a label
    {
        createChips(5, offset); //Makes one chip

        if(isBlackjackWin && evenCounter%2==0)
        {
            createChips(5, offset);
        }

        evenCounter++;
        offset++;
    }
}
