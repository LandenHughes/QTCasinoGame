#include "lesson.h"

#include <QMessageBox>

Lesson12::Lesson12(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson12::initLesson()
{
    currentStep = 0;

    //player gets 4 and 2, dealer gets 7 up card and Q down card, when player hits they get a 5 and hits again to get an 8
    Card cards[]{Card(0, 4), Card(2, 2), Card(1, 12), Card(3, 7),
                 Card(0, 5), Card(2, 8)};
    //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(10, cards, 6);

    //TODO: Disable changing bets and hand size, set both to minimum values.

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson12::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //Briefly Describe card counting
        emit displayTextPopup("Calculating Running Count"
                              ,"Now that you know some of the basics of the game and some strategy "
                              "I will now teach you how to get an edge over the dealer through a method called card counting. "
                              "There are many card counting strategies, one of the most common being the Hi-Lo"
                              "system which is the strategy that you will be tought."
                              ,"Continue");

        emit displayTextPopup("Assigning Ranks"
                              ,"The first step to counting cards using the Hi-Lo system is keeping track of the running count. "
                               "As a general rule the higher the count the more of an advantage "
                              "the player has over the dealer. Each set of card ranks has an assigned value being -1, 0 or +1. "
                               "Hit OK to see the card's assigned values."
                              ,"Continue");

        emit displayTextPopup("Assigning Ranks Continued"
                              ,"The counts that you need to know for this system are cards with ranks of 2-6 have a value of +1. "
                              "Ranks 7-9 have a value of 0 and the remaining cards being 10, all face cards and ace have a value of -1. "
                              "For example if the first 8 cards to come out are\tK,  8,  7,  4,  Q,  J,  A,  2\n"
                                                               "\t\t-1  0  0  +1 -1 -1 -1 +1 = -2 "
                               "so current running count is -2. "
                              "As each card comes out you will update the running count. Hit the deal button and calculate the current "
                               "running count."
                              ,"Continue");
    }

    else if (currentStep == 1)
    {
        //After a hand is dealt...

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Calculating the running count"
                              ,"Take a look at you cards and the dealers card and calculate the running count. "
                               "Hit OK when you have calculated the running count"
                              ,"Continue");
        emit displayTextPopup("See if your calcultion was right"
                              ,"You have a 4 and a 2 and the dealer's upcard is 7. The running count is currently 2 because 4 is +1, 2 is +1 and 7 is 0. "
                                "Now select hit to continue playing your hand."
                              ,"Continue");

        emit controller.setHitButtonEnabled(true);
    }

    else if (currentStep == 2)
    {
        //Player hits first time
        emit controller.setHitButtonEnabled(false);

        emit displayTextPopup("Running Count Calculation Practice"
                              ,"You got a 5, now the count is +3 because 5 has a value of +1. Go ahead and hit again."
                              ,"Continue");

        emit controller.setHitButtonEnabled(true);
    }

    else if (currentStep == 3)
    {
        //player hits for second time

        emit controller.setHitButtonEnabled(false);

        emit displayTextPopup("Running Count Calculation Practice"
                              , "You got an 8, nothing happens to the running count because 8 has a value of 0. Stand here you have 20."
                              , "On it!");

        emit controller.setStandButtonEnabled(true);
    }

    else if (currentStep == 4)
    {
        //Player stands, dealer shows down card

        emit controller.setStandButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);

        emit displayTextPopup("Dealer Shows down card"
                              ,"The dealer revealed his down card, it is a Queen so update the running count by -1 making the current running count 2. "
                               "You won this hand and the running count is positive so you have a small advantage over the house on the next hand. "
                              ,"Perfect!");
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

void Lesson12::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
