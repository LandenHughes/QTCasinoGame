QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Box2D/Collision/Shapes/b2ChainShape.cpp \
    Box2D/Collision/Shapes/b2CircleShape.cpp \
    Box2D/Collision/Shapes/b2EdgeShape.cpp \
    Box2D/Collision/Shapes/b2PolygonShape.cpp \
    Box2D/Collision/b2BroadPhase.cpp \
    Box2D/Collision/b2CollideCircle.cpp \
    Box2D/Collision/b2CollideEdge.cpp \
    Box2D/Collision/b2CollidePolygon.cpp \
    Box2D/Collision/b2Collision.cpp \
    Box2D/Collision/b2Distance.cpp \
    Box2D/Collision/b2DynamicTree.cpp \
    Box2D/Collision/b2TimeOfImpact.cpp \
    Box2D/Common/b2BlockAllocator.cpp \
    Box2D/Common/b2Draw.cpp \
    Box2D/Common/b2Math.cpp \
    Box2D/Common/b2Settings.cpp \
    Box2D/Common/b2StackAllocator.cpp \
    Box2D/Common/b2Timer.cpp \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2CircleContact.cpp \
    Box2D/Dynamics/Contacts/b2Contact.cpp \
    Box2D/Dynamics/Contacts/b2ContactSolver.cpp \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp \
    Box2D/Dynamics/Contacts/b2PolygonContact.cpp \
    Box2D/Dynamics/Joints/b2DistanceJoint.cpp \
    Box2D/Dynamics/Joints/b2FrictionJoint.cpp \
    Box2D/Dynamics/Joints/b2GearJoint.cpp \
    Box2D/Dynamics/Joints/b2Joint.cpp \
    Box2D/Dynamics/Joints/b2MotorJoint.cpp \
    Box2D/Dynamics/Joints/b2MouseJoint.cpp \
    Box2D/Dynamics/Joints/b2PrismaticJoint.cpp \
    Box2D/Dynamics/Joints/b2PulleyJoint.cpp \
    Box2D/Dynamics/Joints/b2RevoluteJoint.cpp \
    Box2D/Dynamics/Joints/b2RopeJoint.cpp \
    Box2D/Dynamics/Joints/b2WeldJoint.cpp \
    Box2D/Dynamics/Joints/b2WheelJoint.cpp \
    Box2D/Dynamics/b2Body.cpp \
    Box2D/Dynamics/b2ContactManager.cpp \
    Box2D/Dynamics/b2Fixture.cpp \
    Box2D/Dynamics/b2Island.cpp \
    Box2D/Dynamics/b2World.cpp \
    Box2D/Dynamics/b2WorldCallbacks.cpp \
    Box2D/Rope/b2Rope.cpp \
    card.cpp \
    chipphysics.cpp \
    controller.cpp \
    counttracker.cpp \
    deckmodel.cpp \
    fieldmodel.cpp \
    hand.cpp \
    lesson1.cpp \
    lesson12.cpp \
    lesson7.cpp \
    lesson13.cpp \
    lesson14.cpp \
    lesson15.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Box2D/Box2D.h \
    Box2D/Collision/Shapes/b2ChainShape.h \
    Box2D/Collision/Shapes/b2CircleShape.h \
    Box2D/Collision/Shapes/b2EdgeShape.h \
    Box2D/Collision/Shapes/b2PolygonShape.h \
    Box2D/Collision/Shapes/b2Shape.h \
    Box2D/Collision/b2BroadPhase.h \
    Box2D/Collision/b2Collision.h \
    Box2D/Collision/b2Distance.h \
    Box2D/Collision/b2DynamicTree.h \
    Box2D/Collision/b2TimeOfImpact.h \
    Box2D/Common/b2BlockAllocator.h \
    Box2D/Common/b2Draw.h \
    Box2D/Common/b2GrowableStack.h \
    Box2D/Common/b2Math.h \
    Box2D/Common/b2Settings.h \
    Box2D/Common/b2StackAllocator.h \
    Box2D/Common/b2Timer.h \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2CircleContact.h \
    Box2D/Dynamics/Contacts/b2Contact.h \
    Box2D/Dynamics/Contacts/b2ContactSolver.h \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2PolygonContact.h \
    Box2D/Dynamics/Joints/b2DistanceJoint.h \
    Box2D/Dynamics/Joints/b2FrictionJoint.h \
    Box2D/Dynamics/Joints/b2GearJoint.h \
    Box2D/Dynamics/Joints/b2Joint.h \
    Box2D/Dynamics/Joints/b2MotorJoint.h \
    Box2D/Dynamics/Joints/b2MouseJoint.h \
    Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    Box2D/Dynamics/Joints/b2PulleyJoint.h \
    Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    Box2D/Dynamics/Joints/b2RopeJoint.h \
    Box2D/Dynamics/Joints/b2WeldJoint.h \
    Box2D/Dynamics/Joints/b2WheelJoint.h \
    Box2D/Dynamics/b2Body.h \
    Box2D/Dynamics/b2ContactManager.h \
    Box2D/Dynamics/b2Fixture.h \
    Box2D/Dynamics/b2Island.h \
    Box2D/Dynamics/b2TimeStep.h \
    Box2D/Dynamics/b2World.h \
    Box2D/Dynamics/b2WorldCallbacks.h \
    Box2D/Rope/b2Rope.h \
    card.h \
    chipphysics.h \
    controller.h \
    counttracker.h \
    deckmodel.h \
    fieldmodel.h \
    hand.h \
    lesson.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Box2D/Box2DConfig.cmake \
    Box2D/CMakeLists.txt \
    Box2D/Collision/Icon_ \
    Box2D/Collision/Shapes/Icon_ \
    Box2D/Common/Icon_ \
    Box2D/Dynamics/Contacts/Icon_ \
    Box2D/Dynamics/Icon_ \
    Box2D/Dynamics/Joints/Icon_ \
    Box2D/Icon_ \
    Box2D/Rope/Icon_ \
    Playing Cards/10_of_clubs.png \
    Playing Cards/10_of_clubs.png \
    Playing Cards/10_of_diamonds.png \
    Playing Cards/10_of_diamonds.png \
    Playing Cards/10_of_hearts.png \
    Playing Cards/10_of_hearts.png \
    Playing Cards/10_of_spades.png \
    Playing Cards/10_of_spades.png \
    Playing Cards/2_of_clubs.png \
    Playing Cards/2_of_clubs.png \
    Playing Cards/2_of_diamonds.png \
    Playing Cards/2_of_diamonds.png \
    Playing Cards/2_of_hearts.png \
    Playing Cards/2_of_hearts.png \
    Playing Cards/2_of_spades.png \
    Playing Cards/2_of_spades.png \
    Playing Cards/3_of_clubs.png \
    Playing Cards/3_of_clubs.png \
    Playing Cards/3_of_diamonds.png \
    Playing Cards/3_of_diamonds.png \
    Playing Cards/3_of_hearts.png \
    Playing Cards/3_of_hearts.png \
    Playing Cards/3_of_spades.png \
    Playing Cards/3_of_spades.png \
    Playing Cards/4_of_clubs.png \
    Playing Cards/4_of_clubs.png \
    Playing Cards/4_of_diamonds.png \
    Playing Cards/4_of_diamonds.png \
    Playing Cards/4_of_hearts.png \
    Playing Cards/4_of_hearts.png \
    Playing Cards/4_of_spades.png \
    Playing Cards/4_of_spades.png \
    Playing Cards/5_of_clubs.png \
    Playing Cards/5_of_clubs.png \
    Playing Cards/5_of_diamonds.png \
    Playing Cards/5_of_diamonds.png \
    Playing Cards/5_of_hearts.png \
    Playing Cards/5_of_hearts.png \
    Playing Cards/5_of_spades.png \
    Playing Cards/5_of_spades.png \
    Playing Cards/6_of_clubs.png \
    Playing Cards/6_of_clubs.png \
    Playing Cards/6_of_diamonds.png \
    Playing Cards/6_of_diamonds.png \
    Playing Cards/6_of_hearts.png \
    Playing Cards/6_of_hearts.png \
    Playing Cards/6_of_spades.png \
    Playing Cards/6_of_spades.png \
    Playing Cards/7_of_clubs.png \
    Playing Cards/7_of_clubs.png \
    Playing Cards/7_of_diamonds.png \
    Playing Cards/7_of_diamonds.png \
    Playing Cards/7_of_hearts.png \
    Playing Cards/7_of_hearts.png \
    Playing Cards/7_of_spades.png \
    Playing Cards/7_of_spades.png \
    Playing Cards/8_of_clubs.png \
    Playing Cards/8_of_clubs.png \
    Playing Cards/8_of_diamonds.png \
    Playing Cards/8_of_diamonds.png \
    Playing Cards/8_of_hearts.png \
    Playing Cards/8_of_hearts.png \
    Playing Cards/8_of_spades.png \
    Playing Cards/8_of_spades.png \
    Playing Cards/9_of_clubs.png \
    Playing Cards/9_of_clubs.png \
    Playing Cards/9_of_diamonds.png \
    Playing Cards/9_of_diamonds.png \
    Playing Cards/9_of_hearts.png \
    Playing Cards/9_of_hearts.png \
    Playing Cards/9_of_spades.png \
    Playing Cards/9_of_spades.png \
    Playing Cards/ace_of_clubs.png \
    Playing Cards/ace_of_clubs.png \
    Playing Cards/ace_of_diamonds.png \
    Playing Cards/ace_of_diamonds.png \
    Playing Cards/ace_of_hearts.png \
    Playing Cards/ace_of_hearts.png \
    Playing Cards/ace_of_spades.png \
    Playing Cards/ace_of_spades.png \
    Playing Cards/ace_of_spades2.png \
    Playing Cards/ace_of_spades2.png \
    Playing Cards/black_joker.png \
    Playing Cards/black_joker.png \
    Playing Cards/jack_of_clubs.png \
    Playing Cards/jack_of_clubs.png \
    Playing Cards/jack_of_clubs2.png \
    Playing Cards/jack_of_clubs2.png \
    Playing Cards/jack_of_diamonds.png \
    Playing Cards/jack_of_diamonds.png \
    Playing Cards/jack_of_diamonds2.png \
    Playing Cards/jack_of_diamonds2.png \
    Playing Cards/jack_of_hearts.png \
    Playing Cards/jack_of_hearts.png \
    Playing Cards/jack_of_hearts2.png \
    Playing Cards/jack_of_hearts2.png \
    Playing Cards/jack_of_spades.png \
    Playing Cards/jack_of_spades.png \
    Playing Cards/jack_of_spades2.png \
    Playing Cards/jack_of_spades2.png \
    Playing Cards/king_of_clubs.png \
    Playing Cards/king_of_clubs.png \
    Playing Cards/king_of_clubs2.png \
    Playing Cards/king_of_clubs2.png \
    Playing Cards/king_of_diamonds.png \
    Playing Cards/king_of_diamonds.png \
    Playing Cards/king_of_diamonds2.png \
    Playing Cards/king_of_diamonds2.png \
    Playing Cards/king_of_hearts.png \
    Playing Cards/king_of_hearts.png \
    Playing Cards/king_of_hearts2.png \
    Playing Cards/king_of_hearts2.png \
    Playing Cards/king_of_spades.png \
    Playing Cards/king_of_spades.png \
    Playing Cards/king_of_spades2.png \
    Playing Cards/king_of_spades2.png \
    Playing Cards/queen_of_clubs.png \
    Playing Cards/queen_of_clubs.png \
    Playing Cards/queen_of_clubs2.png \
    Playing Cards/queen_of_clubs2.png \
    Playing Cards/queen_of_diamonds.png \
    Playing Cards/queen_of_diamonds.png \
    Playing Cards/queen_of_diamonds2.png \
    Playing Cards/queen_of_diamonds2.png \
    Playing Cards/queen_of_hearts.png \
    Playing Cards/queen_of_hearts.png \
    Playing Cards/queen_of_hearts2.png \
    Playing Cards/queen_of_hearts2.png \
    Playing Cards/queen_of_spades.png \
    Playing Cards/queen_of_spades.png \
    Playing Cards/queen_of_spades2.png \
    Playing Cards/queen_of_spades2.png \
    Playing Cards/red_joker.png \
    Playing Cards/red_joker.png \
    Playing_Cards/10_of_clubs.png \
    Playing_Cards/10_of_diamonds.png \
    Playing_Cards/10_of_hearts.png \
    Playing_Cards/10_of_spades.png \
    Playing_Cards/2_of_clubs.png \
    Playing_Cards/2_of_diamonds.png \
    Playing_Cards/2_of_hearts.png \
    Playing_Cards/2_of_spades.png \
    Playing_Cards/3_of_clubs.png \
    Playing_Cards/3_of_diamonds.png \
    Playing_Cards/3_of_hearts.png \
    Playing_Cards/3_of_spades.png \
    Playing_Cards/4_of_clubs.png \
    Playing_Cards/4_of_diamonds.png \
    Playing_Cards/4_of_hearts.png \
    Playing_Cards/4_of_spades.png \
    Playing_Cards/5_of_clubs.png \
    Playing_Cards/5_of_diamonds.png \
    Playing_Cards/5_of_hearts.png \
    Playing_Cards/5_of_spades.png \
    Playing_Cards/6_of_clubs.png \
    Playing_Cards/6_of_diamonds.png \
    Playing_Cards/6_of_hearts.png \
    Playing_Cards/6_of_spades.png \
    Playing_Cards/7_of_clubs.png \
    Playing_Cards/7_of_diamonds.png \
    Playing_Cards/7_of_hearts.png \
    Playing_Cards/7_of_spades.png \
    Playing_Cards/8_of_clubs.png \
    Playing_Cards/8_of_diamonds.png \
    Playing_Cards/8_of_hearts.png \
    Playing_Cards/8_of_spades.png \
    Playing_Cards/9_of_clubs.png \
    Playing_Cards/9_of_diamonds.png \
    Playing_Cards/9_of_hearts.png \
    Playing_Cards/9_of_spades.png \
    Playing_Cards/ace_of_clubs.png \
    Playing_Cards/ace_of_diamonds.png \
    Playing_Cards/ace_of_hearts.png \
    Playing_Cards/ace_of_spades.png \
    Playing_Cards/ace_of_spades2.png \
    Playing_Cards/back.png \
    Playing_Cards/black_joker.png \
    Playing_Cards/jack_of_clubs.png \
    Playing_Cards/jack_of_clubs2.png \
    Playing_Cards/jack_of_diamonds.png \
    Playing_Cards/jack_of_diamonds2.png \
    Playing_Cards/jack_of_hearts.png \
    Playing_Cards/jack_of_hearts2.png \
    Playing_Cards/jack_of_spades.png \
    Playing_Cards/jack_of_spades2.png \
    Playing_Cards/king_of_clubs.png \
    Playing_Cards/king_of_clubs2.png \
    Playing_Cards/king_of_diamonds.png \
    Playing_Cards/king_of_diamonds2.png \
    Playing_Cards/king_of_hearts.png \
    Playing_Cards/king_of_hearts2.png \
    Playing_Cards/king_of_spades.png \
    Playing_Cards/king_of_spades2.png \
    Playing_Cards/queen_of_clubs.png \
    Playing_Cards/queen_of_clubs2.png \
    Playing_Cards/queen_of_diamonds.png \
    Playing_Cards/queen_of_diamonds2.png \
    Playing_Cards/queen_of_hearts.png \
    Playing_Cards/queen_of_hearts2.png \
    Playing_Cards/queen_of_spades.png \
    Playing_Cards/queen_of_spades2.png \
    Playing_Cards/red_joker.png

RESOURCES += \
    Resources.qrc
