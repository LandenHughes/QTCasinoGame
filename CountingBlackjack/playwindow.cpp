/**
 * @class PlayWindow
 * @file playwindow.h
 * @brief - UI for the Play window where the user will be able to play
 * blackjack without being in the learning mode.
 *
 */

#include "playwindow.h"
#include "ui_playwindow.h"

PlayWindow::PlayWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PlayWindow)
{
    ui->setupUi(this);

    //Connections to other UI
    connect(ui->mainPushButton, &QPushButton::clicked, this, &PlayWindow::mainWindowButtonClick);
    connect(ui->learnPushButton, &QPushButton::clicked, this, &PlayWindow::learnWindowButtonClick);

    //Signal Catching
    //    connect(&mainWindowUI, &MainWindow::switchToLearnWindow, this, &PlayWindow::setupPlayUI);
    //    connect(&learnWindowUI, &LearnWindow::switchToLearnWindow, this, &PlayWindow::setupPlayUI);
}

PlayWindow::~PlayWindow()
{
    delete ui;
}

void PlayWindow::setupPlayUI()
{

}

void PlayWindow::mainWindowButtonClick()
{
    emit switchToMainWindow();
}

void PlayWindow::learnWindowButtonClick()
{
    emit switchToLearnWindow();
}
