#include "lesson.h"

#include <QMessageBox>

Lesson4::Lesson4(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson4::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the dealer hands in 1 hand rounds.
    Card cards[]{};
    //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(200, cards, 9);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson4::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //On opening the lesson...

        emit displayTextPopup("Advanced Rules: Splitting!"
                              ,"In this lesson, you'll learn about a more advanced rule, splitting!\n"
                               "Splitting is an additional option that lets you get more out of your bets."
                               "Let's see it in action!  (Deal a hand)"
                              ,"Let's do it!");
    }

    if (currentStep == 1)
    {
        //Player gets two 9s, dealer gets 17...

        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);

        emit displayTextPopup("Basic Rules: BLACKJACK!"
                              ,"Since you got two cards of the same value, you can split them into 2 different hands, each one getting a new card!\n"
                               "When splitting, you have to add your origional bet to your second hand as well, so look at your chip count when splitting."
                              ,"Sweet!");
    }

    if (currentStep == 2)
    {
        //Player split...

        emit displayTextPopup("Basic Rules: BLACKJACK!"
                              ,"Now you're playing with two hands, when you finish this one's turn you can see the next one's.\n"
                               "Techinically you're done with the lesson, but you can play around a bit to see how it works!\n"
                               "Remember that, when you're ready, to view the next lesson at Lessons > Section 2 > Lesson 5"
                              ,"Yay!");

        completeLesson();
    }

    /**
     * And so on and so forth.  Remember that the order of steps is:
     * 0 - Lesson opens, emidiately call stepLesson() after a lesson opens.
     * 1 - First hand is dealt.
     * 2 + This happens for any action, such as a dealout, the end of a round, the player hitting, the player standing, the player splitting, etc.
     *     Make sure you enable/disable buttons and stack the deck as needed to keep things on the right track.
     *     This does not mean each lesson needs to be linear, as you could for exmple offer hit and split, and the next step would see if the player busted or
     *     not to reprimand them from hitting at 20, or let them know how lucky they got.
     *
     *     Just know that all actions will move the step forward, so KNOW THIS when preparing the lesson.
     *
     *     List of action that advance:
     *
     *     Opening the lesson.
     *     Clicking "Deal"
     *     Clicking "Stand"
     *     Clicking "Hit" (REMEMBER THE PLAYER HAS TO HIT STAND AFTER BUSTING).
     *     Clicking "Double Down"
     *     Clicking "Split"
     *     Clicking "Insurance"
     *     The Dealer's turn ending
     *
     *     Actions that DO NOT ADVANCE:
     *     Setting the bet
     *     Setting the hand size
     **/

    //Move to the next step
    currentStep++;
}

void Lesson4::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
