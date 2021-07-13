#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{
    application.fetchPlayersData();
    login = new Login();
    login->show();
    int result = login->exec();
    while (1)
    {
        if (result == QDialog::Accepted)
        {
            loginStatus = application.login(login->getUsername(), login->getPassword());

            if (loginStatus)
                break;

            else
                result = login->exec();
        }

        else if (result == QDialog::Rejected)
        {
            this->close();
            break;
        }
    }
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showScoreboard()
{
    scoreboard = new Scoreboard(NULL, application.getPlayerlistref(), application.getplayerID());
    int result = scoreboard->exec();
    while (1)
    {
        if (result == QDialog::Accepted)
        {
            ssb = application.setScoreboard(application.getplayerID());
            if (ssb)
                break;
            else
                result = scoreboard->exec();
        }

        else if (result == QDialog::Rejected)
        {
            scoreboard->close();
            //or this?
            break;
        }
    }
}

void MainWindow::saveNewUserData(QString name, QString username, QString password, QString email)
{
    application.addPlayer(Player(name, username, password, email)); // Saves to json automatically too
}
