
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

    connect(&control, &Controller::hitAction, this, &MainWindow::addCardToPlayArea);

    //Game Control Buttons
    connect(ui->hitPushButton, &QPushButton::clicked, &control, qOverload<>(&Controller::hit));
    connect(ui->splitPushButton, &QPushButton::clicked, &control, &Controller::split);
    connect(ui->standPushButton, &QPushButton::clicked, &control, &Controller::stand);
    connect(ui->dealPushButton, &QPushButton::clicked, this, &MainWindow::startRound);
    connect(ui->insurancePushButton, &QPushButton::clicked, &control, &Controller::insurance);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCardToPlayArea(bool faceDown, int hand, int suit, int rank)
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
    ui->doubleDownPushButton->setEnabled(true);
    ui->dealPushButton->setEnabled(false);
    ui->betComboBox->setEnabled(false);
    ui->handNumberComboBox->setEnabled(false);
    controller.setBet(ui->betComboBox->currentText().toInt());
    controller.dealOutCards();
}
