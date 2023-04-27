#include "lesson.h"

#include <QMessageBox>

Lesson10::Lesson10(Ui::MainWindow *ui, Controller &controller)
    : Lesson(ui, controller)
{}

void Lesson10::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the player hands in 1 hand rounds.
    Card cards[]{Card(1, 4), Card(3, 7), Card(3, 3), Card(3, 12), Card(2, 12), Card(3, 6),
                 Card(1,7), Card(2,2), Card(1,11), Card(2,8), Card(2, 5), Card(0,3), Card(1, 10),
                 Card(3, 4), Card(0, 6), Card(3, 10), Card(2, 6), Card(0, 13), Card(3, 1)};

    //For this lesson, I want the field model to have 1000 chips to start.
    emit controller.clearTable();
    controller.initalizeGame(1000, cards, 19);

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(&controller, &Controller::roundFinished, this, &Lesson::stepLesson);
    connect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);
    connect(ui->doubleDownPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    controller.dealOutCards(1, 100);

    stepLesson();
}


void Lesson10::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: When to Double Down",
                              "Welcome to the 10th lesson!\n"
                              "This section focuses on doubling down and when the risk is worth it.\n"
                              "Remember, in our simulator you can only double down on a hand with a hard 9, 10, or 11, and only if it's your "
                              "first two cards.\n"
                              "Though, most of these occasion are times you'd want to double down regardless, as you cannot bust are are likely "
                              "to get close to 21!",
                              "Ok!");
        emit displayTextPopup("Basic Strategy: When to Double Down",
                              "Once again, you've already been dealt out a hand, one with a hard total of 11.\n"
                              "This is a very good hand. Any card worth 10 will make this hand into a 21, and most others will get you fairly close.\n"
                              "As such, regardless of the up-card, you should double down!",
                              "Ok!");
    }
    else if (currentStep == 1)
    {
        emit controller.setStandButtonEnabled(true);
    }
    else if (currentStep == 2)
    {
        emit displayTextPopup("Basic Strategy: When to Double Down",
                              "Another win, and because you doubled down your won twice as much from that hand!\n"
                              "Lets continue, hands with 9s and 10s are slightly more complex\n"
                              "Deal yourself out a new hand!",
                              "Ok!");
    }
    else if (currentStep == 3)
    {
        emit controller.setDoubleButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: When to Double Down",
                              "You got an 9. Unlike a 11 which is a slam dunk hand, you'll want to be a little more careful with this one.\n"
                              "The up-card is an 8 right now, so if they had assuming they had a 10 card, you'd need a a ten card of your own to win "
                              "this.\n"
                              "It's best not to double down right now. In fact, on a 9, you only want to double down when the up-card is a 6 or worse. "
                              "When the up-card is 7 or better, just play the hand like you didn't have the option to double down at all!\n",
                              "Ok!");
    }
    else if (currentStep == 4)
    {
        controller.burnCards(controller.cardsInDeck() - 6);
        emit displayTextPopup("Basic Strategy: When to Double Down",
                              "Unfortunately that hand just wasn't in the cards for you. No matter what you had done you would've lost\n"
                              "Though, because you didn't double down you only lost your origonal bet instead of double it! That's a relief!\n"
                              "We haven't covered hard totals of 10 yet, so deal yourself out a new hand!",
                              "Ok!");
    }
    else if (currentStep == 5)
    {
        emit controller.setHitButtonEnabled(false);
        emit controller.setStandButtonEnabled(false);

        emit displayTextPopup("Basic Strategy: When to Double Down",
                              "It's a 10.\n"
                              "A 10 is safer than a 9 but still more risky than an 11, so you'll play this hand slightly more safely than "
                              "an 11. You want to double down in most circumstances, but a up-card worth 10 or an ace is enough to exercise "
                              "caution and play it like a normal hand.\n"
                              "In this case though the up-card is a 6. Go ahead a double down, you're in a winning position!",
                              "Ok!");
    }
    else if (currentStep == 6)
    {
        emit controller.setStandButtonEnabled(true);
    }
    else if (currentStep == 7)
    {
        emit displayTextPopup("Basic Strategy: When to Double Down",
                              "With one final win you've finished lesson 10!\n"
                              "Please continue onto lesson 12 to lear about when it's best to split!\n"
                              "Though a quick spolier. It's best to treat a pair of 5s like a hard 10, and double down when you would "
                              "with any other hand like that!",
                              "Ok!");
    }



    //Move to the next step
    currentStep++;
}

void Lesson10::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(&controller, &Controller::roundFinished, this, &Lesson::stepLesson);
    disconnect(ui->dealPushButton, &QPushButton::clicked, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
