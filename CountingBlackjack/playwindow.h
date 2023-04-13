#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QMainWindow>

namespace Ui {
class PlayWindow;
}

class PlayWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PlayWindow(QWidget *parent = nullptr);
    ~PlayWindow();

private:
    Ui::PlayWindow *ui;

signals:
    void switchToMainWindow(); //signal to switch to the main window
    void switchToLearnWindow(); //signal to switch to the play window

public slots:
    void mainWindowButtonClick(); //On main window button click emmit signal
    void learnWindowButtonClick(); //On play window button click emmit signal
    void setupPlayUI(); //When switching to this window, set it up

private slots:

};

#endif // PLAYWINDOW_H
