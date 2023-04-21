#include "lesson.h"

#include <QMessageBox>

class Lesson1 : public Lesson
{
    //public Lesson()
    //{
    //      //MAKE CONTROLLER SAME AS THE MAINWINDOW'S CONTROLLER, OR THIS WILL BREAK!!! (Emits won't be connected properly!)
    //      //initLesson();
    //      //stepLesson(); //Get the opening of the lesson.
    //}

    void initLesson()
    {
        currentStep = 0;

        //Stack the deck as needed.  Remember cards are dealt player, dealer, player , dealer in 1 hand rounds.
        Card cards[]{Card(10, 0), Card(7, 1), Card(11, 2), Card(10, 3), Card(7, 0), Card(13, 0), Card(3, 2), Card(8, 1), Card(1, 3), Card(1,2)};
        deckModel = DeckModel(cards, 10);
        //For this lesson, I want the field model to have 10 chips to start.  This is needed to clear the board at the start.
        fieldModel = FieldModel(10);
        //TODO: Disable changing bets and hand size, set both to minimum values.
    }


    void stepLesson()
    {
        //Complete the logic of the step
        if (currentStep == 0)
        {
            //On opening the lesson...
            emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                                  ,"Welcome to BlackJack!\n"
                                   "This is the first lesson, which will teach you about the basics of the game, as well as how to win!\n"
                                   "To start, just hit the deal button."
                                  ,"Got it!");
            return;
        }

        if (currentStep == 1)
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
                                   "Face cards (J, Q, K) count as 10, so your hand has a total of 20 right now.  Not bad!"
                                  ,"Continue");
            emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                                  ,"You can hit to get another card, since you aren't at 21, but since you would need an Ace (1) to do that, you'll probably bust and lose."
                                   "Just click stay for now, and see what the dealer has."
                                  ,"Easy Peasy");

            return;
        }

        if (currentStep == 2)
        {
            //Player hits stand, dealer takes turn...

            emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                                  ,"After standing, your turn ends, and it becomes the dealers turn.\n"
                                   "We'll go over what the dealer does in their turn later, but for now just know they reveal their hidden card at the start.\n"
                                  ,"Continue");
            emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                                  ,"The dealer got a 17, which is less than a 20, so you win!\n"
                                   "Congratulations!  Since you put in 10 chips, the payout is 20 chips, this is known as a 3:2 payout.\n"
                                   "Deal out another hand!"
                                  ,"Onto the next hand!");

            return;
        }

        if (currentStep == 3)
        {
            //Second hand is dealt...

            emit controller.setStandButtonEnabled(false);
            emit controller.setSplitButtonEnabled(false);
            emit controller.setDoubleButtonEnabled(false);

            emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                                  ,"The dealer' got's hand has a score of 18, so you win!\n"
                                   "This was the basics of hitting, standing, and card values!\n"
                                   "Remember, the basic idea is to get as close to 21 as you can, without going over!\n\n"
                                   "To continue, activate Section 1 lesson 2 from the lessons menu..."
                                  ,"Hit me!");
            emit controller.setHitButtonEnabled(true);

            return;
        }

        if (currentStep == 4)
        {
            //Player hits, gets an Ace...

            emit controller.setHitButtonEnabled(false);

            emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                                  ,"You got an Ace!\n"
                                   "Aces have the neat property as being able to be treated as a 1 or an 11, depending on which one would make you have a bigger hand!\n"
                                   "Right now, the ace is treated as an 11, since that would bring you to 21!\n"
                                   "Since you have 21, just stay for now!  You can't get a better hand than this!"
                                  ,"Perfect!");

            return;
        }
        if (currentStep == 5)
        {
            //Player stands...

            emit displayTextPopup("Basic Rules: Card Values Hitting, and Busting"
                                  ,"You got an Ace!\n"
                                   "Aces have the neat property as being able to be treated as a 1 or an 11, depending on which one would make you have a bigger hand!\n"
                                   "Right now, the ace is treated as an 11, since that would bring you to 21!\n"
                                   "Since you have 21, just stay for now!  You can't get a better hand than this!"
                                  ,"Perfect!");

            completeLesson();

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

        //Move to the next step
        currentStep++;
    }

    void completeLesson()
    {
        //Do what needs to be done to comlplete the lesson, such as displaying a window and reenabling diabled buttons.
        emit lessonFinished();
    }
};
