/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSection_1;
    QAction *actionSections;
    QAction *actionhelp;
    QAction *actionLesson1;
    QAction *actionLesson2;
    QAction *actionLesson3;
    QAction *actionStartPlay;
    QAction *actionLesson4;
    QAction *actionLesson5;
    QAction *actionLesson6;
    QAction *actionLesson7;
    QAction *actionLesson8;
    QAction *actionLesson9;
    QAction *actionLesson10;
    QAction *actionLesson11;
    QAction *actionLesson12;
    QAction *actionLesson13;
    QAction *actionLesson14;
    QAction *actionLesson15;
    QWidget *centralwidget;
    QLabel *drawDeck;
    QLabel *discardDeck;
    QLabel *label_5;
    QLabel *labelCurrentBet;
    QLabel *label_8;
    QPushButton *splitPushButton;
    QPushButton *hitPushButton;
    QPushButton *standPushButton;
    QPushButton *doubleDownPushButton;
    QPushButton *acceptInsurancePushButton;
    QPushButton *dealPushButton;
    QPushButton *denyInsurancePushButton;
    QComboBox *betComboBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *dealerArea;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *playerArea;
    QLabel *label_9;
    QComboBox *handNumberComboBox;
    QLabel *labelTotalChips;
    QLabel *dealerTotalLabel;
    QLabel *playerTotalLabel;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuPlay;
    QMenu *menuHelp;
    QMenu *menuLessons;
    QMenu *menuSection1;
    QMenu *menuSection_2_Advanced_Rules;
    QMenu *menuSection_3_Basic_Strategy;
    QMenu *menuSection_4_Card_Counting;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionSection_1 = new QAction(MainWindow);
        actionSection_1->setObjectName("actionSection_1");
        actionSections = new QAction(MainWindow);
        actionSections->setObjectName("actionSections");
        actionhelp = new QAction(MainWindow);
        actionhelp->setObjectName("actionhelp");
        actionLesson1 = new QAction(MainWindow);
        actionLesson1->setObjectName("actionLesson1");
        actionLesson2 = new QAction(MainWindow);
        actionLesson2->setObjectName("actionLesson2");
        actionLesson3 = new QAction(MainWindow);
        actionLesson3->setObjectName("actionLesson3");
        actionStartPlay = new QAction(MainWindow);
        actionStartPlay->setObjectName("actionStartPlay");
        actionLesson4 = new QAction(MainWindow);
        actionLesson4->setObjectName("actionLesson4");
        actionLesson5 = new QAction(MainWindow);
        actionLesson5->setObjectName("actionLesson5");
        actionLesson6 = new QAction(MainWindow);
        actionLesson6->setObjectName("actionLesson6");
        actionLesson7 = new QAction(MainWindow);
        actionLesson7->setObjectName("actionLesson7");
        actionLesson8 = new QAction(MainWindow);
        actionLesson8->setObjectName("actionLesson8");
        actionLesson9 = new QAction(MainWindow);
        actionLesson9->setObjectName("actionLesson9");
        actionLesson10 = new QAction(MainWindow);
        actionLesson10->setObjectName("actionLesson10");
        actionLesson11 = new QAction(MainWindow);
        actionLesson11->setObjectName("actionLesson11");
        actionLesson12 = new QAction(MainWindow);
        actionLesson12->setObjectName("actionLesson12");
        actionLesson13 = new QAction(MainWindow);
        actionLesson13->setObjectName("actionLesson13");
        actionLesson14 = new QAction(MainWindow);
        actionLesson14->setObjectName("actionLesson14");
        actionLesson15 = new QAction(MainWindow);
        actionLesson15->setObjectName("actionLesson15");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        drawDeck = new QLabel(centralwidget);
        drawDeck->setObjectName("drawDeck");
        drawDeck->setGeometry(QRect(10, 100, 100, 140));
        drawDeck->setFrameShape(QFrame::Box);
        discardDeck = new QLabel(centralwidget);
        discardDeck->setObjectName("discardDeck");
        discardDeck->setGeometry(QRect(690, 100, 100, 140));
        discardDeck->setFrameShape(QFrame::Box);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(350, 280, 121, 31));
        QFont font;
        font.setPointSize(14);
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        labelCurrentBet = new QLabel(centralwidget);
        labelCurrentBet->setObjectName("labelCurrentBet");
        labelCurrentBet->setGeometry(QRect(690, 250, 101, 261));
        labelCurrentBet->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 370, 81, 16));
        label_8->setAlignment(Qt::AlignCenter);
        splitPushButton = new QPushButton(centralwidget);
        splitPushButton->setObjectName("splitPushButton");
        splitPushButton->setEnabled(false);
        splitPushButton->setGeometry(QRect(470, 330, 80, 24));
        hitPushButton = new QPushButton(centralwidget);
        hitPushButton->setObjectName("hitPushButton");
        hitPushButton->setEnabled(false);
        hitPushButton->setGeometry(QRect(159, 330, 101, 24));
        standPushButton = new QPushButton(centralwidget);
        standPushButton->setObjectName("standPushButton");
        standPushButton->setEnabled(false);
        standPushButton->setGeometry(QRect(270, 330, 80, 24));
        doubleDownPushButton = new QPushButton(centralwidget);
        doubleDownPushButton->setObjectName("doubleDownPushButton");
        doubleDownPushButton->setEnabled(false);
        doubleDownPushButton->setGeometry(QRect(560, 330, 111, 24));
        acceptInsurancePushButton = new QPushButton(centralwidget);
        acceptInsurancePushButton->setObjectName("acceptInsurancePushButton");
        acceptInsurancePushButton->setEnabled(false);
        acceptInsurancePushButton->setGeometry(QRect(510, 300, 161, 24));
        dealPushButton = new QPushButton(centralwidget);
        dealPushButton->setObjectName("dealPushButton");
        dealPushButton->setGeometry(QRect(20, 490, 80, 24));
        denyInsurancePushButton = new QPushButton(centralwidget);
        denyInsurancePushButton->setObjectName("denyInsurancePushButton");
        denyInsurancePushButton->setEnabled(false);
        denyInsurancePushButton->setGeometry(QRect(159, 300, 151, 24));
        betComboBox = new QComboBox(centralwidget);
        betComboBox->addItem(QString());
        betComboBox->addItem(QString());
        betComboBox->addItem(QString());
        betComboBox->addItem(QString());
        betComboBox->addItem(QString());
        betComboBox->addItem(QString());
        betComboBox->setObjectName("betComboBox");
        betComboBox->setGeometry(QRect(20, 390, 81, 24));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(120, 100, 561, 141));
        dealerArea = new QHBoxLayout(horizontalLayoutWidget);
        dealerArea->setObjectName("dealerArea");
        dealerArea->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(120, 370, 561, 141));
        playerArea = new QHBoxLayout(horizontalLayoutWidget_2);
        playerArea->setObjectName("playerArea");
        playerArea->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 430, 101, 20));
        label_9->setAlignment(Qt::AlignCenter);
        handNumberComboBox = new QComboBox(centralwidget);
        handNumberComboBox->addItem(QString());
        handNumberComboBox->addItem(QString());
        handNumberComboBox->addItem(QString());
        handNumberComboBox->addItem(QString());
        handNumberComboBox->addItem(QString());
        handNumberComboBox->setObjectName("handNumberComboBox");
        handNumberComboBox->setGeometry(QRect(20, 450, 81, 24));
        labelTotalChips = new QLabel(centralwidget);
        labelTotalChips->setObjectName("labelTotalChips");
        labelTotalChips->setGeometry(QRect(360, 310, 101, 21));
        labelTotalChips->setFont(font);
        labelTotalChips->setAlignment(Qt::AlignCenter);
        dealerTotalLabel = new QLabel(centralwidget);
        dealerTotalLabel->setObjectName("dealerTotalLabel");
        dealerTotalLabel->setGeometry(QRect(230, 70, 351, 21));
        dealerTotalLabel->setFont(font);
        dealerTotalLabel->setAlignment(Qt::AlignCenter);
        playerTotalLabel = new QLabel(centralwidget);
        playerTotalLabel->setObjectName("playerTotalLabel");
        playerTotalLabel->setGeometry(QRect(290, 520, 231, 21));
        playerTotalLabel->setFont(font);
        playerTotalLabel->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuPlay = new QMenu(menubar);
        menuPlay->setObjectName("menuPlay");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuLessons = new QMenu(menubar);
        menuLessons->setObjectName("menuLessons");
        menuSection1 = new QMenu(menuLessons);
        menuSection1->setObjectName("menuSection1");
        menuSection_2_Advanced_Rules = new QMenu(menuLessons);
        menuSection_2_Advanced_Rules->setObjectName("menuSection_2_Advanced_Rules");
        menuSection_3_Basic_Strategy = new QMenu(menuLessons);
        menuSection_3_Basic_Strategy->setObjectName("menuSection_3_Basic_Strategy");
        menuSection_4_Card_Counting = new QMenu(menuLessons);
        menuSection_4_Card_Counting->setObjectName("menuSection_4_Card_Counting");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuPlay->menuAction());
        menubar->addAction(menuLessons->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuPlay->addAction(actionStartPlay);
        menuLessons->addAction(menuSection1->menuAction());
        menuLessons->addAction(menuSection_2_Advanced_Rules->menuAction());
        menuLessons->addAction(menuSection_3_Basic_Strategy->menuAction());
        menuLessons->addAction(menuSection_4_Card_Counting->menuAction());
        menuSection1->addAction(actionLesson1);
        menuSection1->addAction(actionLesson2);
        menuSection1->addAction(actionLesson3);
        menuSection_2_Advanced_Rules->addAction(actionLesson4);
        menuSection_2_Advanced_Rules->addAction(actionLesson5);
        menuSection_2_Advanced_Rules->addAction(actionLesson6);
        menuSection_3_Basic_Strategy->addAction(actionLesson7);
        menuSection_3_Basic_Strategy->addAction(actionLesson8);
        menuSection_3_Basic_Strategy->addAction(actionLesson9);
        menuSection_3_Basic_Strategy->addAction(actionLesson10);
        menuSection_3_Basic_Strategy->addAction(actionLesson11);
        menuSection_4_Card_Counting->addAction(actionLesson12);
        menuSection_4_Card_Counting->addAction(actionLesson13);
        menuSection_4_Card_Counting->addAction(actionLesson14);
        menuSection_4_Card_Counting->addAction(actionLesson15);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSection_1->setText(QCoreApplication::translate("MainWindow", "Section 1", nullptr));
        actionSections->setText(QCoreApplication::translate("MainWindow", "Sections", nullptr));
        actionhelp->setText(QCoreApplication::translate("MainWindow", "help", nullptr));
        actionLesson1->setText(QCoreApplication::translate("MainWindow", "Lesson 1: Card Values, Hitting and Busting", nullptr));
        actionLesson2->setText(QCoreApplication::translate("MainWindow", "Lesson 2: Betting, Order of Play, and Dealer's Play", nullptr));
        actionLesson3->setText(QCoreApplication::translate("MainWindow", "Lesson 3: Blackjack!", nullptr));
        actionStartPlay->setText(QCoreApplication::translate("MainWindow", "Start Play Mode", nullptr));
        actionLesson4->setText(QCoreApplication::translate("MainWindow", "Lesson 4: Splitting", nullptr));
        actionLesson5->setText(QCoreApplication::translate("MainWindow", "Lesson 5: Doubling Down", nullptr));
        actionLesson6->setText(QCoreApplication::translate("MainWindow", "Lesson 6: Insurance", nullptr));
        actionLesson7->setText(QCoreApplication::translate("MainWindow", "Lesson 7: Introduction to Basic Strategy", nullptr));
        actionLesson8->setText(QCoreApplication::translate("MainWindow", "Lesson 8: Hard Counts", nullptr));
        actionLesson9->setText(QCoreApplication::translate("MainWindow", "Lesson 9: Soft Counts", nullptr));
        actionLesson10->setText(QCoreApplication::translate("MainWindow", "Lesson 10: When to Double Down", nullptr));
        actionLesson11->setText(QCoreApplication::translate("MainWindow", "Lesson 11: When to Split", nullptr));
        actionLesson12->setText(QCoreApplication::translate("MainWindow", "Lesson 12: Counting Cards and the Running Count", nullptr));
        actionLesson13->setText(QCoreApplication::translate("MainWindow", "Lesson 13: Running Count Vs. True Count", nullptr));
        actionLesson14->setText(QCoreApplication::translate("MainWindow", "Lesson 14: Bet Spreads", nullptr));
        actionLesson15->setText(QCoreApplication::translate("MainWindow", "Lesson 15: The Illustrious 18", nullptr));
        drawDeck->setText(QCoreApplication::translate("MainWindow", "Deck", nullptr));
        discardDeck->setText(QCoreApplication::translate("MainWindow", "Discard", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Total Chips", nullptr));
        labelCurrentBet->setText(QCoreApplication::translate("MainWindow", "Chips Area", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Bet", nullptr));
        splitPushButton->setText(QCoreApplication::translate("MainWindow", "SPLIT", nullptr));
        hitPushButton->setText(QCoreApplication::translate("MainWindow", "HIT", nullptr));
        standPushButton->setText(QCoreApplication::translate("MainWindow", "STAND", nullptr));
        doubleDownPushButton->setText(QCoreApplication::translate("MainWindow", "DOUBLE", nullptr));
        acceptInsurancePushButton->setText(QCoreApplication::translate("MainWindow", "ACCEPT INSURANCE", nullptr));
        dealPushButton->setText(QCoreApplication::translate("MainWindow", "DEAL", nullptr));
        denyInsurancePushButton->setText(QCoreApplication::translate("MainWindow", "DENY INSURANCE", nullptr));
        betComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        betComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "20", nullptr));
        betComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "30", nullptr));
        betComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "40", nullptr));
        betComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "50", nullptr));
        betComboBox->setItemText(5, QCoreApplication::translate("MainWindow", "100", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", "Number of hands", nullptr));
        handNumberComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        handNumberComboBox->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));
        handNumberComboBox->setItemText(2, QCoreApplication::translate("MainWindow", "3", nullptr));
        handNumberComboBox->setItemText(3, QCoreApplication::translate("MainWindow", "4", nullptr));
        handNumberComboBox->setItemText(4, QCoreApplication::translate("MainWindow", "5", nullptr));

        handNumberComboBox->setCurrentText(QCoreApplication::translate("MainWindow", "1", nullptr));
        labelTotalChips->setText(QCoreApplication::translate("MainWindow", "XXX", nullptr));
        dealerTotalLabel->setText(QCoreApplication::translate("MainWindow", "Known Dealer Total: 0", nullptr));
        playerTotalLabel->setText(QCoreApplication::translate("MainWindow", "Hand Total: 0", nullptr));
        menuPlay->setTitle(QCoreApplication::translate("MainWindow", "Play", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuLessons->setTitle(QCoreApplication::translate("MainWindow", "Lessons", nullptr));
        menuSection1->setTitle(QCoreApplication::translate("MainWindow", "Section 1: Basics Fules", nullptr));
        menuSection_2_Advanced_Rules->setTitle(QCoreApplication::translate("MainWindow", "Section 2: Advanced Rules", nullptr));
        menuSection_3_Basic_Strategy->setTitle(QCoreApplication::translate("MainWindow", "Section 3: Basic Strategy", nullptr));
        menuSection_4_Card_Counting->setTitle(QCoreApplication::translate("MainWindow", "Section 4: Card Counting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
