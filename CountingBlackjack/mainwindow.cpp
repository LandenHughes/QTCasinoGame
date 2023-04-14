
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(Controller& control, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , controller(control)
{
    ui->setupUi(this);
    setupUI();

    connect(&controller,
            &Controller::hitAction,
            this,
            &MainWindow::addCardToPlayArea);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCardToPlayArea(bool faceDown, int hand, int suit, int rank)
{
    if(faceDown)
    {
        //Add to dealer's hand
        if(hand == -1)
        {

        }
        //Add to player's hand
        else
        {

        }
    }
    else
    {
        //Add to dealer's hand
        if(hand == -1)
        {

        }
        //Add to player's hand
        else
        {

        }
    }
}

void MainWindow::setupUI()
{
    QPixmap cardBack(":/images/Playing_Cards/back.png");
    cardBack = cardBack.scaled(ui->drawDeck->size());
    ui->drawDeck->setPixmap(cardBack);
}


