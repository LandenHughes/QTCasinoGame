#include "lesson.h"

#include <QMessageBox>

Lesson2::Lesson2(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson2::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the dealer hands in 1 hand rounds.
    Card cards[]{Card(1,10), Card(2,10), Card(3,11), Card(1,12), Card(0,13), Card(0,8), Card(2,9), Card(1,2), Card(3,10), Card(3,9), Card(0,5), Card(2,7), Card(0,1), Card(1,1), Card(2,1)};
    //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(200, cards, 15);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson2::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //On opening the lesson...

        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"Welcome to Lesson 2: The Order of Play & The Delaer's Turn!\n"
                               "In this lesson, you'll learn the order in which this game is played!\n"
                              ,"Continue...");
        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"Before dealing, you can set your bet amount.\n"
                               "The more you bet, the more you can win, but the more you risk.\n"
                               "Try setting the bet to something else to see how it works out!"
                              ,"Got it.");
    }

    else if (currentStep == 1)
    {
        //Player has dealt hand

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);

        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"20 is a good total!  Stand again with this hand."
                              ,"Yup");
    }

    else if (currentStep == 2)
    {
        //Player stands

        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"Looks like the dealer also got a 20.\n"
                               "In the case of a draw, also known as a push, you just get oyur bet back without an extra payout.\n"
                               "Deal out another hand and start fresh!"
                              ,"At least I didn't lose much!");
    }

    else if (currentStep == 3)
    {
        //After a hand is dealt...

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);

        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"Looks like you got a hand of 18.  Just stand for now."
                              ,"Continue");
    }

    else if (currentStep == 4)
    {
        //Player loses
        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"Wait, the dealer has 3 cards now?  Yep!\n"
                               "In BlackJack, the dealer will always hit until they have 17 or more.\n"
                               "Since the first 2 cards only added up to 12, the dealer was forced to hit again.\n"
                               "Unfortunately for you, they now have 21, so you lose... it happens.\n"
                               "The only thing to do now is try again!"
                              ,"Continue");
        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"In some casinos, they have a rule where the dealer has to hit on what is known as a soft 17.\n"
                               "This means if they have an ace treated as an 11 in their hand, they have to hit on 17 as well.\n"
                               "If this rule is in effect, it will be posted on the table."
                              ,"Good to know!");
    }

    else if (currentStep == 5)
    {
        //After a hand is dealt...

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);

        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"Looks like you got a lower hand of 12.  This is too low, so try hitting."
                              ,"Continue");
    }

    else if (currentStep == 6)
    {
        //Player hits and busts
        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"Darn, you busted!  A bust is when you go over 21.\n"
                               "Since you busted, the dealer wins automatically, because the players always play before the dealer."
                              ,"Continue");
        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"Stand to let the dealer know you are done with your turn."
                              ,"Good to know!");
    }

    else if (currentStep == 7)
    {
        emit displayTextPopup("Basic Rules: The Order of Play & The Dealer's Turn"
                              ,"Hopefully you learned about the ways hands can play out, and what the dealer does on their turn.\n"
                               "Go to the next lesson at Lessons > Section 1 > Lesson 3"
                              ,"I will not let this defeat stop me!");
        completeLesson();
    }

    //Move to the next step
    currentStep++;
}

void Lesson2::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
