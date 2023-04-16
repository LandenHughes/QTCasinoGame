//This class is the model for the field, or the currently visible playable area.
//It includes...
//Chip totals
//Hands for the round
//Dealer
//dealers hidden card

#include "fieldmodel.h"
#include "deckmodel.h"

FieldModel::FieldModel(int chips) :
    playerChips(chips)
{ }

QVector<Hand> FieldModel::getPlayerHands()
{
    return playerHands;
}

QVector<Card> FieldModel::dealDealerHand(DeckModel& deck)
{
    dealerHand.clear();
    dealerHand.append(deck.dealCard());
    dealerHand.append(deck.dealCard());
    return dealerHand;
}

QVector<Card> FieldModel::dealPlayerHand(DeckModel& deck, int bet)
{
    QVector<Card> hand;
    hand.append(deck.dealCard());
    hand.append(deck.dealCard());
    playerHands.append(Hand(hand, bet));

    playerChips -= bet;

    return hand;
}

Hand& FieldModel::getPlayerHand(int handIndex)
{
    return playerHands[handIndex];
}

Card FieldModel::getDealerHiddenCard(){
    return dealerHand.front();
}

int FieldModel::splitHand(int handIndex)
{
    //Assumes the hand is valid
    playerHands.push_back(playerHands[handIndex].split());
    return playerHands.size()-1;
}

int FieldModel::insurePlayer()
{
    //TODO
    return 0;
}

int FieldModel::getDealerScore()
{
    int scoreTotal = 0;
    int acesTotal = 0;
    for (int i = 0; i < dealerHand.size(); i++)
    {
        Card card = dealerHand.at(i);
        if (card.getRank() >= 10)
            scoreTotal += 10;
        else
            scoreTotal += card.getRank();

        if (card.getRank() == 1)
            acesTotal++;
    }

    //Add aces bonus for 1 or 11
    while (scoreTotal <= 11 && acesTotal > 0)
    {
        scoreTotal += 10;
        acesTotal--;
    }

    return scoreTotal;
}

int FieldModel::getPlayerChips()
{
    return playerChips;
}

bool FieldModel::isDealerCardHidden()
{
    return dealerHand.size() <= 2 && getDealerScore() != 21;
}

bool FieldModel::isDealerHandBlackjack()
{
    return dealerHand.size() == 2 && getDealerScore() == 21;
}


void FieldModel::addToHand(int currentHand, Card card)
{
    if (currentHand == -1)
        dealerHand.append(card);
    else
        playerHands[currentHand].addCard(card);
}

void FieldModel::endRound()
{
    foreach (Hand hand, playerHands) {
        if (hand.getScore() > 21)
            continue;
        else if (hand.getScore() == getDealerScore())
            playerChips += hand.getBet();
        else if (hand.isBlackjack())
            playerChips += 2.5*hand.getBet();
        else if (getDealerScore() > 21 || hand.getScore() > getDealerScore())
            playerChips += 2*hand.getBet();
    }

    //Clear all variables to a 0 state (except chips)
    playerHands.clear();
    dealerHand.clear();
}
