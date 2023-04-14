
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
     * @param faceDown - True if card is to be dealt face down. False otherwise.
     * @param hand - Represents the hand that a card will be added to. -1 for dealer, 0-infinity for player hands.
     * @param suit - Represents the suit of the card given: 0-Heart, 1-Club, 2-Diamond, 3-Spade.
     * @param rank - Rank of the card: 1 is A, 11 is J, 12 is Q, 13 is K.  0 is Joker, but blackjack isn't palyed with Jokers.
     */
    void addCardToPlayArea(bool faceDown, int hand, int suit, int rank);

    /**
     * @brief Helper function which handles initial setup of all visual elements.
     */
    void setupUI();

    /**
     * @brief Takes the menu action just pressed and emits a signal with the lesson number
     */
    void selectLesson();

signals:
    void startLessonNumber(int lessonNum);

private:
    Ui::MainWindow *ui;
    Controller& controller;
};

#endif // MAINWINDOW_H
