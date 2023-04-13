#ifndef COUNTTRACKER_H
#define COUNTTRACKER_H

#include <map>

class CountTracker
{
private:
    int runningCount;
    int numDecksRemaining;
    const int numTotalDecks;
    std::map<int, std::map<int, int> > illustrious18;//outter map key is players total
    //inner map is the dealers up-card with an assigned index to be compared to the true count

public:
    CountTracker(int);//this int is the number of decks

    /**
     * @brief fillIllustrious18 - assigns index for all of the combinations in the illustrious 18
     */
    void fillIllustrious18();
    /**
     * @brief updateRunningCount - int represents the rank of the delt card
     * the running count is updated everytime a new card is delt
     */
    void updateRunningCount(int);

    /**
     * @brief getTrueCount - calculated by dividing the running count by the number of decks remaining
     * @return the true count
     */
    double getTrueCount();

    /**
     * @brief getBestPlay - gets index from illustrious18 and if the truecount is less than the index hit, stand otherwise
     * first 2 ints are player hand, third int is dealers up-card
     * @return char of best play (s-stand, h-hit, return empty char if the current hand is not in the illustrious 18)
     */
    char getBestPlay(int,int,int);

    /**
     * @brief deckRotated - decrements the remaining deck count with a new deck being used now
     */
    void deckRotated();

    /**
     * @brief allDecksShuffled - resets the number of remaining decks to the num of total decks
     */
    void allDecksShuffled();
};

#endif // COUNTTRACKER_H
