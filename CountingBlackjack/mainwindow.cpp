
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(Controller& control, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , controller(control)
{
    ui->setupUi(this);
    setupUI();

    //Construct Lessons
    lessons[0] = new Lesson1(ui, control);
    lessons[1] = nullptr;
    lessons[2] = nullptr;

    lessons[3] = nullptr;
    lessons[4] = nullptr;
    lessons[5] = nullptr;

    lessons[6] = new Lesson7(ui, control);
    lessons[7] = nullptr;
    lessons[8] = nullptr;
    lessons[9] = nullptr;
    lessons[10] = nullptr;

    lessons[11] = new Lesson12(ui, control);
    lessons[12] = nullptr;
    lessons[13] = nullptr;
    lessons[14] = nullptr;

    //Initial Lesson Connections
    connect(lessons[0], &Lesson::displayTextPopup, this, &MainWindow::displayTextPopup);
    connect(lessons[6], &Lesson::displayTextPopup, this, &MainWindow::displayTextPopup);
    connect(lessons[11], &Lesson::displayTextPopup, this, &MainWindow::displayTextPopup);

    //Controller Signals
    connect(&control, &Controller::hitAction, this, &MainWindow::addCardToPlayArea);
    connect(&control, &Controller::initialDeal, this, &MainWindow::initialDeal);
    connect(&control, &Controller::displayCardsInPlayerArea, this, &MainWindow::displayCardsInPlayerArea);
    connect(&control, &Controller::showCard, this, &MainWindow::flipCardUp);
    connect(&control, &Controller::setChipTotal, this, &MainWindow::setPlayerChips);
    connect(&control, &Controller::roundFinished, this, &MainWindow::endRound);
    connect(&control, &Controller::setDoubleButtonEnabled, ui->doubleDownPushButton, &QWidget::setEnabled);
    connect(&control, &Controller::setSplitButtonEnabled, ui->splitPushButton, &QWidget::setEnabled);
    connect(&control, &Controller::setHitButtonEnabled, ui->hitPushButton, &QWidget::setEnabled);
    connect(&control, &Controller::setStandButtonEnabled, ui->standPushButton, &QWidget::setEnabled);
    connect(&control, &Controller::setPlayerTotal, this, &MainWindow::setPlayerTotal);
    connect(&control, &Controller::setDealerTotal, this, &MainWindow::setDealerTotal);
    connect(&control, &Controller::notifyUpdateChipView, this, &MainWindow::updateChipsOnTable);
    connect(&control, &Controller::offerInsurance, this, &MainWindow::offerInsurance);
    connect(&control, &Controller::showInsuranceButtons, this, &MainWindow::showInsuranceButtons);

    //Game Control Buttons
    connect(ui->hitPushButton, &QPushButton::clicked, &control, qOverload<>(&Controller::hit));
    connect(ui->splitPushButton, &QPushButton::clicked, &control, &Controller::split);
    connect(ui->standPushButton, &QPushButton::clicked, &control, &Controller::endTurn);
    connect(ui->dealPushButton, &QPushButton::clicked, this, &MainWindow::startRound);
    connect(ui->doubleDownPushButton, &QPushButton::clicked, &control, &Controller::doubleDown);
    connect(ui->acceptInsurancePushButton, &QPushButton::clicked, &control, &Controller::acceptInsurance);
    connect(ui->denyInsurancePushButton, &QPushButton::clicked, &control, &Controller::denyInsurance);

    //PlayMenuButtons
    connect(ui->actionStartPlay, &QAction::triggered, this, &MainWindow::initalizeGame);

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

    initalizeGame();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete lessons[0];
}

void MainWindow::displayTextPopup(QString title, QString message, QString buttonMessage)
{
    QMessageBox popup(QMessageBox::Information, title, message, QMessageBox::Ok, this);
    popup.exec();
    //popup.addButton()
}

void MainWindow::initalizeGame()
{
    //End any active lessons
    for (int var = 0; var < 15; ++var) {
        if (lessons[var] != nullptr) { lessons[var]->completeLesson(); }
    }

    //Enable/disable buttons
    ui->doubleDownPushButton->setEnabled(false);
    ui->splitPushButton->setEnabled(false);
    ui->hitPushButton->setEnabled(false);
    ui->standPushButton->setEnabled(false);

    ui->dealPushButton->setEnabled(true);
    ui->betComboBox->setEnabled(true);
    ui->handNumberComboBox->setEnabled(true);

    //Reset play area to inital state
    clearTable();

    //Initalize Default Game
    controller.initalizeGame(10000, 2);
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
    QString styleSheet = "color: white";
    ui->dealerTotalLabel->setStyleSheet(styleSheet);
    ui->labelTotalChips->setStyleSheet(styleSheet);
    ui->labelTotalChipsTitle->setStyleSheet(styleSheet);
    ui->labelBetTitle->setStyleSheet(styleSheet);
    ui->labelNumberOfHandsTitle->setStyleSheet(styleSheet);
    ui->dealerTotalLabel->setStyleSheet(styleSheet);
    ui->playerTotalLabel->setStyleSheet(styleSheet);
    ui->acceptInsurancePushButton->setVisible(false);
    ui->denyInsurancePushButton->setVisible(false);

    //Set background to tabletop image
    QPixmap table(":/images/UI_Images/blackjackTable");
    table = table.scaled(ui->backgroundImage->size());
    ui->backgroundImage->setPixmap(table);

    //Set hit button image
    QPixmap hit(":/images/UI_Images/blackjackHitButton");
    QIcon hitButtonIcon(hit);
    ui->hitPushButton->setIcon(hitButtonIcon);
    ui->hitPushButton->setIconSize(ui->hitPushButton->size());

    //Set stand button image
    QPixmap stand(":/images/UI_Images/blackjackStandButton");
    QIcon standButtonIcon(stand);
    ui->standPushButton->setIcon(standButtonIcon);
    ui->standPushButton->setIconSize(ui->standPushButton->size());

    //Set double down button image
    QPixmap doubleDown(":/images/UI_Images/blackjackDoubleDownButton");
    QIcon doubleDownButtonIcon(doubleDown);
    ui->doubleDownPushButton->setIcon(doubleDownButtonIcon);
    ui->doubleDownPushButton->setIconSize(ui->doubleDownPushButton->size());

    //Set split button image
    QPixmap split(":/images/UI_Images/blackjackSplitButton");
    QIcon splitButtonIcon(split);
    ui->splitPushButton->setIcon(splitButtonIcon);
    ui->splitPushButton->setIconSize(ui->doubleDownPushButton->size());

    //Set accept insurance button image
    QPixmap accept(":/images/UI_Images/blackjackAcceptInsuranceButton");
    QIcon acceptButtonIcon(accept);
    ui->acceptInsurancePushButton->setIcon(acceptButtonIcon);
    ui->acceptInsurancePushButton->setIconSize(ui->acceptInsurancePushButton->size());

    //Set deny insurance button image
    QPixmap deny(":/images/UI_Images/blackjackDenyInsuranceButton");
    QIcon denyButtonIcon(deny);
    ui->denyInsurancePushButton->setIcon(denyButtonIcon);
    ui->denyInsurancePushButton->setIconSize(ui->denyInsurancePushButton->size());

    //Set image for draw pile
    QPixmap cardBack(":/images/Playing_Cards/back.png");
    cardBack = cardBack.scaled(ui->drawDeck->size());
    ui->drawDeck->setPixmap(cardBack);
    //Make player and dealer hands display cards from the center of the screen
    ui->dealerArea->setAlignment(Qt::AlignHCenter);
    ui->playerArea->setAlignment(Qt::AlignHCenter);

    chipMap = QPixmap(ui->labelCurrentBet->width(), ui->labelCurrentBet->height());//set the pixmap area for the chip animation area
    qDebug() << "LabelInfo:" << ui->labelCurrentBet->width()<< " "<< ui->labelCurrentBet->width();

    chipMap.fill(Qt::transparent);
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
        int lessonNum = actionText.toInt() - 1;

        for (int var = 0; var < 15; ++var) {
            if (lessons[var] != nullptr) { lessons[var]->completeLesson(); }
        }

        if (lessons[lessonNum] != nullptr) { lessons[lessonNum]->initLesson(); }
        else { qDebug() << "Invalid lesson selected! Lesson" << lessonNum; }
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
    //TODO:
    //send a pixmap that represents the chipArea to chipPhysics for the chips to be drawn on
    controller.createChips(ui->betComboBox->currentText().toInt());
}

void MainWindow::initialDeal(QVector<Card> dealerCards, QVector<Card> playerCards, int totalChips)
{
    clearTable();

    for (int card = 0; card < 2; card++)
    {
        addCardToPlayArea(dealerCards[card], true, card == 0);
        addCardToPlayArea(playerCards[card], false, false);
    }

    setPlayerChips(totalChips);
}

void MainWindow::clearTable()
{
    clearDealerArea();
    setDealerTotal(0);
    clearPlayerArea();
    setPlayerTotal(0);

    //TODO : Reset Chip area.
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

void MainWindow::updateChipsOnTable(b2Body *chipList)
{
    //controller.doChipPhysics(&chipMap);

    QPainter painter(&chipMap);
    painter.setBrush(QColorConstants::Red);

    chipMap.fill(Qt::transparent); //This is to reset the pixMap view

    for(b2Body* currentChip = chipList; currentChip != nullptr; currentChip = currentChip->GetNext())//foreach body convery body info to something that can be drawn on a label
    {
        if(currentChip->GetType() == b2_dynamicBody && currentChip->GetFixtureList()->GetShape()->GetType() == b2Shape::e_circle)
        {
            QPointF centerPoint(currentChip->GetWorldCenter().x, currentChip->GetWorldCenter().y);
            //painter.drawEllipse(centerPoint,
                                //currentChip->GetFixtureList()->GetShape()->m_radius, currentChip->GetFixtureList()->GetShape()->m_radius);
            painter.drawImage((int)currentChip->GetPosition().x,
                              (int)currentChip->GetPosition().y - currentChip->GetFixtureList()->GetShape()->m_radius,
                              QImage(":images/UI_Images/blackjackChip"));
            //qDebug() << "Chip Coordinates x then y:" << centerPoint.x() << " " << centerPoint.y();
        }
    }

    ui->labelCurrentBet->setPixmap(chipMap);
}

void MainWindow::offerInsurance()
{
    //Make UI changes
    ui->acceptInsurancePushButton->setEnabled(true);
    ui->acceptInsurancePushButton->setVisible(true);
    ui->denyInsurancePushButton->setEnabled(true);
    ui->denyInsurancePushButton->setVisible(true);
    ui->hitPushButton->setEnabled(false);
    ui->standPushButton->setEnabled(false);
    ui->doubleDownPushButton->setEnabled(false);
    ui->splitPushButton->setEnabled(false);
}

void MainWindow::showInsuranceButtons(bool show)
{
    ui->acceptInsurancePushButton->setEnabled(show);
    ui->acceptInsurancePushButton->setVisible(show);
    ui->denyInsurancePushButton->setEnabled(show);
    ui->denyInsurancePushButton->setVisible(show);
}

//void MainWindow::acceptInsurance()
//{
//    ui->acceptInsurancePushButton->setEnabled(false);
//    ui->acceptInsurancePushButton->setVisible(false);
//    ui->denyInsurancePushButton->setEnabled(false);
//    ui->denyInsurancePushButton->setVisible(false);
//}

//void MainWindow::denyInsurance()
//{
//    ui->acceptInsurancePushButton->setEnabled(false);
//    ui->acceptInsurancePushButton->setVisible(false);
//    ui->denyInsurancePushButton->setEnabled(false);
//    ui->denyInsurancePushButton->setVisible(false);
//}

