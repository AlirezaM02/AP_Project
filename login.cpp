#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);
    this->setFixedSize(this->geometry().width(),this->geometry().height());
    connect(ui->usernameled, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
    connect(ui->passwordled, SIGNAL(textChanged()), this, SLOT(checkLineEdits()));
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
    bool ok = !ui->usernameled->text().isEmpty() && !ui->passwordled->text().isEmpty();

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(ok);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Login");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Exit");
}

void Login::on_loginbtn_clicked() {}

void Login::on_signupbtn_clicked() {
    Signup* signup;
    signup= new Signup(this);
    signup->show();
}
