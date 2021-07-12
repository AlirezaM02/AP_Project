#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "application.h"
#include "logindialog.h"
#include "scoreboard.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    void showScoreboard();

private slots:
    void saveNewUserData(QString, QString, QString, QString);

signals:

private:
    Ui::MainWindow *ui;
    Application application;
    LoginDialog *login;
    Scoreboard *scoreboard;
    bool setscoreboard = false;
    bool loginStatus = false;
    bool signupStatus = false;
    loginDialog *login;
    void showSignupPage();
};
#endif // MAINWINDOW_H
