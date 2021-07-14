#include "signup.h"
#include "ui_signup.h"

Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    ui->signupbtn->setDisabled(true);
    connect(ui->nameled, SIGNAL(editingFinished()), this, SLOT(check_line_edits()));
    connect(ui->usernameled, SIGNAL(editingFinished()), this, SLOT(check_line_edits()));
    connect(ui->passwordled, SIGNAL(editingFinished()), this, SLOT(check_line_edits()));
    connect(ui->rewriteled, SIGNAL(editingFinished()), this, SLOT(check_line_edits()));
    connect(ui->emailled, SIGNAL(editingFinished()), this, SLOT(check_line_edits()));
    connect(this, SIGNAL(passmatch()), this, SLOT(check_line_edits()));
}

Signup::~Signup()
{
    delete ui;
}

void Signup::on_signupbtn_clicked()
{
    QString name, username, password, email;
    name = ui->nameled->text();
    username = ui->usernameled->text();
    password = ui->passwordled->text();
    email = ui->emailled->text();
    emit sendNewUserData(name, username, password, email);
}

void Signup::check_line_edits()
{
    QChar c;

    bool validemail;
    int flag=0;

    c = ui->emailled->text()[0];
    if (!c.isLetter() && !flag)
    {
        validemail = false;
        flag = 1;
        ui->emailerrorlbl->setText("Invalid Email!");
    }

    int at = -1;
    int dot = -1;

    for (int i = 0; i < ui->emailled->text().length(); i++)
    {
        if (ui->emailled->text()[i] == '@')
            at=i;
        else if (ui->emailled->text()[i]=='.')
            dot=i;
    }

    if ((at == -1 || dot == -1) && !flag)
    {
        validemail = false;
        ui->emailerrorlbl->setText("Invalid Email!");
        flag = 1;
    }

    if ((dot < at) && !flag)
    {
        validemail = false;
        ui->emailerrorlbl->setText("Invalid e-mail!");
        flag = 1;
    }

    if (!flag)
    {
        validemail = !(dot>=(ui->emailled->text().length() - 1));
    }

    if (validemail)
        //ui->errorlbl->setText("");
        ui->emailerrorlbl->clear();

    bool strongPassword;
    int lower = 0, digit = 0, symbol = 0, upper = 0, passlen = ui->passwordled->text().length();

    for (int i = 0; i < passlen; i++)
    {
        c = ui->passwordled->text()[i];
        if (c.isUpper())
            upper++;
        else if (c.isLower())
            lower++;
        else if (c.isDigit())
            digit++;
        else
            symbol++;
        qDebug()<<upper<<lower<<digit<<symbol<<passlen;
    }

    if (upper >= 1 and lower >= 1 and digit >= 1 and symbol >= 1 and passlen >=6)
    {
        strongPassword = true;
        ui->passworderrorlbl->clear();
    }

    else
    {
        strongPassword = false;
        ui->passworderrorlbl->setText("Your password is not strong enough! \n(Make sure it contains at least 6 characters and an uppercase letter, a lowercase letter,\n a number and a special symbol)");
    }

    bool confirmpass;

    if (ui->passwordled->text().toUtf8() == ui->rewriteled->text().toUtf8())
    {
        confirmpass=true;
        ui->confirmpasserrorlbl->clear();
    }

    else
    {
        confirmpass=false;
        ui->confirmpasserrorlbl->setText("Passwords don't match");
    }

    bool validName = false;
    for (int i = 0; i < ui->nameled->text().length(); i++)
    {
        c = ui->nameled->text()[i];
        if (c.isDigit() && (!(c.isDigit() || c.isLetter()))) // If its a digit or not a letter or a digit (meaning its a symbol)
        {
            validName = false;
            ui->nameerrorlbl->setText("Invalid name!");
        }
        else
        {
            validName = true;
            ui->nameerrorlbl->clear();
        }
    }

    int username_counter = 0;
    QFile file("C:\\data.json");
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Json file couldn't be opened/found";
        return;
    }
    QByteArray byteArray;
    byteArray = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);
    if (parseError.error != QJsonParseError::NoError)
    {
        qWarning() << "Parse error at " << parseError.offset << ":" << parseError.errorString();
        exit(0);
    }
    QJsonObject Obj = jsonDoc.object();
    QJsonArray Arr = Obj.value("users").toArray();
    foreach (const QJsonValue &val, Arr)
    {
        if (val.toObject().value("username").toString().toStdString() == ui->usernameled->text().toStdString())
            username_counter ++;
    }

    //all filled? [X]
    //pass==rewritepass? [X]
    //new username? [X]
    //strong pass? [X]
    //valid name? [X]
    //valid email? [X]

    bool ok = !(ui->usernameled->text().isEmpty() || ui->passwordled->text().isEmpty()
                || ui->rewriteled->text().isEmpty() || (!confirmpass) || (!validemail)
                || (!strongPassword) || (!validName) || (username_counter != 0));
    ui->signupbtn->setEnabled(ok);
}
