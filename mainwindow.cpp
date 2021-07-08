#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    application.fetchPlayersData();
    login=new LoginDialog();
    int result=login->exec();
       while(1)
       {
           if(result==QDialog::Accepted)
            {
                loginSeccess=application.login(login->getUsername(),login->getPassword());
                if(loginSeccess)
                 {
                     break;
                 }
                 else
                 {
                     result=login->exec();
                 }
             }
             else if(result==QDialog::Rejected)
             {
                 this->close();
                 break;
             }
         }
}
MainWindow::~MainWindow()
{
    delete ui;
}

