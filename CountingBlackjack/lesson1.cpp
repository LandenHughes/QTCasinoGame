#include "lesson.h"

#include <QMessageBox>

class Lesson1 : public Lesson
{
    //public Lesson1():
    //{
    //      //initLesson();
    //      //stepLesson(); //Get the opening of the lesson.
    //}

    void initLesson()
    {
        currentStep = 0;

        //Stack the deck as needed, for this example, I'm using a 4 card deck of all aces.
        Card cards[]{Card(1, 0), Card(1, 1), Card(1, 2), Card(1, 3)};
        deckModel = DeckModel(cards, 4);
        //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
        fieldModel = FieldModel(10);

        //Disable buttons as needed at the start.  EX:
        emit controller.setSplitButtonEnabled(false);
    }


    void stepLesson()
    {
        //Complete the logic of the step

        if (currentStep == 0)
        {
            //Do stuff, for example...
            emit displayTextPopup("The lesson has begun! This is the title"
                                  ,"Nothing has been dealt yet, as I explain the basics. \n\
                                   1) Don't Lose."
                                  ,"Button Message!");
            return;
        }

        if (currentStep == 1)
        {
            //Do stuff, for example...
            emit displayTextPopup("Title again"
                                  ,"You did it, you placed a bet, good job!"
                                  ,"Click my face!");
            return;
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

        if (currentStep == 3)
        {
            //Eventually end the lesson
            completeLesson();
            return;
        }

        //Move to the next step
        currentStep++;
    }

    void completeLesson()
    {
        //Do what needs to be done to comlplete the lesson, such as displaying a window.
    }
};
