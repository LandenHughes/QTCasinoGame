#include "lesson.h"

#include <QMessageBox>

Lesson15::Lesson15(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson15::initLesson()
{
    currentStep = 0;

    //player gets 10 and 10, dealer has up 7 and down jack
    Card cards[]{Card(0, 10), Card(2, 10), Card(1, 11), Card(3, 7),
                Card(0, 8), Card(2, 7),
                Card(1, 5), Card(3, 7), Card(1, 1), Card(3, 2), Card(2,9)};
    //For this lesson, I want the field model to have 100 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(100, cards, 11);

    //TODO: Disable changing bets and hand size, set both to minimum values.

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson15::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //Briefly Describe true count
        emit displayTextPopup("Intro to Illustrious18"
                              ,"The final lesson will teach you how to use the Illustrious 18 created by Donald Schlesinger. "
                               "Schlesinger is a member of the Blackjack hall of fame and the author of Blackjack Attack. "
                               "This will take some memorization but will provide a significant advantage over the house."
                              ,"Continue");

        emit displayTextPopup("Intro to Illustrious18"
                              ,"All of the following plays represent player hand on the left vs a dealer up-card and an index. "
                               "If the true count is less than the index the player should hit. "
                               "In any other case the player should stand, double or split accordingly.\n"
                              "hand v dealer Card	Index"
                          "1		Insurance		+3\n"
                          "2		16 Vs. 10		+0\n"
                          "3		15 Vs. 10		+4\n"
                          "4		10,10 Vs. 5		+5\n"
                          "5		10,10 Vs. 6		+4\n"
                          "6		10 Vs. 10		+4\n"
                          "7		12 Vs. 3		+2\n"
                          "8		12 Vs. 2		+3\n"
                          "9		11 Vs. A		+1\n"
                          "10		9 Vs. 2		    +1\n"
                          "11		10 Vs. A		+4\n"
                          "12		9 Vs. 7		    +3\n"
                          "13		16 Vs. 9		+5\n"
                          "14		13 Vs. 2		-1\n"
                          "15		12 Vs. 4		0\n"
                          "16		12 Vs. 5		-2\n"
                          "17		12 Vs. 6		-1\n"
                          "18		13 Vs. 3		-2\n"
                               "You can refer later to the illustrious 18 chart in the help menu."
                              ,"Continue");//will prob need to fix formatting

        emit displayTextPopup("Intro to Illustrious18"
                              ,"Lets say the current running count is 9 and there are 2 decks remaining making the true count 4.5. "
                               "Place your bet and select deal to continue."
                              ,"Continue");

    }

    else if (currentStep == 1)
    {
        //After a hand is dealt...Deal player: 10, 10 Dealer: 7 upcard, Jack downcard

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Using the illustrious18"
                              ,"You have two 10s and the dealer's upcard is a 7. "
                               "This corosponds to #5 on the illustrious 18(refer to illustrious 18 in help menu). "
                               "Since the true countis higher than the index you should split since you have two high value cards. "
                              ,"Continue");
        emit controller.setSplitButtonEnabled(true);

    }

    else if (currentStep == 2)
    {
        //After split

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Using the illustrious18"
                              ,"Hit on the first hand"
                              ,"Continue");
        emit controller.setHitButtonEnabled(true);

    }

    else if (currentStep == 3)
    {
        //after first hit
        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Using the illustrious18"
                              ,"Stand on this hand"
                              ,"Continue");
        emit controller.setStandButtonEnabled(true);
    }

    else if (currentStep == 4)
    {
        //after first stand
        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Using the illustrious18"
                              ,"You should hit on this hand too"
                              ,"Continue");
        emit controller.setHitButtonEnabled(true);
    }

    else if (currentStep == 5)
    {
        //after second hit
        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Using the illustrious18"
                              ,"You now stand"
                              ,"Continue");
        emit controller.setStandButtonEnabled(true);
    }

    else if (currentStep == 6)
    {
        //after second stand
        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Using the illustrious18"
                              ,"You won with the first hand and pushed with the second."
                               "Not bad! Deal your next hand"
                              ,"Continue");
        emit controller.setStandButtonEnabled(true);

    }

    else if (currentStep == 7)
    {
        //after second deal Deal player: 5, 7 Dealer: 2 upcard, Ace downcard
        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Using the illustrious18"
                              ," Now lets say the true count is 1. "
                               "You have a 12 total and the dealer has a 2 upcard. "
                               "This corosponds to #8 on the illustrious 18 but since the the true count is 1 "
                               "and the index of #8 is +3 you should hit. "
                              ,"Continue");

        emit controller.setHitButtonEnabled(true);
    }

    else if (currentStep == 8)
    {
        //after hit(deal player 9 to put them to 21)
        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Using the illustrious18"
                              ,"Nice! You hit 21, you win"
                              ,"Continue");

        emit displayTextPopup("End of lessons"
                              ,"This is the end of the lessons you can now play blackjack as normal and feel free to refer to the illustrious18 "
                               "in the help menu as you play."
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

void Lesson15::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
