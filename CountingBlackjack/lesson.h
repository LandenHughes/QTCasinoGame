#ifndef LESSON_H
#define LESSON_H

#include <QObject>
#include "controller.h"
#include "deckmodel.h"
#include "fieldmodel.h"

/**
 * @brief The Lesson abstract class. From this class will all of the lesson subclasses with their functionality be derived.
 */
class Lesson : public QObject
{
    Q_OBJECT

public:
    virtual void initLesson() = 0;
    virtual void stepLesson() = 0;

signals:
    void lessonFinished();
    void displayTextPopup(QString title, QString message, QString buttonMessage);

protected:
    Lesson(Controller &controller, FieldModel &fieldModel, DeckModel &deckModel);

    Controller &controller;
    FieldModel &fieldModel;
    DeckModel &deckModel;
};

#endif // LESSON_H
