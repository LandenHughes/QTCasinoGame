#include "counttracker.h"

CountTracker::CountTracker(int numOfDecks): numTotalDecks(numOfDecks)
{
    numDecksRemaining = numOfDecks;
    runningCount = 0;//always starts as 0
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

double CountTracker::getTrueCount(){
    return runningCount/numDecksRemaining;
}

void CountTracker::deckRotated(){
    numDecksRemaining--;
}

void CountTracker::allDecksShuffled(){
    numDecksRemaining = numTotalDecks;
}
