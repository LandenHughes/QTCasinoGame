
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(Controller& control, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , controller(control)
{
    ui->setupUi(this);
    setupUI();

    //Controller Signals
    connect(&control, &Controller::hitAction, this, &MainWindow::addCardToPlayArea);
    connect(&control, &Controller::initalDeal, this, &MainWindow::initalDeal);
    connect(&control, &Controller::focusHand, this, &MainWindow::focusHand);
    connect(&control, &Controller::showCard, this, &MainWindow::showCard);
    connect(&control, &Controller::setChipTotal, this, &MainWindow::setPlayerChips);
    connect(&control, &Controller::roundFinished, this, &MainWindow::endRound);

    //Game Control Buttons
    connect(ui->hitPushButton, &QPushButton::clicked, &control, qOverload<>(&Controller::hit));
    connect(ui->splitPushButton, &QPushButton::clicked, &control, &Controller::split);
    connect(ui->standPushButton, &QPushButton::clicked, &control, &Controller::stand);
    connect(ui->dealPushButton, &QPushButton::clicked, this, &MainWindow::startRound);
    connect(ui->acceptInsurancePushButton, &QPushButton::clicked, &control, &Controller::insurance);
    connect(ui->doubleDownPushButton, &QPushButton::clicked, &control, &Controller::doubleDown);

    //Lesson Menu Buttons
    connect(ui->actionLesson1, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson2, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson3, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson4, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson5, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson6, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson7, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson8, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson9, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson10, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson11, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson12, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson13, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson14, &QAction::triggered, this, &MainWindow::selectLesson);
    connect(ui->actionLesson15, &QAction::triggered, this, &MainWindow::selectLesson);

    //Initalize Default Game
    controller.initalizeGame(10000, 2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCardToPlayArea(int hand, int suit, int rank, bool faceDown)
{
    QLabel* newCard = new QLabel;
    if(faceDown)
    {
        //Set card image
        QPixmap cardBack(":/images/Playing_Cards/back.png");
        cardBack = cardBack.scaled(ui->drawDeck->size());
        newCard->setPixmap(cardBack);

        //Add to dealer's hand
        if(hand == -1)
        {
            ui->dealerArea->addWidget(newCard);
        }
        //Add to player's hand
        else
        {
            //TODO: Determine the correct player hand
            ui->playerArea->addWidget(newCard);
        }
    }
    else
    {
        //Build string for correct card's filename and location
        QString cardAddress = ":/images/Playing_Cards/";

        //Determine card rank
        if(rank > 1 && rank < 11) cardAddress = cardAddress + QString::number(rank) + "_of_";
        else if(rank == 1) cardAddress = cardAddress + "ace_of_";
        else if(rank == 11) cardAddress = cardAddress + "jack_of_";
        else if(rank == 12) cardAddress = cardAddress + "queen_of_";
        else if(rank == 13) cardAddress = cardAddress + "king_of_";

        //Determin card suit
        switch(suit)
        {
        case(0):
            cardAddress = cardAddress + "hearts.png";
            break;
        case(1):
            cardAddress = cardAddress + "clubs.png";
            break;
        case(2):
            cardAddress = cardAddress + "diamonds.png";
            break;
        case(3):
            cardAddress = cardAddress + "spades.png";
            break;
        }

        qDebug()<<cardAddress;
        //Set card image
        QPixmap cardImage(cardAddress);
        cardImage = cardImage.scaled(ui->drawDeck->size());
        newCard->setPixmap(cardImage);

        //Add to dealer's hand
        if(hand == -1)
        {
            ui->dealerArea->addWidget(newCard);
        }
        //Add to player's hand
        else
        {
            //TODO: Determine the correct player hand
            ui->playerArea->addWidget(newCard);
        }
    }
}

void MainWindow::removeCardFromPlayArea(int hand, int card)
{
    if (hand == -1)
        delete ui->dealerArea->takeAt(card);
    else
        delete ui->playerArea->takeAt(card);
}

void MainWindow::showCard(int hand, int cardPos, Card card)
{
    removeCardFromPlayArea(hand, cardPos);
    addCardToPlayArea(hand, card.getSuit(), card.getRank(), false);
}

void MainWindow::setPlayerChips(int chips)
{
    ui->labelTotalChips->setText(QString::number(chips));
}

void MainWindow::setupUI()
{
    //Set image for draw pile
    QPixmap cardBack(":/images/Playing_Cards/back.png");
    cardBack = cardBack.scaled(ui->drawDeck->size());
    ui->drawDeck->setPixmap(cardBack);
    //Make player and dealer hands display cards from the center of the screen
    ui->dealerArea->setAlignment(Qt::AlignHCenter);
    ui->playerArea->setAlignment(Qt::AlignHCenter);

    //TODO: FOR TESTING~REMOVE LATER
//    addCardToPlayArea(true, -1, 0, 0);
//    addCardToPlayArea(true, 0, 0, 0);
//    addCardToPlayArea(false, 0, 0, 1);
//    addCardToPlayArea(false, 0, 1, 6);
//    addCardToPlayArea(false, 0, 2, 11);
//    addCardToPlayArea(false, 0, 3, 13);
//    addCardToPlayArea(false, 0, 3, 13);
//    addCardToPlayArea(false, 0, 3, 13);
//    addCardToPlayArea(false, 0, 3, 13);
//    addCardToPlayArea(false, 0, 3, 13);
//    addCardToPlayArea(false, 0, 3, 13);
//    addCardToPlayArea(false, -1, 2, 12);
//    addCardToPlayArea(false, -1, 0, 3);
}

//Lesson Menu Slots
void MainWindow::selectLesson()
{
    //https://stackoverflow.com/questions/37938304/how-to-know-which-button-was-clicked-in-qt
    QAction* actionSender = qobject_cast<QAction*>(sender()); //Gets the button/action menu that was just selected
    QString actionText = actionSender->objectName(); //actionLesson1, actionLesson2, etc.

    if(actionText.contains("actionLesson"))
    {
        actionText.remove("actionLesson");
        int lessonNum = actionText.toInt();
        emit startLessonNumber(lessonNum);
    }
}

void MainWindow::startRound()
{
    ui->hitPushButton->setEnabled(true);
    ui->standPushButton->setEnabled(true);
    ui->splitPushButton->setEnabled(false);
    ui->doubleDownPushButton->setEnabled(false);
    ui->dealPushButton->setEnabled(false);
    ui->betComboBox->setEnabled(false);
    ui->handNumberComboBox->setEnabled(false);
    controller.dealOutCards(ui->handNumberComboBox->currentText().toInt(), ui->betComboBox->currentText().toInt());
}

void MainWindow::initalDeal(QVector<Card> dealerHand, QVector<Card> playerCards, int totalChips)
{
    clearDealerArea();
    clearPlayerArea();

    for (int card = 0; card < 2; card++)
        for (int hand = -1; hand < playerCards.size()/2; hand++)
        {
            if (hand == -1)
                addCardToPlayArea(-1, dealerHand[card].getSuit(), dealerHand[card].getRank(), card == 0);
            else
                addCardToPlayArea(hand, playerCards[2*hand + card].getSuit(), playerCards[2*hand + card].getRank(), false);
        }

    setPlayerChips(totalChips);
}

void MainWindow::clearPlayerArea()
{
    while (ui->playerArea->count() > 0)
    {
        QLayoutItem* toDelete = ui->playerArea->takeAt(0);
        delete toDelete;
    }
}

void MainWindow::clearDealerArea()
{
    while (ui->dealerArea->count() > 0)
    {
        QLayoutItem* toDelete = ui->dealerArea->takeAt(0);
        delete toDelete;
    }
}


void MainWindow::focusHand(QVector<Card> hand)
{
    clearPlayerArea();
    for (int i = 0; i < hand.size(); i++)
    {
        addCardToPlayArea(0, hand[i].getSuit(), hand[i].getRank(), false);
    }
}

void MainWindow::endRound()
{
    ui->hitPushButton->setEnabled(false);
    ui->standPushButton->setEnabled(false);
    ui->splitPushButton->setEnabled(false);
    ui->doubleDownPushButton->setEnabled(false);
    ui->dealPushButton->setEnabled(true);
    ui->betComboBox->setEnabled(true);
    ui->handNumberComboBox->setEnabled(true);
}
