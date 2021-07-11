#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{
    application.fetchPlayersData();
    login = new loginDialog();
    login->show();
    int result = login->exec();
    while(1)
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

void MainWindow::showSignupPage()
{
    signupPage = new signup(this);
    signupPage->show();
    connect(signupPage, SIGNAL(sendNewUserData(QString, QString, QString, QString)), this, SLOT(saveNewUserData(QString, QString, QString, QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveNewUserData(QString name, QString username, QString password, QString email)
{
    application.addPlayer(Player(20, 0, 1, name, username, password, email)); // Saves to json automatically too
}

