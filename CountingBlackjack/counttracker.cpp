#include "counttracker.h"

CountTracker::CountTracker(int numOfDecks): numTotalDecks(numOfDecks)
{
    numDecksRemaining = numOfDecks;
    runningCount = 0;//always starts as 0
    fillIllustrious18();
}

void CountTracker::updateRunningCount(int rank)
{
    if(rank > 1 && rank < 7)//when rank is 2-6
    {
        runningCount++;
    }

    else if(rank > 9 && rank < 12)//between 10 and 11(ace,10, and face cards)
    {
        runningCount--;
    }
    //if rank is 7-9 do nothing to running count
}

double CountTracker::getTrueCount()
{
    return runningCount/numDecksRemaining;
}

void CountTracker::deckRotated()
{
    numDecksRemaining--;
}

void CountTracker::allDecksShuffled()
{
    numDecksRemaining = numTotalDecks;
}

char CountTracker::getBestPlay(int playerCard1, int playerCard2, int dealerCard)
{
    if(illustrious18 [playerCard1 + playerCard2].empty())//the player card combination is not in the illustrious 18 - use basic strategy
        return ' ';

    if(illustrious18 [playerCard1 + playerCard2][dealerCard]
            > getTrueCount())//if the true count is less than the index in the map we want to hit
        return 'h';

    return 's';//stand otherwise
}

void CountTracker::fillIllustrious18()
{
    illustrious18[16][10] = 0;//player 16 and dealer 10
    illustrious18[15][10] = 4;
    illustrious18[20][5] = 5;//special case (duplicate)
    illustrious18[20][6] = 4;//special case (duplicate)
    illustrious18[10][10] = 4;
    illustrious18[12][3] = 2;
    illustrious18[12][2] = 3;
    illustrious18[11][11] = 1;//this is for dealer ace
    illustrious18[11][1] = 1;//dealer ace
    illustrious18[9][2] = 1;
    illustrious18[10][11] = 4;//for dealer ace
    illustrious18[10][1] = 4;//for dealer ace
    illustrious18[9][7] = 3;
    illustrious18[16][9] = 5;
    illustrious18[13][2] = -1;
    illustrious18[12][4] = 0;
    illustrious18[12][5] = -2;
    illustrious18[12][6] = -1;
    illustrious18[13][3] = 0;
}
