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
        flag=1;
    }
    if( (dot<at)&& !flag)
    {
        validemail= false;
        flag=1;
    }
    if (!flag)
    {
        validemail= !(dot>=(ui->emailled->text().length()-1));
    }
    //all filled? [X]
    //pass==rewritepass? [X]
    //new username?
    //strong pass?
    //valid name?
    //valid email? [X]
    bool ok= !ui->usernameled->text().isEmpty()
            && !ui->passwordled->text().isEmpty()
            && !ui->rewriteled->text().isEmpty()&&(ui->passwordled->text()==ui->rewriteled->text())
            &&(validemail);
    ui->signupbtn->setEnabled(ok);
}
