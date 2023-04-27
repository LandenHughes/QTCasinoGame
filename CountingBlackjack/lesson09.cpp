#include "lesson.h"

#include <QMessageBox>

Lesson9::Lesson9(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson9::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the player hands in 1 hand rounds.
    Card cards[]{Card(1, 1), Card(2, 8), Card(1, 12), Card(2, 7),
                 Card(0, 1), Card(3, 4), Card(1, 11), Card(3, 8), Card(1, 9), Card(2, 5), Card(0, 3),
                 Card(2, 1), Card(1, 7), Card(0, 7), Card(1, 6), Card(0, 12)};
    //For this lesson, I want the field model to have 1000 chips to start.
    emit controller.clearTable();
    controller.initalizeGame(1000, cards, 16);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(&controller, &Controller::roundFinished, this, &Lesson::stepLesson);
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    controller.dealOutCards(1, 100);

    stepLesson();
}


void Lesson9::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        emit controller.setHitButtonEnabled(false);
        //emit controller.setStandButtonEnabled(true);

        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "Welcome to the 9th lesson!\n"
                              "This section focuses on what to do when you have a hand with an Ace.\n"
                              "The strategy is a little bit different from hard hands as you can afford to play a little more risky!",
                              "Ok!");
        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "As you can see, you've already been dealt a soft 19.\n"
                              "This is a good hand, and already beats out most other hands in blackjack. In fact there are only 2 better hands!\n"
                              "So for a soft hand like this one, or one with a better score, you should always stand.",
                              "Ok!");
    }
    else if (currentStep == 1)
    {
        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "With a hand like that one it's fairly hand to lose if you just hold!\n"
                              "Go ahead and deal yourself out a new hand now!",
                              "Ok!");
    }
    else if (currentStep == 2)
    {
        //emit controller.setHitButtonEnabled(true);
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "You got your new hand: a soft 15.\n"
                              "This hand is no good, and loses to any hand that the dealer would stay on. If you stand your only hope would be the "
                              "dealer busting.\n"
                              "But remember! Even if you get a card worth ten you wont bust! There's no risk, so hit!",
                              "Ok!");
    }
    else if (currentStep == 3)
    {
        emit controller.setHitButtonEnabled(true);
        emit controller.setStandButtonEnabled(true);
        disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "The card you got was an 9.\n"
                              "If you hand hand been a hard 15 this would've broughten your score to 24. A bust. "
                              "Thankfully though your hand was a soft 15. So now counting your ace a worth 1, your score is 14.\n"
                              "Do note though this is now a hard 14 as the ace is being counted as 1 point and cannot save you from busting again.\n"
                              "Go ahead and finish playing out this hand. Though, If you forgot what to do in this situation please review lesson "
                              "8 once this lesson is completed",
                              "Ok!");
    }
    else if (currentStep == 4)
    {
        controller.burnCards(controller.cardsInDeck() - 5);
        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "Another hand done and dusted, so please deal yourself out a new hand now!",
                              "Ok!");
    }
    else if (currentStep == 5)
    {
        emit controller.setHitButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "You've been dealt a soft 18. This hand is one of the ones that depends upon the up-card.\n"
                              "As the upcard is currently a 6 you should stand! Infact, with a soft 18 you should stand whenever the "
                              "up-card is an 8 or less!",
                              "Ok!");
    }
    else if (currentStep == 6)
    {
        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "Another hand won!\n"
                              "Remember! A soft 18 is a hand where you have to consider the up-card. "
                              "An 8 or less means you should stay. A 9 or better mean you should hit!",
                              "Ok!");
        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "With that, we've reached the end of lesson 9!\n"
                              "Good job finishing yet another lesson! You should play a couple rounds via navigating to Play > Play Game"
                              " and continue onto lesson 10 when you feel comfortable with what to do with most hands!\n"
                              "The next lesson discusses when to double down, so look forward to that!",
                              "Ok!");

        completeLesson();
    }


    //Move to the next step
    currentStep++;
}

void Lesson9::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(&controller, &Controller::roundFinished, this, &Lesson::stepLesson);
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
