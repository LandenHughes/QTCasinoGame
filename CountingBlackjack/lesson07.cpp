#include "lesson.h"

#include <QMessageBox>

Lesson7::Lesson7(Ui::MainWindow *ui, Controller &controller)
        : Lesson(ui, controller)
{}

void Lesson7::initLesson()
{
    currentStep = 0;

    //Stack the deck as needed.  Remember cards are dealt to the player hands, then the player hands in 1 hand rounds.
    Card cards[]{Card(3, 6), Card(2, 8), Card(0, 7), Card(3, 10), Card(1, 6), Card(0,8), Card(3,3)};
    //For this lesson, I want the field model to have 1000 chips to start.
    emit controller.clearTable();
    controller.initalizeGame(1000, cards, 7);

    //TODO: Disable changing bets and hand size, set both to minimum values.

    // Connect the lesson to the ui, allowing it to advnace when any of these buttons are pressed
    connect(&controller, &Controller::roundFinished, this, &Lesson::stepLesson);

    controller.dealOutCards(1, 100);

    stepLesson();
}


void Lesson7::stepLesson()
{
    //Complete the logic of the step
    if (currentStep == 0)
    {
        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "Welcome to the 7th lesson and congratulations for making it through the basic rules!\n"
                              "This section focuses on what's known as Basic Strategy which matches your current "
                              "hand to the dealers visable card to figure out the best possible play without counting.\n",
                              "Ok!");
        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "As you can see, you've already been dealt a hand with a 6 and a 8. This is what's called a \"hard total\" of 14.\n"
                              "The reason it's called a hard total is because you don't have an Ace. As Aces can be worth either 1 or 11 "
                              "hands with them are called soft totals. This is because while the ace is worth 11, you cannot bust and can therefore "
                              "afford to play slightly more agressively.\n"
                              "Though, please note that if you have an Ace and several other cards that are worth more than 10, your score is once "
                              "more considered a hard total. This is because the Ace is already worth 1 and cannot reduce it's value to save you from "
                              "busting",
                              "Ok!");
        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "Also, please look at the dealers hand. They currently have a 10 face up.\n"
                              "This card is called the up-card, and is important to consider when making your plays.\n"
                              "For example, when the up-card is either and 10 or an Ace, the dealer is fairly likely to have a good hand and "
                              "not have to hit. On the other hand if the dealer has a 5 or less face up they will be forced to hit as they have "
                              "at most a total score of 16.",
                              "Ok!");
        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "Go ahead a play out the rest of this hand however you feel like! We'll recovene after the round finishes",
                              "On it!");
    }
    else if (currentStep == 1)
    {
        emit displayTextPopup("Basic Strategy: Introduction to the Basic Strategy",
                              "That will be the end of this lesson. Please coninue onto the rest of the lessons by navigating to the Lessons drop down.\n"
                              "As for that last hand, the best thing to do was to hit exactly once. This is because, with a 14, any card worth less "
                              "than 8 improves your hand, and the dealer had a ten up. With a ten up, the chance of the dealer going bust is fairly "
                              "low, as first they'd have to have a face down card worth less than 7, then if they did, they'd still have to draw "
                              "some number of cards that bring their total to over 21.\n"
                              "We'll go over more hands like the last one in Lesson 8: Hard Counts.",
                              "Ok");

        completeLesson();
    }

    //Move to the next step
    currentStep++;
}

void Lesson7::completeLesson()
{

    // Remove all active connections from lesson
    disconnect(&controller, &Controller::roundFinished, this, &Lesson::stepLesson);

    //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
    emit lessonFinished();
}
