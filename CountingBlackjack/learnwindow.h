#ifndef LEARNWINDOW_H
#define LEARNWINDOW_H

#include <QMainWindow>

namespace Ui {
class LearnWindow;
}

class LearnWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LearnWindow(QWidget *parent = nullptr);
    ~LearnWindow();

private:
    Ui::LearnWindow *ui;

signals:
    void switchToMainWindow(); //signal to switch to the main window
    void switchToPlayWindow(); //sinal to switch tot he play window

public slots:
    void mainWindowButtonClick(); //On main window button click switch to main
    void playWindowButtonClick(); //On play window button click switch to play
    void setupLearnUI(); //When switching to this window, setup the windo

private slots:

};

#endif // LEARNWINDOW_H
