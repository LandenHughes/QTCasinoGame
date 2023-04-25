#include "lesson.h"

#include <QMessageBox>

Lesson3::Lesson3(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson3::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the dealer hands in 1 hand rounds.
    Card cards[]{Card(0,1), Card(1,12), Card(0,9), Card(1,9), Card(0,8), Card(2,10), Card(3,1), Card(2,11), Card(3,5)};
    //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(200, cards, 9);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson3::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //On opening the lesson...

        emit displayTextPopup("Basic Rules: BLACKJACK!"
                              ,"In this lesson, you'll learn about the namesake of this game, Blackjack!\n"
                               "If you are lucky enough to get one, your payout is 3:2 instead of 1:1!\n"
                               "Let's see it in action!  (Deal a hand)"
                              ,"Let's do it!");
    }

    if (currentStep == 1)
    {
        //Player gets a blackjack, dealer gets garbage...

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);

        emit displayTextPopup("Basic Rules: BLACKJACK!"
                              ,"You got 2 cards that add up to 21 on their own.  That's a Blackjack!\n"
                               "At this point, the dealer reveals if they have one or not.  If they do, it's a push.\n"
                               "But if they don't, you win AUTOMATICALLY.\n"
                               "Stand to let the dealer know you are done."
                              ,"Sweet!");
    }

    if (currentStep == 2)
    {
        //Player stood...

        emit displayTextPopup("Basic Rules: BLACKJACK!"
                              ,"It's nice when you get one, but the dealer can also get a Blackjack just the same.\n"
                               "Deal out a hand."
                              ,"Uh-Oh");
    }

    if (currentStep == 3)
    {
        //Another hand was dealt, dealer Blackjack...

        emit displayTextPopup("Basic Rules: BLACKJACK!"
                              ,"You got a nice hand, but the dealer got a Blackjack.\n"
                               "You lose automatically, but at least you don't have to pay them 3:2!"
                              ,"Continue");
        emit displayTextPopup("Basic Rules: BLACKJACK!"
                              ,"That's basically the basics.  Onto the advanced rules!\n"
                               "Please go to the next section at Lessons > Section 2 > Lesson 4"
                              ,"Got it");
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

void Lesson3::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
