#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    connect(ui->usernameled, SIGNAL(editingFinished()), this, SLOT(check_line_edits()));
    connect(ui->passwordled, SIGNAL(editingFinished()), this, SLOT(check_line_edits()));
    connect(ui->signupbtn, SIGNAL(clicked()), this, SLOT(on_signupbtn_clicked()));
}

Login::~Login()
{
    delete ui;
}

QString Login::getUsername()
{
    return ui->usernameled->text();
}

QString Login::getPassword()
{
    return ui->passwordled->text();
}

void Login::check_line_edits()
{
    if (ui->usernameled->text().length() != 0 && )
    {
        un_Ok = true;
    }
}

void Login::on_loginbtn_clicked()
{
    un_Ok = true;
}

void Login::on_signupbtn_clicked() {
    Signup* signup;
    signup= new Signup(this);
    //connect(this, &QDialog::destroyed, signup, &QDialog::deleteLater);
    signup->show();
}
