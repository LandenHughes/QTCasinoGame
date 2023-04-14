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
    } // retranslateUi

};

namespace Ui {
    class PlayWindow: public Ui_PlayWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYWINDOW_H
