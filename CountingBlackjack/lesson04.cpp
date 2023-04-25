#include "lesson.h"

#include <QMessageBox>

Lesson4::Lesson4(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson4::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the dealer hands in 1 hand rounds.
    Card cards[]{Card(0,9), Card(1,9), Card(0,13), Card(2,4), Card(0,12), Card(1,1), Card(3,4), Card(3,5), Card(3,6), Card(0,11)};
    //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(200, cards, 10);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->splitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson4::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //On opening the lesson...

        emit displayTextPopup("Advanced Rules: Splitting"
                              ,"In this lesson, you'll learn about a more advanced rule, splitting!\n"
                               "Splitting is an additional option that lets you get more out of your bets."
                               "Let's see it in action!  (Deal a hand)"
                              ,"Let's do it!");
    }

    if (currentStep == 1)
    {
        //Player gets two 9s, dealer gets 17...

        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);

        emit displayTextPopup("Basic Rules: Splitting"
                              ,"Since you got two cards of the same value, you can split them into 2 different hands, each one getting a new card!\n"
                               "When splitting, you have to add your origional bet to your second hand as well, so look at your chip count when splitting.\n"
                               "(Any card with a value of 10 can be split, so you could split a 10 and Jack if needed, for example.)"
                              ,"Sweet!");
    }

    if (currentStep == 2)
    {
        //Player split...

        emit displayTextPopup("Basic Rules: Splitting"
                              ,"Now you're playing with two hands, when you finish this one's turn you can see the next one's.\n"
                               "Each hand plays individually with the opponent, try it out."
                              ,"Yay!");
    }

    if(currentStep ==4)
    {
        //Player has stood the second hand...

        emit displayTextPopup("Basic Rules: Splitting"
                              ,"Each hand has it's own payout, so if you win one, lose another, it becomes net 0.\n"
                               "If you want to try that again, just replay this lesson.\n"
                               "Remember that, when you're ready, to view the next lesson at Lessons > Section 2 > Lesson 5"
                              ,"Yay!");

        completeLesson();
    }

    //Move to the next step
    currentStep++;
}

void Lesson4::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->splitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
