#ifndef LESSON_H
#define LESSON_H

#include <QObject>
#include "controller.h"

/**
 * @brief The Lesson abstract class. From this class will all of the lesson subclasses with their functionality be derived.
 */
class Lesson : public QObject
{
    Q_OBJECT

public:
    /**
     * @brief COMMENT HERE JAMAL
     */
    virtual void initLesson() = 0;

    /**
     * @brief COMMENT HERE JAMAL
     */
    virtual void stepLesson() = 0;

    /**
     * @brief Completes the lesson, and does what it needs to to reset, like emiting lessonFinished.
     */
    virtual void completeLesson();

signals:
    void lessonFinished();
    void displayTextPopup(QString title, QString message, QString buttonMessage);

protected:
    Lesson(Controller &controller, FieldModel &fieldModel, DeckModel &deckModel);

    //Holds the current step of the lesson plan.  This should be increased whenever a player hits, stands, deals, etc.
    //When creating lessons, make sure to enable/disable options to be able to lead the player as you want.
    int currentStep;

    Controller &controller;
    FieldModel &fieldModel;
    DeckModel &deckModel;
};

#endif // LESSON_H
