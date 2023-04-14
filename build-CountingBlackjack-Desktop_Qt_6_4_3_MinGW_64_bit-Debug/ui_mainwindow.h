/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *dealerArea;
    QLabel *playerArea;
    QLabel *drawDeck;
    QLabel *discardDeck;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QComboBox *comboBox;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        dealerArea = new QLabel(centralwidget);
        dealerArea->setObjectName("dealerArea");
        dealerArea->setGeometry(QRect(180, 100, 421, 141));
        dealerArea->setFrameShape(QFrame::Box);
        playerArea = new QLabel(centralwidget);
        playerArea->setObjectName("playerArea");
        playerArea->setGeometry(QRect(160, 360, 461, 175));
        playerArea->setFrameShape(QFrame::Box);
        drawDeck = new QLabel(centralwidget);
        drawDeck->setObjectName("drawDeck");
        drawDeck->setGeometry(QRect(70, 100, 100, 140));
        drawDeck->setFrameShape(QFrame::Box);
        discardDeck = new QLabel(centralwidget);
        discardDeck->setObjectName("discardDeck");
        discardDeck->setGeometry(QRect(610, 100, 100, 140));
        discardDeck->setFrameShape(QFrame::Box);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(360, 310, 49, 51));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(360, 240, 49, 51));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(650, 260, 111, 261));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 440, 81, 16));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(450, 330, 80, 24));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(160, 330, 80, 24));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(250, 330, 80, 24));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(540, 330, 80, 24));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(540, 300, 80, 24));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(30, 490, 80, 24));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(160, 300, 80, 24));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 460, 81, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        dealerArea->setText(QCoreApplication::translate("MainWindow", "Dealer card Area", nullptr));
        playerArea->setText(QCoreApplication::translate("MainWindow", "player hands area", nullptr));
        drawDeck->setText(QCoreApplication::translate("MainWindow", "Deck", nullptr));
        discardDeck->setText(QCoreApplication::translate("MainWindow", "Discard", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "P SCORE", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "D Score", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Chips Area", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Bet Place Area", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "SPLIT", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "HIT", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "STAND", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "DOUBLE DOWN", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "INSURANCE", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "DEAL", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "GIMMICK BTN", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "10", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "20", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "30", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "40", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "50", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "100", nullptr));

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
