#include "lesson.h"

#include <QMessageBox>

Lesson11::Lesson11(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson11::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the player hands in 1 hand rounds.
    Card cards[]
    {
        Card(1, 11), Card(2, 11), Card(3, 13), Card(0, 12),
        Card(0, 1), Card(2, 1), Card(3, 10), Card(0, 9), Card(3, 12), Card(0, 7),
        Card(3, 5), Card(0, 5), Card(3, 8), Card(3,7), Card(2, 12),
        Card(2, 3), Card(3, 3), Card(3, 1), Card(2, 7), Card(2, 2), Card(1, 9),
        Card(0, 4), Card(2, 4), Card(3, 11), Card(3, 6), Card(1, 12), Card(2, 10),
        Card(3, 9), Card(2, 9), Card(0, 2), Card(0, 6), Card(1, 7), Card(1, 6)
        };
    //For this lesson, I want the field model to have 1000 chips to start.
    emit controller.clearTable();
    controller.initalizeGame(1000, cards, 33);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->doubleDownPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->splitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    controller.dealOutCards(1, 100);

    stepLesson();
}


void Lesson11::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        emit controller.setHitButtonEnabled(false);
        emit controller.setSplitButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: When to Double Down",
                              "Welcome to the 11th lesson!\n"
                              "This section focuses on splitting and when two hands are better than one.\n"
                              "In this section we will be skipping past most of the hands and only focusing on the decision to split. "
                              "In terms of what to do after splitting, just treat each of the hands like a completely new hand, and follow the "
                              "princples set forth by these lessons and basic strategy in the corresponding situations.",
                              "Ok!");
        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "Once again, you've already been dealt out a hand. This one has two matching 10 cards.\n"
                              "This is a very good hand as it's score is 20. Don't split any hand like this. It's not worth the risk.",
                              "Ok!");
    }
    else if (currentStep == 1)
    {
        controller.endRound();
        controller.dealOutCards(1, 100);

        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "You've gotten a new hand now: a pair of Aces.\n"
                              "This is a hand you always want to split. It's not worth much on it's own, only 12, but is very likely to turn "
                              "into two good hands after splitting.\n"
                              "Simularly if this hand was a pair of 8s you'd also always split.",
                              "Ok!");
    }
    else if (currentStep == 2)
    {
        controller.endRound();
        controller.dealOutCards(1, 100);

        emit controller.setSplitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "Onto the next hand: a pair of 5s.\n"
                              "Treat this hand like any other hard total of 10. Double if the up-card is 9 or less, and hit otherwise.",
                              "Ok!");
    }
    else if (currentStep == 3)
    {
        controller.endRound();
        controller.dealOutCards(1, 100);

        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "Onto the yet another hand: a pair of 3s.\n"
                              "Splitting this hand depends upon the upcard. If the upcard is a 7 or less split, otherwise you should "
                              "simply hit.\n"
                              "Pairs of 2s and 6s are identical to pairs of 3s in this way. Split on upcard of 7 or less and hit otherwise.\n"
                              "Pairs of 7s are also fairly simular to pairs of 2s, 3s and 6s. But you also want to split if the upcard is an 8.",
                              "Ok!");
    }
    else if (currentStep == 4)
    {
        controller.endRound();
        controller.dealOutCards(1, 100);

        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "One more hand: a pair of 4s.\n"
                              "Once more splitting this hand depends upon the upcard. Though, with this hand you only want to split if the "
                              "upcard is a 5 or 6",
                              "Ok!");
    }
    else if (currentStep == 5)
    {
        controller.endRound();
        controller.dealOutCards(1, 100);

        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Soft Totals",
                              "Last hand! A pair of 9s.\n"
                              "This hand is the most complex, once more splitting this hand depends upon the upcard. Though, "
                              "with this hand you only want to split if the upcard is a NOT a 7, 10, or Ace, splitting on each other hand "
                              "in 2-6 and on an 8 or 9.",
                              "Ok!");
    }
    else if (currentStep == 6)
    {
        emit displayTextPopup("Basic Strategy: When to Split",
                              "And That's all of the possible pairs covered!\n"
                              " Congradulations for completeling Lesson 11 and the entirty of Section 3.\n"
                              "Section 4 of the tutorial introduces the player to card counting, which gives you an additional advantage over "
                              "the house and over time can lead to profiting off of blackjack!\n"
                              "Though, before you move onto Section 4 you should practice everything you've learn in Section 3. If you don't "
                              "perfectly remember the basic strategy of blackjack, then even with counting, you wont be able to beat the house!",
                              "Ok!");
    }



    //Move to the next step
    currentStep++;
}

void Lesson11::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(ui->standPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->doubleDownPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->splitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
