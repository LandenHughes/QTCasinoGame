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
    } // retranslateUi

};

namespace Ui {
    class LearnWindow: public Ui_LearnWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARNWINDOW_H
