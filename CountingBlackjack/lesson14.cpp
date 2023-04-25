#include "lesson.h"

#include <QMessageBox>

Lesson14::Lesson14(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson14::initLesson()
{
    currentStep = 0;

    //player gets 3 and 2, dealer has up king and down 9
    Card cards[]{Card(0, 11), Card(2, 10), Card(1, 9), Card(3, 12),
                Card(0, 12), Card(2, 1), Card(1, 8), Card(3, 11)};
    //For this lesson, I want the field model to have 30 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(30, cards, 8);

    //TODO: Disable changing bets and hand size, set both to minimum values.

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson14::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //Briefly Describe true count
        emit displayTextPopup("Continuing from last lesson"
                              ,"We will continue where we left off on the last lesson. Remember the Running count is 3 and there is only"
                              "one remaining deck so the true count is 3 aswell."
                              ,"Continue");

        emit displayTextPopup("Intro to bet spreads"
                              ,"In this lesson we will discuss bet spreads. "
                               "The idea of a bet spread is to assist you in how much to increase or decrease your bets given the true count. "
                               "You can use your own style and decide what will work for you but to start I suggest to place you bets using this "
                               "formula, (true count - 1) * previous bet(for this game bet units are 10). With the currenttrue count being 3 what "
                               "should your next bet be? Go ahead and place your bet and hit deal to continue."
                              ,"Continue");

    }

    else if (currentStep == 1)
    {
        //After a hand is dealt...

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Calculating bet amount"
                              ,"True count is 3 so after putting that into the formula provided you should get (3-1)*10(previous bet) which is 20. "
                               "Do not forget to continue to calculate the count."
                              ,"Continue");
        emit displayTextPopup(""
                              ,"Your hand currently totals to 20, you should stand here."
                              ,"Continue");
        emit controller.setStandButtonEnabled(true);

    }

    else if (currentStep == 2)
    {
        //After stand

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("New hand with new count"
                              ,"The dealer has revealed a Queen, "
                               "meaning the count is now 3-1(from jack)-1(from 10)-0(from 8) and -1(from Queen) = 0. "
                               "Now that the count is back down there are less high value cards left in the deck so you should decrese "
                               "your bet back to the minimum($10). Deal next hand to continue"
                              ,"Continue");
    }

    else if (currentStep == 3)
    {
        //After deal blackjack

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Bet based on true count"
                              ,"Congrats! You have blackjack and now have learned the basics of counting. "
                               "The next lesson will conver some special cases that will continue to assist you in taking the casios money!"
                              ,"Continue");
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

void Lesson14::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
