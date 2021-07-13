#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ok = false;

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Login");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Exit");

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
    if (((ui->usernameled->text().length() != 0) && (ui->passwordled->text().length() != 0)))
        ok = true;

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
}

void Login::on_loginbtn_clicked()
{
    ok = true;
}

void Login::on_signupbtn_clicked()
{
    Signup *signup;
    signup = new Signup(this);
    //connect(this, &QDialog::destroyed, signup, &QDialog::deleteLater);
    this->close();
    signup->show();
}
