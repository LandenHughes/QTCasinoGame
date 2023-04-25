#ifndef LESSON_H
#define LESSON_H

#include <QObject>
#include "controller.h"
#include "ui_mainwindow.h"

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
    virtual void completeLesson() = 0;

signals:
    void lessonFinished();
    void displayTextPopup(QString title, QString message, QString buttonMessage);

protected:
    Lesson(Ui::MainWindow *ui, Controller &controller) : ui(ui), controller(controller) {}

    //Holds the current step of the lesson plan.  This should be increased whenever a player hits, stands, deals, etc.
    //When creating lessons, make sure to enable/disable options to be able to lead the player as you want.
    int currentStep;

    Ui::MainWindow *ui;
    Controller &controller;
};

class Lesson1 : public Lesson {
public:
    Lesson1(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson2 : public Lesson {
public:
    Lesson1(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson3 : public Lesson {
public:
    Lesson1(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson4 : public Lesson {
public:
    Lesson1(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson5 : public Lesson {
public:
    Lesson1(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson6 : public Lesson {
public:
    Lesson1(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson7 : public Lesson {
public:
    Lesson7(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson8 : public Lesson {
public:
    Lesson8(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson9 : public Lesson {
public:
    Lesson8(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson10 : public Lesson {
public:
    Lesson8(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson11 : public Lesson {
public:
    Lesson8(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson12: public Lesson{
public:
    Lesson12(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson13: public Lesson{
public:
    Lesson13(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson14: public Lesson{
public:
    Lesson14(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};

class Lesson15: public Lesson{
public:
    Lesson15(Ui::MainWindow *ui, Controller &controller);
    void initLesson();
    void stepLesson();
    void completeLesson();
};


#endif // LESSON_H
