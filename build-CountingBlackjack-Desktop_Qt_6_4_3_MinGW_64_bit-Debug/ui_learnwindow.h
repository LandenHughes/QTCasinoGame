/********************************************************************************
** Form generated from reading UI file 'learnwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARNWINDOW_H
#define UI_LEARNWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LearnWindow
{
public:
    QWidget *centralwidget;
    QPushButton *mainPushButton;
    QPushButton *playPushButton;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *dealerArea;
    QPushButton *pushButton_4;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *playerArea;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QLabel *label_5;
    QPushButton *pushButton_7;
    QLabel *label_6;
    QLabel *discardDeck;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QLabel *drawDeck;
    QPushButton *pushButton;
    QPushButton *pushButton_5;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LearnWindow)
    {
        if (LearnWindow->objectName().isEmpty())
            LearnWindow->setObjectName("LearnWindow");
        LearnWindow->resize(800, 600);
        centralwidget = new QWidget(LearnWindow);
        centralwidget->setObjectName("centralwidget");
        mainPushButton = new QPushButton(centralwidget);
        mainPushButton->setObjectName("mainPushButton");
        mainPushButton->setGeometry(QRect(10, 510, 83, 29));
        playPushButton = new QPushButton(centralwidget);
        playPushButton->setObjectName("playPushButton");
        playPushButton->setGeometry(QRect(710, 510, 83, 29));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 360, 81, 16));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(120, 60, 561, 141));
        dealerArea = new QHBoxLayout(horizontalLayoutWidget);
        dealerArea->setObjectName("dealerArea");
        dealerArea->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(560, 290, 80, 24));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(120, 330, 561, 141));
        playerArea = new QHBoxLayout(horizontalLayoutWidget_2);
        playerArea->setObjectName("playerArea");
        playerArea->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 410, 80, 24));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(270, 290, 80, 24));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(380, 270, 49, 51));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(180, 260, 80, 24));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(380, 200, 49, 51));
        discardDeck = new QLabel(centralwidget);
        discardDeck->setObjectName("discardDeck");
        discardDeck->setGeometry(QRect(690, 60, 100, 140));
        discardDeck->setFrameShape(QFrame::Box);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 290, 80, 24));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(690, 220, 101, 261));
        drawDeck = new QLabel(centralwidget);
        drawDeck->setObjectName("drawDeck");
        drawDeck->setGeometry(QRect(10, 60, 100, 140));
        drawDeck->setFrameShape(QFrame::Box);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(470, 290, 80, 24));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(560, 260, 80, 24));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 380, 81, 24));
        LearnWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LearnWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        LearnWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LearnWindow);
        statusbar->setObjectName("statusbar");
        LearnWindow->setStatusBar(statusbar);

        retranslateUi(LearnWindow);

        QMetaObject::connectSlotsByName(LearnWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LearnWindow)
    {
        LearnWindow->setWindowTitle(QCoreApplication::translate("LearnWindow", "MainWindow", nullptr));
        mainPushButton->setText(QCoreApplication::translate("LearnWindow", "Main Menu", nullptr));
        playPushButton->setText(QCoreApplication::translate("LearnWindow", "Play Mode", nullptr));
        label_8->setText(QCoreApplication::translate("LearnWindow", "Bet Place Area", nullptr));
        pushButton_4->setText(QCoreApplication::translate("LearnWindow", "DOUBLE DOWN", nullptr));
        pushButton_6->setText(QCoreApplication::translate("LearnWindow", "DEAL", nullptr));
        pushButton_3->setText(QCoreApplication::translate("LearnWindow", "STAND", nullptr));
        label_5->setText(QCoreApplication::translate("LearnWindow", "P SCORE", nullptr));
        pushButton_7->setText(QCoreApplication::translate("LearnWindow", "GIMMICK BTN", nullptr));
        label_6->setText(QCoreApplication::translate("LearnWindow", "D Score", nullptr));
        discardDeck->setText(QCoreApplication::translate("LearnWindow", "Discard", nullptr));
        pushButton_2->setText(QCoreApplication::translate("LearnWindow", "HIT", nullptr));
        label_7->setText(QCoreApplication::translate("LearnWindow", "Chips Area", nullptr));
        drawDeck->setText(QCoreApplication::translate("LearnWindow", "Deck", nullptr));
        pushButton->setText(QCoreApplication::translate("LearnWindow", "SPLIT", nullptr));
        pushButton_5->setText(QCoreApplication::translate("LearnWindow", "INSURANCE", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("LearnWindow", "10", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("LearnWindow", "20", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("LearnWindow", "30", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("LearnWindow", "40", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("LearnWindow", "50", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("LearnWindow", "100", nullptr));

    } // retranslateUi

};

namespace Ui {
    class LearnWindow: public Ui_LearnWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNWINDOW_H
