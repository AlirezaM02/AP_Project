#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    connect(ui->usernameled, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->passwordled, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));

}

login::~login()
{
    delete ui;
}

void login::checkLineEdits()
{
bool ok = !ui->usernameled->text().isEmpty()
&& !ui->passwordled->text().isEmpty();

ui->loginbtn->setEnabled(ok);
}

void login::on_loginbtn_clicked()
{

}


void login::on_signupbtn_clicked()
{

}

