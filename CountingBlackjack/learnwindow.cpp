/**
 * @class LearnWindow
 * @file learnwindow.cpp
 * @brief - UI portion for the learn window where the user will learn how to play and count cards
 * in blackjack.
 *
 */

#include "learnwindow.h"
#include "ui_learnwindow.h"
#include <QWidget>

LearnWindow::LearnWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LearnWindow)
{
    ui->setupUi(this);

    //Connections to other UI
    connect(ui->mainPushButton, &QPushButton::clicked, this, &LearnWindow::mainWindowButtonClick);
    connect(ui->playPushButton, &QPushButton::clicked, this, &LearnWindow::playWindowButtonClick);

    //Signal Catching
    //    connect(&mainWindowUI, &MainWindow::switchToLearnWindow, this, &LearnWindow::setupLearnUI);
    //    connect(&playWindowUI, &PlayWindow::switchToLearnWindow, this, &LearnWindow::setupLearnUI);
}

LearnWindow::~LearnWindow()
{
    delete ui;
}

void LearnWindow::setupLearnUI()
{

}

void LearnWindow::mainWindowButtonClick()
{
    emit switchToMainWindow();
}

void LearnWindow::playWindowButtonClick()
{
    emit switchToPlayWindow();
}
