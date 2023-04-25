#include "lesson.h"

#include <QMessageBox>

Lesson13::Lesson13(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson13::initLesson()
{
    currentStep = 0;

    //player gets 3 and 2, dealer has up king and down 9
    Card cards[]{Card(0, 3), Card(2, 2), Card(1, 9), Card(3, 13)};
    //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(10, cards, 4);

    //TODO: Disable changing bets and hand size, set both to minimum values.

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson13::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //Briefly Describe true count
        emit displayTextPopup("Into to True Count"
                              ,"When playing with multiple decks(as all casinos do) placing a more accurate bet will require you "
                              "to calculate the True Count. The true count is calculated by diving the running count by the number of "
                              "remaining decks (being the decks that have not yet been rotated or reshuffled). Press OK for an example."
                              ,"Continue");

        emit displayTextPopup("True Count Example"
                              ,"For example if you running count is +2 and there are 3 decks left your true count is 2/3. "
                              "This puts you at a disadvantage to the house. When the true count is below 1 you are at a disadvantage, "
                              "when count is 1 you are playing an even game and should rely on basic strategy, and when true count is greater than 1"
                              "you are at an advantage."
                              ,"Continue");

        emit displayTextPopup(""
                              ,"We will continue from where we left off from the last lesson, where the running count was 2 playing with 2 decks. "
                              "So the true count is 2/2 which is 1, you are playing an even game right now. Press Deal to get your next hand. "
                              ,"Continue");
    }

    else if (currentStep == 1)
    {
        //After a hand is dealt...deal player 3 and 2 and dealer 8 up and Ace down

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);


        emit displayTextPopup("Calculating the true count"
                              ,"You got a 3 and 2, and the dealers upcard is king, the new current running count is 3. "
                              "We havent rotated decks yet so go ahead and calculate the true count. Press OK to see if you were right."
                              ,"Continue");
        emit displayTextPopup("See if your calcultion was right"
                              ,"The true count is 3/2 so 1.5, meaning that you have the advantage over the house. Press Ok to continue"
                              ,"Continue");

        emit displayTextPopup("See if your calcultion was right"
                              ,"Now lets say that after dealing the last hand the dealer has finished thefirst deck, "
                               "so there is now one remaining deck. "
                               "Calculate the True count and Press OK to verify you are correct."
                              ,"Continue");

        emit displayTextPopup("See if your calcultion was right"
                              ,"With one deck remaining and the running count still at 3 the new true count is 3/1 which is 3. "
                               "You are now in a very good position for you next hand."
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

void Lesson13::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
