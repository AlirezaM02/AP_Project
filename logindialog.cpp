#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    connect(ui->usernameled, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->passwordled, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));

}

LoginDialog::~LoginDialog()
{
    delete ui;
}

QString LoginDialog::getUsername()
{
    return ui->usernameled->text();
}

QString LoginDialog::getPassword()
{
    return ui->passwordled->text();
}

void LoginDialog::checkLineEdits()
{
bool ok = !ui->usernameled->text().isEmpty()
&& !ui->passwordled->text().isEmpty();

ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Login");
ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Exit");

}
void LoginDialog::on_loginbtn_clicked()
{

}
void LoginDialog::on_signupbtn_clicked()
{

}
