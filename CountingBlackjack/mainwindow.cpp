
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
    connect(&control, &Controller::displayCardsInPlayerArea, this, &MainWindow::displayCardsInPlayerArea);
    connect(&control, &Controller::showCard, this, &MainWindow::flipCardUp);
    connect(&control, &Controller::setChipTotal, this, &MainWindow::setPlayerChips);
    connect(&control, &Controller::roundFinished, this, &MainWindow::endRound);
    connect(&control, &Controller::setDoubleButtonEnabled, ui->doubleDownPushButton, &QWidget::setEnabled);
    connect(&control, &Controller::setSplitButtonEnabled, ui->splitPushButton, &QWidget::setEnabled);
    connect(&control, &Controller::setHitButtonEnabled, ui->hitPushButton, &QWidget::setEnabled);
    connect(&control, &Controller::setPlayerTotal, this, &MainWindow::setPlayerTotal);
    connect(&control, &Controller::setDealerTotal, this, &MainWindow::setDealerTotal);

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

void MainWindow::addCardToPlayArea(Card card, bool toDealerArea, bool faceDown)
{
    QLabel* newCard = new QLabel;
    if(faceDown)
    {
        //Set card image
        QPixmap cardBack(":/images/Playing_Cards/back.png");
        cardBack = cardBack.scaled(ui->drawDeck->size());
        newCard->setPixmap(cardBack);

        //Add to dealer's hand
        if(toDealerArea)
        {
            ui->dealerArea->addWidget(newCard);
        }
        //Add to player's hand ~ technically impossible during game
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
        int rank = card.getRank();
        if(rank > 1 && rank < 11) cardAddress = cardAddress + QString::number(rank) + "_of_";
        else if(rank == 1) cardAddress = cardAddress + "ace_of_";
        else if(rank == 11) cardAddress = cardAddress + "jack_of_";
        else if(rank == 12) cardAddress = cardAddress + "queen_of_";
        else if(rank == 13) cardAddress = cardAddress + "king_of_";

        //Determin card suit
        switch(card.getSuit())
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
        if(toDealerArea)
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

void MainWindow::removeCardFromPlayArea(bool inDealerHand, int cardPos)
{
    if (inDealerHand)
    {
        QLayoutItem* item = ui->dealerArea->takeAt(cardPos);
        delete item->widget();
        delete item;
    }
    else
    {
        QLayoutItem* item = ui->playerArea->takeAt(cardPos);
        delete item->widget();
        delete item;
    }
}

void MainWindow::flipCardUp(Card card, int inDealerHand, int cardPos)
{
    removeCardFromPlayArea(inDealerHand, cardPos);
    addCardToPlayArea(card, inDealerHand, false);
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

void MainWindow::initalDeal(QVector<Card> dealerCards, QVector<Card> playerCards, int totalChips)
{
    clearDealerArea();
    clearPlayerArea();

    for (int card = 0; card < 2; card++)
    {
        addCardToPlayArea(dealerCards[card], true, card == 0);
        addCardToPlayArea(playerCards[card], false, false);
    }

    setPlayerChips(totalChips);
}

void MainWindow::clearPlayerArea()
{
    while (ui->playerArea->count() > 0)
    {
        QLayoutItem* toDelete = ui->playerArea->takeAt(0);
        delete toDelete->widget();
        delete toDelete;
    }
}

void MainWindow::clearDealerArea()
{
    while (ui->dealerArea->count() > 0)
    {
        QLayoutItem* toDelete = ui->dealerArea->takeAt(0);
        delete toDelete->widget();
        delete toDelete;
    }
}


void MainWindow::displayCardsInPlayerArea(QVector<Card> hand)
{
    clearPlayerArea();
    for (int i = 0; i < hand.size(); i++)
    {
        addCardToPlayArea(hand[i], false, false);
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

void MainWindow::setPlayerTotal(int newTotal)
{
    QString newTotalMessage = "Player Total: " + QString::number(newTotal);
    qDebug() << newTotal << " " << newTotalMessage;
    ui->playerTotalLabel->setText(newTotalMessage);
}

void MainWindow::setDealerTotal(int newDTotal)
{
    QString newTotalMessage = "Known Dealer Total: " + QString::number(newDTotal);
    qDebug() << newDTotal << " " << newTotalMessage;
    ui->dealerTotalLabel->setText(newTotalMessage);
}
