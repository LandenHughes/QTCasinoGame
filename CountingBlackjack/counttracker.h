#ifndef COUNTTRACKER_H
#define COUNTTRACKER_H


class CountTracker
{
private:
    int runningCount;
    int numDecksRemaining;
    const int numTotalDecks;

public:
    CountTracker(int);//this int is the number of decks

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
     * @brief deckRotated - decrements the remaining deck count with a new deck being used now
     */
    void deckRotated();

    /**
     * @brief allDecksShuffled - resets the number of remaining decks to the num of total decks
     */
    void allDecksShuffled();
};

#endif // COUNTTRACKER_H
