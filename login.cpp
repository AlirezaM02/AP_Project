#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    signup= new Signup(this);
    connect(ui->usernameled, SIGNAL(textChanged(const QString&)), this, SLOT(check_line_edits(const QString&)));
    connect(ui->passwordled, SIGNAL(textChanged(const QString&)), this, SLOT(check_line_edits(const QString&)));
    connect(ui->signupbtn, SIGNAL(clicked()), this, SLOT(on_signupbtn_clicked()));
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Login");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Exit");

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


void Login::on_loginbtn_clicked()
{
    ok = true;
    qDebug()<<"on loginbtn clicked";
}

void Login::check_line_edits(const QString &a_strString)
{
    qDebug()<<"in slot!";
    if (ui->usernameled->text().isEmpty() || ui->passwordled->text().isEmpty())
    {
        ok = true;
        ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);
    }
    else
    {
          ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
    }
}

void Login::on_signupbtn_clicked() {

    //connect(this, SIGNAL(destroyed()), signup, SLOT(close()));
    //this->close();
    signup->show();
}
