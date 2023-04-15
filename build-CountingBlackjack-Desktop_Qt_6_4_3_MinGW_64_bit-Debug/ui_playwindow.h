/********************************************************************************
** Form generated from reading UI file 'playwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYWINDOW_H
#define UI_PLAYWINDOW_H

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

class Ui_PlayWindow
{
public:
    QWidget *centralwidget;
    QPushButton *mainPushButton;
    QPushButton *learnPushButton;
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

    void setupUi(QMainWindow *PlayWindow)
    {
        if (PlayWindow->objectName().isEmpty())
            PlayWindow->setObjectName("PlayWindow");
        PlayWindow->resize(800, 600);
        centralwidget = new QWidget(PlayWindow);
        centralwidget->setObjectName("centralwidget");
        mainPushButton = new QPushButton(centralwidget);
        mainPushButton->setObjectName("mainPushButton");
        mainPushButton->setGeometry(QRect(0, 510, 83, 29));
        learnPushButton = new QPushButton(centralwidget);
        learnPushButton->setObjectName("learnPushButton");
        learnPushButton->setGeometry(QRect(710, 520, 83, 29));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 370, 81, 16));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(120, 70, 561, 141));
        dealerArea = new QHBoxLayout(horizontalLayoutWidget);
        dealerArea->setObjectName("dealerArea");
        dealerArea->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(560, 300, 80, 24));
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(120, 340, 561, 141));
        playerArea = new QHBoxLayout(horizontalLayoutWidget_2);
        playerArea->setObjectName("playerArea");
        playerArea->setContentsMargins(0, 0, 0, 0);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(20, 420, 80, 24));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(270, 300, 80, 24));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(380, 280, 49, 51));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(180, 270, 80, 24));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(380, 210, 49, 51));
        discardDeck = new QLabel(centralwidget);
        discardDeck->setObjectName("discardDeck");
        discardDeck->setGeometry(QRect(690, 70, 100, 140));
        discardDeck->setFrameShape(QFrame::Box);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(180, 300, 80, 24));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(690, 230, 101, 261));
        drawDeck = new QLabel(centralwidget);
        drawDeck->setObjectName("drawDeck");
        drawDeck->setGeometry(QRect(10, 70, 100, 140));
        drawDeck->setFrameShape(QFrame::Box);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(470, 300, 80, 24));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(560, 270, 80, 24));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(20, 390, 81, 24));
        PlayWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PlayWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        PlayWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PlayWindow);
        statusbar->setObjectName("statusbar");
        PlayWindow->setStatusBar(statusbar);

        retranslateUi(PlayWindow);

        QMetaObject::connectSlotsByName(PlayWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PlayWindow)
    {
        PlayWindow->setWindowTitle(QCoreApplication::translate("PlayWindow", "MainWindow", nullptr));
        mainPushButton->setText(QCoreApplication::translate("PlayWindow", "Main Menu", nullptr));
        learnPushButton->setText(QCoreApplication::translate("PlayWindow", "Learn Mode", nullptr));
        label_8->setText(QCoreApplication::translate("PlayWindow", "Bet Place Area", nullptr));
        pushButton_4->setText(QCoreApplication::translate("PlayWindow", "DOUBLE DOWN", nullptr));
        pushButton_6->setText(QCoreApplication::translate("PlayWindow", "DEAL", nullptr));
        pushButton_3->setText(QCoreApplication::translate("PlayWindow", "STAND", nullptr));
        label_5->setText(QCoreApplication::translate("PlayWindow", "P SCORE", nullptr));
        pushButton_7->setText(QCoreApplication::translate("PlayWindow", "GIMMICK BTN", nullptr));
        label_6->setText(QCoreApplication::translate("PlayWindow", "D Score", nullptr));
        discardDeck->setText(QCoreApplication::translate("PlayWindow", "Discard", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PlayWindow", "HIT", nullptr));
        label_7->setText(QCoreApplication::translate("PlayWindow", "Chips Area", nullptr));
        drawDeck->setText(QCoreApplication::translate("PlayWindow", "Deck", nullptr));
        pushButton->setText(QCoreApplication::translate("PlayWindow", "SPLIT", nullptr));
        pushButton_5->setText(QCoreApplication::translate("PlayWindow", "INSURANCE", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("PlayWindow", "10", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("PlayWindow", "20", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("PlayWindow", "30", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("PlayWindow", "40", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("PlayWindow", "50", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("PlayWindow", "100", nullptr));

    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H
