#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    signup = new Signup(this);
    setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint | Qt::BypassWindowManagerHint | Qt::WindowTitleHint);

    Player *tempPlayer = new Player;
    playerMap = new Map(this, *tempPlayer, tempPlayer->get_ID(), players);

    connect(ui->usernameled, SIGNAL(textChanged(const QString&)), this, SLOT(check_line_edits(const QString&)));
    connect(ui->passwordled, SIGNAL(textChanged(const QString&)), this, SLOT(check_line_edits(const QString&)));
    connect(ui->signupbtn, SIGNAL(clicked()), this, SLOT(on_signupbtn_clicked()));
    connect(ui->buttonBox, SIGNAL(accepted()),this, SLOT(on_loginbtn_clicked()));
    connect(ui->buttonBox,SIGNAL(rejected()),this, SLOT(on_buttonBox_rejected()));
    connect(signup, SIGNAL(exitBtn_clicked()), this, SLOT(show()));
    connect(signup, SIGNAL(exitBtn_clicked()), signup, SLOT(close_and_clear()));
    connect(signup, SIGNAL(sendNewUserData(QString, QString, QString, QString)), this, SLOT(saveNewUserData(QString, QString, QString, QString)));
    connect(playerMap, SIGNAL(scoreboardclicked()), this, SLOT(show_score_board()));
    connect(playerMap, SIGNAL(exitBtn_clicked()), this, SLOT(show()));
    connect(playerMap, SIGNAL(exitBtn_clicked()), this, SLOT(mapClosed()));

    this->setFixedSize(this->geometry().width(),this->geometry().height());
    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Login");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("Exit");

    // Setting up users
    QDir d;
    QFile file(d.currentPath() + "\\..\\AP_Project\\data.json");
    file.setFileName(d.currentPath() + "\\..\\AP_Project\\data.json");
    file.open(QIODevice::ReadOnly);

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
        int ID = val.toObject().value("ID").toInteger();
        QString name = val.toObject().value("name").toString();
        QString username = val.toObject().value("username").toString();
        QString password = val.toObject().value("password").toString();
        QString email = val.toObject().value("email").toString();
        int level = val.toObject().value("level").toInteger();
        int XP = val.toObject().value("XP").toInteger();
        int coins = val.toObject().value("coins").toInteger();
        int nails = val.toObject().value("nails").toInteger();
        int shovel = val.toObject().value("shovel").toInteger();
        int hay = val.toObject().value("hay").toInteger();
        int egg = val.toObject().value("egg").toInteger();
        int milk = val.toObject().value("milk").toInteger();
        int wool = val.toObject().value("wool").toInteger();
        int wheat = val.toObject().value("wheat").toInteger();
        int cow = val.toObject().value("cow").toInteger();
        int sheep = val.toObject().value("sheep").toInteger();
        int hen = val.toObject().value("hen").toInteger();
        int day = val.toObject().value("day").toInteger();

        players.push_back(Player(name, username, password, email, coins, XP, level,
                                    nails , shovel, hay , egg , milk, wool, wheat , cow , sheep,  hen , day));
    }
}

Login::~Login()
{
    delete ui;
}

void Login::addPlayer(Player p)
{
    players.push_back(p);
    saveUsersData();
}

void Login::saveUsersData()
{
    QJsonObject mainObj;
    QJsonArray mainArray;
    for (int i = 0; i < players.size(); i++)
    {
        QJsonObject playerObj;
        playerObj["ID"] = players[i].get_ID();
        playerObj["name"] = players[i].get_name();
        playerObj["username"] = players[i].get_username();
        playerObj["password"] = players[i].get_password();
        playerObj["email"] = players[i].get_email();
        playerObj["level"] = players[i].get_level();
        playerObj["XP"] = players[i].get_XP();
        playerObj["coins"] = players[i].get_coins();
        playerObj["nails"] = players[i].getNail();
        playerObj["shovel"] = players[i].getShovel();
        playerObj["hay"] = players[i].getHay();
        playerObj["egg"] = players[i].getEgg();
        playerObj["milk"] = players[i].getMilk();
        playerObj["wool"] = players[i].getWool();
        playerObj["wheat"] = players[i].getWheat();
        playerObj["cow"] = players[i].getCow();
        playerObj["sheep"] = players[i].getSheep();
        playerObj["hen"] = players[i].getHen();
        playerObj["day"] = players[i].getDay();

        mainArray.append(playerObj);
    }
    mainObj["users"] = mainArray;

    QByteArray byteArray;
    byteArray = QJsonDocument(mainObj).toJson();

    QDir d;
    QFile file(d.currentPath() + "\\..\\AP_Project\\data.json");
    file.setFileName(d.currentPath() + "\\..\\AP_Project\\data.json");
    file.open(QIODevice::WriteOnly);
    file.write(byteArray);
    file.close();
}

void Login::addPlayer(QString name, QString username, QString password, QString email)
{
    Player p(name, username, password, email);
    addPlayer(p); // Smurt :))
}

void Login::on_loginbtn_clicked()
{
    qDebug()<<"in login onloginbtn clicked";
    for (int i = 0; i < players.size(); i++)
        if ((ui->usernameled->text() == players[i].get_username()) && (ui->passwordled->text() == players[i].get_password()))
        {
            currentPlayer = &players[i];
            playerMap = new Map(this, *currentPlayer, currentPlayer->get_ID(), players);
            playerMap->show();
            loginStat = true;
            this->hide();
        }
        else
            ui->loginStat->setText("Wrong username or password");
}

void Login::check_line_edits(const QString &a_strString)
{
    ui->loginStat->clear();
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

void Login::on_signupbtn_clicked()
{
    this->close();
    signup->show();
}

void Login::on_buttonBox_rejected()
{
    this->close();
}

void Login::saveNewUserData(QString name, QString username, QString password, QString email)
{
    qDebug()<<"in save new player data";
    Player *p = new Player(name, username, password, email);
    addPlayer(*p); // Saves to json
    signupStat = true;
}

void Login::mapClosed()
{
    this->show();
    playerMap->close();
    saveUsersData();
}

void Login::show_score_board()
{
    emit(scoreboardclicked());
}

