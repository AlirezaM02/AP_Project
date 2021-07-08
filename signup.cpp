#include "signup.h"
#include "ui_signup.h"

signup::signup(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    ui->signupbtn->setDisabled(true);
    connect(ui->nameled, SIGNAL(textChanged(const QString &)), this, SLOT(checkLineEdits()));
    connect(ui->usernameled, SIGNAL(textChanged(const QString &)), this, SLOT(checkLineEdits()));
    connect(ui->passwordled, SIGNAL(textChanged(const QString &)), this, SLOT(checkLineEdits()));
    connect(ui->rewriteled, SIGNAL(textChanged(const QString &)), this, SLOT(checkLineEdits()));
    connect(ui->emailled, SIGNAL(textChanged(const QString &)), this, SLOT(checkLineEdits()));
    connect(this, SIGNAL(passmatch), this, SLOT(checkLineEdits()));
}

signup::~signup()
{
    delete ui;
}

void signup::on_signupbtn_clicked()
{

}

void signup::checkLineEdits()
{
    bool validemail;
    int flag=0;
    QChar c= ui->emailled->text()[0];
    if (!c.isLetter()&&!flag)
    {
        validemail= false;
        flag=1;
        ui->emailerrorlbl->setText("Invalid Email!");
    }
    int at=-1;
    int dot=-1;
    for(int i=0; i<ui->emailled->text().length(); i++)
    {
        if (ui->emailled->text()[i]=='@')
            at=i;
        else if (ui->emailled->text()[i]=='.')
            dot=i;
    }
    if((at==-1 || dot==-1)&&!flag)
    {
        validemail= false;
        ui->emailerrorlbl->setText("Invalid Email!");
        flag=1;
    }
    if( (dot<at)&& !flag)
    {
        validemail= false;
        ui->emailerrorlbl->setText("Invalid e-mail!");
        flag=1;
    }
    if (!flag)
    {
        validemail= !(dot>=(ui->emailled->text().length()-1));
    }
    if (validemail)
        //ui->errorlbl->setText("");
        ui->emailerrorlbl->clear();
    bool strongPassWord;
    int lower = 0, digit = 0, symbol = 0, upper = 0, passlen = ui->passwordled->text().length();
    for (const auto& character : ui->passwordled->text())
    {
        if (character.isUpper())
            upper++;
        else if (character.isLower())
            lower++;
        else if (character.isDigit())
            digit++;
        else
            symbol++;
    }
    if (upper >= 1 and lower >= 1 and digit >= 1 and symbol >= 1 and passlen >=6)
    {
        strongPassWord= true;
    }
    else
    {
        strongPassWord=false;
        ui->passworderrorlbl->setText("Your password is not strong enough! (Make sure it contains at least 6 characters and an uppercase letter, a lowercase letter, a number and a special symbol)");

    }
    bool confirmpass;
    if(ui->passwordled->text()==ui->rewriteled->text())
    {
        confirmpass=true;
        ui->confirmpasserrorlbl->clear();

    }
    else
    {
        confirmpass=false;
        ui->confirmpasserrorlbl->setText("Passwords don't match");
    }
    //all filled? [X]
    //pass==rewritepass? [X]
    //new username?
    //strong pass? [X]
    //valid name?
    //valid email? [X]

    bool ok= !ui->usernameled->text().isEmpty()
            && !ui->passwordled->text().isEmpty()
            && !ui->rewriteled->text().isEmpty()&&(confirmpass)
            &&(validemail)&&(strongPassWord);
    ui->signupbtn->setEnabled(ok);
}
