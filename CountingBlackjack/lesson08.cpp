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
                 Card(1, 8), Card(1,7), Card(0, 7), Card(1, 4), Card(0, 12),
                 Card(2,3), Card(3,9), Card(1, 1), Card(2,2), Card(0, 4), Card(2, 13), Card(3, 10), Card(3, 12)};
    //For this lesson, I want the field model to have 1000 chips to start.
    emit controller.clearTable();
    controller.initalizeGame(1000, cards, 24);

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

        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "Welcome to the 8th lesson!\n"
                              "This section focuses on what to do when you have a hand without an Ace.\n",
                              "Ok!");
        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "As you can see, you've already been dealt a hard 19.\n"
                              "This is a good hand. You should stand because you much more likely to bust than to improve your hand "
                              "if you hit.\n"
                              "In fact, basic strategy suggests standing on all hands with a hard total of 17 or more, regardless of the up-card",
                              "Ok!");
    }
    else if (currentStep == 1)
    {
        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "Congratulations on winning the last hand!\n"
                              "Go ahead and deal yourself out a new hand now!",
                              "Ok!");
    }
    else if (currentStep == 2)
    {
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "You've gotten your next hand: a hard 8.\n"
                              "You should hit on this hand. You cannot bust will have diffculty winning with a total of 8.\n"
                              "In fact, you should hit on any hand with a total of 11 or less for this very reason\n",
                              "Ok!");
    }
    else if (currentStep == 3)
    {
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "So you've hit, and your hand has improved, but not enough to get you into that 17+ range. What now?\n"
                              "In this circumstance look towards the up-card. As it's 8 you will want to hit once more as it's likely that "
                              "the dealer already has 17 or more and thereby cannot bust.\n"
                              "Generally, you should hit any hand with a hard total of 13-16 when the upcard is a 7 or better.",
                              "Ok!");
    }
    else if (currentStep == 4)
    {
        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(true);

        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "With that hit, you're total is 19! That's enough to stand!\n",
                              "Ok!");
    }
    else if (currentStep == 5)
    {
        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "And that's another hand won with basic strategy!\n"
                              "Lets deal you out another hand now!",
                              "Ok!");
    }
    else if (currentStep == 6)
    {
        emit controller.setHitButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "Okay so this time you've gotten a hard 15.\n"
                              "As it's within 13-16 we once more we look towards the up-card. This time it's only a 4!\n"
                              "You should stand on this hand and other hands that have a hard total of 12-16 and an up-card of 6 or less.",
                              "Ok!");
    }
    else if (currentStep == 7)
    {
        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "Oh, that's unfortunate, you lost! Still this is an important thing to know. Basic strategy doesn't gaurentee "
                              "victory. It just minimizes the amount you will lose over time\n"
                              "Don't get discouraged! There is one last thing to teach you, so deal yourself out another hand!",
                              "Ok");
    }
    else if (currentStep == 8)
    {
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "You drew a hard 12. This is a little bit of a tricky hand.\n"
                              "It is very similar to hard totals of 13-16 in that you want to base your decisions based upon the up-card. "
                              "Though, unlike a 13-16, you only want to stay on a 12 if the up-card is a 4-6, hitting on up-cards of 2, 3, "
                              "and 7-Ace.",
                              "Got it!");
    }
    else if (currentStep == 9)
    {
        disconnect(ui->hitPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

        emit controller.setStandButtonEnabled(true);
        emit controller.setHitButtonEnabled(true);

        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "A 4, bringing your total to 16\n"
                              "Against an up-card of 2, you remember what to do right?",
                              "Yes!");
    }
    else if (currentStep == 10)
    {
        ui->dealPushButton->setEnabled(false);

        emit displayTextPopup("Basic Strategy: Hard Totals",
                              "That brings us to the end of Lesson 8!\n"
                              "The next lesson will talk about what to do when you have an ace in your starting hand.\n"
                              "Lastly, did you win that last hand? If you made sure to the basic strategy you should have!",
                              "Ok");
        completeLesson();
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
