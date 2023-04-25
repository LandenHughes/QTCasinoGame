#include "lesson.h"

#include <QMessageBox>

Lesson6::Lesson6(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson6::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the dealer hands in 1 hand rounds.
    Card cards[]{Card(0,7), Card(1,11), Card(3,12), Card(1,1), Card(2,9), Card(3,9)};
    //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(200, cards, 6);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->acceptInsurancePushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson6::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //On opening the lesson...

        emit displayTextPopup("Advanced Rules: Insurance"
                              ,"When the dealer has an ace face-up, they can offer insurance.\n"
                               "Insurance is a special rule that lets you mitigate the damage if they have a Blackjack.\n"
                               "Deal a hand to try it out!"
                              ,"Let's do it!");
    }

    if (currentStep == 1)
    {
        //Player gets 17, dealer gets Blackjack...

        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);
        emit controller.setDenyInsuranceButtonEnabled(false);

        emit displayTextPopup("Advanced Rules: Insurance"
                              ,"Since the dealer has a face-up ace card, you can pay insurance here!\n"
                               "To get insurance, make an insurance bet that's worth half of your hand's bet.\n"
                               "If the dealer doesn't have a Blackjack, you simply lose the insurance bet, but you can still win the hand!\n"
                               "Try getting some insurance!"
                              ,"Better safe than sorry!");
    }

    if (currentStep == 2)
    {
        //Player gets insurance...

        emit displayTextPopup("Advanced Rules: Insurance"
                              ,"You bought the insurance, and the dealer revealed... Blackjack!\n"
                               "If they have a Blackjack, the insurance bet pays out 2:1.\n"
                               "This is a fancy way of saying you don't win or loseany chips if you insured against a Blackjack.\n"
                               "Stand to end this round."
                              ,"Gotcha");
    }

    if (currentStep == 3)
    {
        //Player stands...

        emit displayTextPopup("Advanced Rules: Insurance"
                              ,"This is the end of the advanced rules section.\n"
                               "Hopefully, you learned some options you can use to give you an edge while playing!\n"
                               "In later lessons, we go over when the best time to use these extra rules is."
                               "To move onto the next lesson, go to Lessons > Section 3 > Lesson 7"
                              ,"Exit");

        completeLesson();
    }

    //Move to the next step
    currentStep++;
}

void Lesson6::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->acceptInsurancePushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
