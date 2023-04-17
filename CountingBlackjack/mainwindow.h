
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "controller.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(Controller& control, QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    /**
     * @brief Draws a new card on the play area
     * @param Card - the card to add
     * @param toDealerHand - True if the card will be dealt to dealer area
     * @param faceDown - True if card is to be dealt face down. False otherwise.
     */
    void addCardToPlayArea(Card card, bool toDealerHand, bool faceDown);

    /**
     * @brief Removes a card from the play area
     * @param hand - Represents the hand that a card will be added to. -1 for dealer, 0-infinity for player hands.
     * @param cardPos - The index of the card within the hand.
     */
    void removeCardFromPlayArea(bool inDealerHand, int cardPos);

    /**
     * @brief Plays inital deal animation. Assumes each hand gets 2 cards
     * @param dealerHand - The dealer's current hand
     * @param playerHands - All of the cards in all of the player's current hands. All of the first hand's cards, the the next's and so on
     * @param totalChips - The total number of chips that the player has after bets
     */
    void initalDeal(QVector<Card> dealerCards, QVector<Card> playerCards, int totalChips);

    /**
     * @brief Used to tell the view to flip over a card
     * @param hand - the hand in which to flip the card. -1 for dealer, 0-infinity for player hands.
     * @param card - the card to flip.
     */
    void flipCardUp(Card card, int inDealerHand, int cardPos);

    /**
     * @brief Pulls up given hand to act on
     * @param hand - the hand to focus. Note: only works for player hands, -1 in will result in an execption
     */
    void displayCardsInPlayerArea(QVector<Card> hand);

    /**
     * @brief Set the players chips to the given value
     * @param The value to display
     */
    void setPlayerChips(int playerChips);

    /**
     * @brief Helper function which handles initial setup of all visual elements.
     */
    void setupUI();

    /**
     * @brief Takes the menu action just pressed and emits a signal with the lesson number
     */
    void selectLesson();

    /**
     * @brief Tells the controller to deal out cards and passes bet amount to controller.
     */
    void startRound();

    /**
     * @brief Clears ui->dealerArea
     */
    void clearDealerArea();

    /**
     * @brief Clears ui->playerArea
     */
    void clearPlayerArea();

    /**
     * @brief Called when a round finishes.
     */
    void endRound();

signals:
    void startLessonNumber(int lessonNum);

private:
    Ui::MainWindow *ui;
    Controller& controller;
};

#endif // MAINWINDOW_H
