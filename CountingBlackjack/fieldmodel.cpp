//This class is the model for the field, or the currently visible playable area.
//It includes...
//Chip totals
//Hands for the round
//Dealer
//dealers hidden card

#include "fieldmodel.h"
#include "deckmodel.h"
#include <QDebug>

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

    playerWin = false;
    isWinBlackjack = false;
    return hand;
}

Hand FieldModel::getPlayerHand(int handIndex)
{
    return playerHands[handIndex];
}

Card FieldModel::getDealerHiddenCard(){
    return dealerHand.front();
}

int FieldModel::splitHand(DeckModel& deck, int handIndex)
{
    //Assumes the hand is valid
    //Pay for split
    playerChips -= playerHands[handIndex].getBet();

    //Adds new hand to the end of playerHands
    playerHands.push_back(playerHands[handIndex].split());

    //Deals cards to both hands.
    int newHandIndex = playerHands.size()-1;
    dealToHand(deck, handIndex);
    dealToHand(deck, newHandIndex);

    return newHandIndex;
}

void FieldModel::insureHand(int hand)
{
    playerHands[hand].insure();
    playerChips -=  playerHands[hand].getBet() / 2;
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

void FieldModel::setPlayerChips(int newChipAmount)
{
    playerChips = newChipAmount;
}

bool FieldModel::isDealerCardHidden()
{
    return dealerHand.size() <= 2 && getDealerScore() != 21;
}

bool FieldModel::isDealerHandBlackjack()
{
    return dealerHand.size() == 2 && getDealerScore() == 21;
}

bool FieldModel::canOfferInsurance(int hand)
{
    return dealerHand[1].getRank() == 1
           && playerChips >= getPlayerHand(hand).getBet() / 2
           && getPlayerHand(hand).getScore() < 22;
}

Card FieldModel::doubleDownHand(DeckModel& deck, int handIndex)
{
    playerChips -= playerHands[handIndex].getBet();
    playerHands[handIndex].doubleDown();
    return dealToHand(deck, handIndex);
}

Card FieldModel::dealToHand(DeckModel& deck, int handIndex)
{
    Card card = deck.dealCard();
    if (handIndex == -1)
        dealerHand.append(card);
    else
        playerHands[handIndex].addCard(card);
    return card;
}

void FieldModel::endRound()
{
    foreach (Hand hand, playerHands) {
        if (hand.getScore() > 21)
            continue;
        else if (dealerHand.length() == 2
                 && getDealerScore() == 21
                 && hand.isInsured())
        {
            playerChips += hand.getBet() * 1.5;
            playerWin = true;
            isWinBlackjack = false;
            continue;
        }
        else if (hand.getScore() == getDealerScore())
        {
            playerChips += hand.getBet();
            playerWin = false;
            isWinBlackjack = false;
            continue;
        }
        else if (hand.isBlackjack())
        {
            playerChips += 2.5*hand.getBet();
            playerWin = true;
            isWinBlackjack = true;
        }
        else if (getDealerScore() > 21 || hand.getScore() > getDealerScore())
        {
            playerChips += 2*hand.getBet();
            playerWin = true;
            isWinBlackjack = false;
        }
    }

    //Clear all variables to a 0 state (except chips)
    playerHands.clear();
    dealerHand.clear();
}
