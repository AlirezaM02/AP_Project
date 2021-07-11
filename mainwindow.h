#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "application.h"
#include "logindialog.h"
#include "scoreboard.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showScoreboard();

private:
    Ui::MainWindow *ui;
    Application application;
    LoginDialog* login;
    Scoreboard* scoreboard;
    bool loginSeccess=false;
    bool setscoreboard= false;
};
#endif // MAINWINDOW_H
