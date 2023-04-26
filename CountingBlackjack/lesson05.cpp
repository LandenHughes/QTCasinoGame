#include "lesson.h"

#include <QMessageBox>

Lesson5::Lesson5(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson5::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the dealer hands in 1 hand rounds.
    Card cards[]{Card(0,7), Card(1,2), Card(3,8), Card(1,9), Card(2,9), Card(3,9)};
    //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(200, cards, 6);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->doubleDownPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson5::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //On opening the lesson...

        emit displayTextPopup("Advanced Rules: Double Down"
                              ,"In this lesson, you'll learn about a more advanced rule, doubling down!\n"
                               "When your starting hand has a total of 9,10, or 11, you can double down.  \n"
                               "If you do, you double your bet for that hand, but you only get 1 more card!\n"
                               "Deal out a hand to try it out!"
                              ,"Let's do it!");
    }

    if (currentStep == 1)
    {
        //Player gets 9, dealer gets 17...

        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Advanced Rules: Double Down"
                              ,"You have a chance to double down here!\n"
                               "Remember that your original bet gets doubled here, so look at your chips while doubling down!"
                              ,"Gotcha");
    }

    if (currentStep == 2)
    {
        //Player doubles down...

        emit displayTextPopup("Advanced Rules: Double Down"
                              ,"From your extra card, you got 18, not bad.\n"
                               "Stand to let the dealer know it's their turn!"
                              ,"Gotcha");

        emit controller.setStandButtonEnabled(true);
    }

    if (currentStep == 3)
    {
        //Player stands...

        emit displayTextPopup("Advanced Rules: Double Down"
                              ,"The dealer had 17, so you win this hand!\n"
                               "Since you doubled your bet, your payout is also twice as much as if you hadn't doubled down.\n"
                               "To move onto the next lesson, go to Lessons > Section 2 > Lesson 6"
                              ,"Exit");

        completeLesson();
    }

    //Move to the next step
    currentStep++;
}

void Lesson5::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->doubleDownPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
