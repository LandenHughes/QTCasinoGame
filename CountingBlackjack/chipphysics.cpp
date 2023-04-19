/**
 * @class ChipPhysics
 * @file chipphysics.cpp
 * @brief Set parameters and initialize values of the chip body and other factors
 * to create chips that fall and bounce.
 */
#include "chipphysics.h"

//ChipPhysics::ChipPhysics(Controller &control, QObject *parent)
//    : QObject(parent)
//    , controller(control)
ChipPhysics::ChipPhysics(QObject *parent)
    : QObject(parent)
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
//    animationDone = false;
//    //TODO: values are just placeholders for now!!! fix later

//    b2BodyDef chipBodyDef; //Body of the chip(s)

//    b2AABB worldAABB;
//    worldAABB.lowerBound.Set(-200, -100);
//    worldAABB.upperBound.Set(200, 500);
//    //World setup
//    world = new b2World(b2Vec2(0.0f, -9.8)); //-9.8m/s^2 is Earth's gravity

//    //this is what the chips will bounce off of after falling commented out right now for testing
////    b2BodyDef groundBodyDef;
////    groundBodyDef.position.Set(0.0f, -10.0f);
////    b2Body* groundBody = world->CreateBody(&groundBodyDef);
////    b2PolygonShape groundBox;
////    groundBox.SetAsBox(50.0f, 10.0f);//these are just example values these will be received by the label bounds
////    groundBody->CreateFixture(&groundBox, 0.0f);


//    //Body setup - https://box2d.org/documentation/md__d_1__git_hub_box2d_docs_dynamics.html#autotoc_md56
//    chipBodyDef.type = b2_dynamicBody; //Dynamic bodies move when colliding with static objects
//    chipBodyDef.position.Set(50,20); //Starting position of the body
//    chipBodyDef.angle = 0; //Starting angle of the body
//    chipBodyDef.allowSleep = true; //When bodies are at rest they are put into a sleep state to improve performance
//    //this should be false not true

//    //body factory
//    b2Body *worldChipBody = world->CreateBody(&chipBodyDef);

//    //Chip Shape & Fixture
//    b2FixtureDef chipFixtureDef;
//    b2CircleShape chipShape;
//    chipShape.m_radius = 10.0f; //Set radius
//    chipFixtureDef.shape = &chipShape;
//    chipFixtureDef.density = 1.0f;
//    b2Fixture *chipFixture = worldChipBody->CreateFixture(&chipFixtureDef);
//    chipFixture->SetDensity(5.0f);
//    //worldChipBody->ApplyForceToCenter(b2Vec2(0, -9.81f), true);//apply gravity force to the body
//    //worldChipBody->DestroyFixture(chipFixture); //Can destroy to model a breakable object if wished

//    chipFixture->SetRestitution(1.0f); //Restitution is used to make objects bounce

    //Alternate Version Based on - https://libgdx.com/wiki/extensions/physics/box2d#objectsbodies
    animationDone = false;

    //World setup
    world = new b2World(b2Vec2(0.0f, -9.8f));

    //Body setup for chip and ground

    //Body setup for chip (dynamic object)
    b2BodyDef *chipBodyDef = new b2BodyDef(); //Creates a body definition
    chipBodyDef->type = b2_dynamicBody; //Dynamic so it can interact. Something like the ground would be static instead
    chipBodyDef->position.Set(50.0f, 50.0f); //Body's starting position in the world

    //Create the chipBody in the world by using a body definition
    b2Body *chipBody = world->CreateBody(chipBodyDef);

    b2CircleShape *chipCircle = new b2CircleShape();
    chipCircle->m_radius = 1.0f;

    //Create fixture definition to apply our shape to
    b2FixtureDef *fixtureDef = new b2FixtureDef();
    fixtureDef->shape = chipCircle;
    fixtureDef->density = 0.5f;
    fixtureDef->friction = 0.4f;
    fixtureDef->restitution = 0.6f; //Make it bounce a bit

    //Create a fixture and attach it to the body
    b2Fixture *fixture = chipBody->CreateFixture(fixtureDef);
    //chipCircle.dispose(); does not exist so can't remove like this for cleanup

    //Body setup for the ground (Static object)
    b2BodyDef *groundBodyDef = new b2BodyDef();
    groundBodyDef->type = b2_staticBody;
    b2Body *groundBody = world->CreateBody(groundBodyDef);
    b2PolygonShape *groundBox = new b2PolygonShape();

    groundBox->SetAsBox(-0.0f, 10.0f);
    groundBody->CreateFixture(groundBox, 0.0f);
    //groundBox.dispose() DOES NOT EXIST so may not be able to remove?
}

void ChipPhysics::placeChipsOnMap(QPixmap* map)
{

    QPainter painter(map);
    painter.setBrush(QColorConstants::Black);

    for(b2Body* currentChip = world->GetBodyList(); currentChip != nullptr; currentChip = currentChip->GetNext())//foreach body convery body info to something that can be drawn on a label
    {
        if(currentChip->GetType() == b2_dynamicBody && currentChip->GetFixtureList()->GetShape()->GetType() == b2Shape::e_circle)
        {
        QPointF centerPoint(currentChip->GetWorldCenter().x, currentChip->GetWorldCenter().y);
        painter.drawEllipse(centerPoint /2,
                            currentChip->GetFixtureList()->GetShape()->m_radius, currentChip->GetFixtureList()->GetShape()->m_radius);
        qDebug() << "Chip Coordinates x then y:" << centerPoint.x()<< " "<< centerPoint.y();

        if(centerPoint.y() < -100){//this will be different from 100 but this is a stop condition to get the animation loop to stop (should stop when bodies stop moving)
            animationDone = true;
            currentChip->SetLinearVelocity(b2Vec2(0.0f, 0));//no more movement
        }//end if
        }
    }
    world->Step(1/60.0f, 6, 2);//updates the state of the world
}

void ChipPhysics::createChips(int betAmt)//bet amt will determine number/color of chips
{
    b2BodyDef chipBodyDef;
    chipBodyDef.type = b2_dynamicBody; //Dynamic bodies move when colliding with static objects
    chipBodyDef.position.Set(50.0f, 20.0f); //Starting position of the body
    chipBodyDef.angle = 0.0f; //Starting angle of the body
    chipBodyDef.allowSleep = true; //When bodies are at rest they are put into a sleep state to improve performance

    b2Body *worldChipBody = world->CreateBody(&chipBodyDef);

    b2FixtureDef chipFixtureDef;
    b2CircleShape chipShape;
    chipShape.m_radius = 5.0f; //Set radius
    chipFixtureDef.shape = &chipShape;
    chipFixtureDef.density = 1.0f;
    worldChipBody->CreateFixture(&chipFixtureDef);
    b2Fixture *chipFixture = worldChipBody->CreateFixture(&chipFixtureDef);
    chipFixture->SetDensity(5.0f);
}

