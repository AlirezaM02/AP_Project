#include "logindialog.h"
#include "ui_logindialog.h"

loginDialog::loginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    connect(ui->usernameled, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->passwordled, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    //connect(ui->signupbtn, SIGNAL(pressed()), this, SLOT())
}

loginDialog::~loginDialog()
{
    delete ui;
}

QString loginDialog::getUsername()
{
    return ui->usernameled->text();
}

QString loginDialog::getPassword()
{
    return ui->passwordled->text();
}

void loginDialog::check_line_edits()
{
    bool ok = !ui->usernameled->text().isEmpty()
            && !ui->passwordled->text().isEmpty();

    ui->loginbtn->setEnabled(ok);
}

void loginDialog::on_loginbtn_clicked()
{

}

void loginDialog::on_signupbtn_clicked()
{

}
