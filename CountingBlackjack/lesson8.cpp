#include "lesson.h"

#include <QMessageBox>

Lesson8::Lesson8(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson8::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the player hands in 1 hand rounds.
    Card cards[]{Card(0, 10), Card(2, 9), Card(0, 3), Card(1, 12), Card(2, 11),
                 Card(1, 5), Card(0, 3), Card(1, 11), Card(3, 8), Card(3, 6), Card(2, 5),
                 Card(1, 8), Card(1,7), Card(0, 7), Card(1, 4), Card(0, 12)};
    //For this lesson, I want the field model to have 1000 chips to start.
    emit controller.clearTable();
    controller.initalizeGame(1000, cards, 10);

    //TODO: Disable changing bets and hand size, set both to minimum values.

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(&controller, &Controller::roundFinished, this, &Lesson::stepLesson);
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    controller.dealOutCards(1, 100);

    stepLesson();
}


void Lesson8::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        emit controller.setHitButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "Welcome to the 8th lesson!\n"
                              "This section focuses on what to do when you have hands without Aces.\n",
                              "Ok!");
        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "As you can see, you've already been dealt a hard 19.\n"
                              "This is a good hand. You should stand because you much more likely to bust than to improve your hand "
                              "if you hit.\n"
                              "In fact, basic strategy suggests standing on all hands totaling 17 or more, regardless of the up-card",
                              "Ok!");
    }
    else if (currentStep == 1)
    {
        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "Congratulations on winning the last hand!\n"
                              "Go ahead and deal yourself out a new hand now!",
                              "Ok!");
    }
    else if (currentStep == 2)
    {
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "You've gotten your next hand: a hard 8.\n",
                              "You should hit on this hand. You cannot bust will have diffculty winning with a total of 8.\n"
                              "In fact, you should hit on any hand with a total of 11 or less for this very reason\n"
                              "Ok!");
    }
    else if (currentStep == 3)
    {
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "So you've hit, and your hand has improved, but not enough to get you into that 17+ range. What now?\n"
                              "In this circumstance look towards the up-card. As it's 8 you will want to hit once more as it's likely that "
                              "the dealer already has 17 or more and thereby cannot bust.\n"
                              "Generally, you should hit any hand with a hard total of 13-16 when the upcard is a 7 or better.",
                              "Ok!");
    }
    else if (currentStep == 4)
    {
        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "And that's another hand won with basic strategy!\n"
                              "Lets deal you out another hand now!",
                              "Ok!");
    }
    else if (currentStep == 5)
    {
        emit controller.setHitButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "Okay so this time you've gotten a hard 15.\n",
                              "As it's within 13-16 we once more we look towards the up-card. This time it's only a 4!\n"
                              "You should stand on this hand and other hands that have a hard total of 12-16 and an up-card of 6 or less."
                              "Ok!");
    }
    else if (currentStep == 6)
    {
        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "Oh, that's unfortunate, you lost! Still this is an important thing to know. Basic strategy doesn't gaurentee "
                              "victory. It just minimizes the amount you will lose over time\n"
                              "Don't get discouraged! I have one last thing to teach you, so deal yourself out another hand!",
                              "Ok");
    }

    //Move to the next step
    currentStep++;
}

void Lesson8::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(&controller, &Controller::roundFinished, this, &Lesson::stepLesson);
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
