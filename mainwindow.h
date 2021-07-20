#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "application.h"
#include "login.h"
#include "signup.h"
#include "scoreboard.h"
#include "map.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui { class MainWindow; }

QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
    void showMap();

private slots:
    void saveNewUserData(QString, QString, QString, QString);

public slots:
    void showScoreboard();

private:
    Ui::MainWindow *ui;
    Application application;
    Login *login;
    Scoreboard *scoreboard;
    Map *map;
    bool ssb = false;
    bool smap = false;
    bool loginStatus = false;
    bool signupStatus = false;
};
#endif // MAINWINDOW_H
