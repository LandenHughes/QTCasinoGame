#include "lesson.h"

#include <QMessageBox>

Lesson1::Lesson1(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson1::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the player hands in 1 hand rounds.
    Card cards[]{Card(0, 10), Card(2, 11), Card(1, 7), Card(3, 10),
                 Card(0, 7), Card(2, 3), Card(0, 13), Card(1, 8), Card(3, 1), Card(2,1)};
    //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
    emit controller.clearTable();
    controller.initalizeGame(100, cards, 10);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    stepLesson();
}


void Lesson1::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        //On opening the lesson...
        emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                              ,"Welcome to Blackjack!\n"
                               "This is the first lesson, which will teach you about the basics of the game, as well as how to win!\n"
                               "To start, just hit the deal button."
                              ,"Got it!");
    }

    else if (currentStep == 1)
    {
        //After a hand is dealt...

        emit controller.setSplitButtonEnabled(false);
        emit controller.setHitButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);

        emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                              ,"To start the game, the dealer and player are dealt 2 cards, with the dealer getting one face down card.\n"
                               "The goal of the game is to have your cards add up as close to 21 as you can, without going over 21.\n"
                               "Going over 21 is known as a BUST, and if that happens, you lose immediately.\n\n"
                               "Looking at your hand, you have a 10 and a Jack!\n"
                               "Number cards are worth their number value, and face cards (J, Q, K) count as 10. So, your hand has a total of 20 right now.  Not bad!"
                              ,"Continue");
        emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                              ,"You can hit to get another card, since you aren't at 21, but since you would need an Ace (1) to do that, you'll probably bust and lose.\n"
                               "Just click stay for now, and see what the dealer has."
                              ,"Easy Peasy");
    }

    else if (currentStep == 2)
    {
        //Player hits stand, dealer takes turn...

        emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                              ,"After standing, your turn ends, and it becomes the dealers turn.\n"
                               "We'll go over what the dealer does in their turn later, but for now just know they reveal their hidden card at the start.\n"
                              ,"Continue");
        emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                              ,"The dealer got a 17, which is less than a 20, so you win!\n"
                               "Congratulations!  Since you put in 10 chips, the payout is 20 chips, this is the classic 1:1 payout. \n"
                               "Deal out another hand!"
                              ,"Onto the next hand!");
    }

    else if (currentStep == 3)
    {
        //The second hand is dealt

        emit controller.setStandButtonEnabled(false);
        emit controller.setDoubleButtonEnabled(false);

        emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                              , "You've gotten your second hand. Though it's only a 7 and a 3. You should go ahead and hit."
                              , "On it!");

    }

    else if (currentStep == 4)
    {
        //Player hits, gets an Ace...

        emit controller.setStandButtonEnabled(true);
        emit controller.setHitButtonEnabled(false);

        emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                              ,"You got an Ace!\n"
                               "Aces have the neat property as being able to be treated as a 1 or an 11, depending on which one would make you have a bigger hand!\n"
                               "Right now, the ace is treated as an 11, since that would bring you to 21!\n"
                               "Since you have 21, just stand for now! You can't get a better hand than this!"
                              ,"Perfect!");

    }
    else if (currentStep == 5)
    {
        //Player stands...
        //emit controller.setDealButtonEnabled(false); //Disable the "Deal" Button

        emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                              ,"Congadulations! You have completeing the first lesson!\n"
                               "The next lesson will go over when you bet, the order of play, and the dealer's strategy.\n"
                               "To access it just nagivate to Lessons > Section 1 > Lesson 2"
                              ,"Ok!");

        completeLesson();
    }

    //Move to the next step
    currentStep++;
}

void Lesson1::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
