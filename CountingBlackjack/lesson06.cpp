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

        emit displayTextPopup("Advanced Rules: Insurance"
                              ,"Since the dealer has a face-up ace card, you can pay insurance after playing your hand!\n"
                               "In some casinos, insurance is payed before you play, but in this game, we play so you pay for insurance afterwards."
                              ,"OK");
        emit displayTextPopup("Advanced Rules: Insurance"
                              , "Just stay this hand since it's already 18."
                              ,"OK");

    }

    if (currentStep == 2)
    {
        //Player stands, is offered insurance...

        emit controller.setDenyInsuranceButtonEnabled(false);

        emit displayTextPopup("Advanced Rules: Insurance"
                              ,"At this point you can choose to buy insurance.\n"
                               "Insurance costs half the bet of your hand.\n"
                               "If the dealer does not have a Blackjack, you simply lose this insurance cost.\n"
                               "If they do have a Blackjack, your insurance gets payed back 2:1!\n"
                               "This is a fancy way of saying that you don't lose any chips, but you don't gain any other.\n"
                              ,"Gotcha");

        emit displayTextPopup("Advanced Rules: Insurance"
                              ,"I have a bad feeling about this, so try getting insurance!"
                              ,"Gotcha");

    }

    if (currentStep == 3)
    {
        //Player gets insurance...

        emit displayTextPopup("Advanced Rules: Insurance"
                              ,"The dealer in fact had a Blackjack!\n"
                               "Since you insured yourself, your precious chips stay on your side of the table!"
                              ,"Exit");

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
