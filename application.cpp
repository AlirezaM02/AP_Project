#include "application.h"

int Application::playerCounter = 0;
int Application::lastID = 0;

Player *Application::getCurrentPlayer() const
{
    return currentPlayer;
}

const QVector<Player> &Application::getPlayerlist() const
{
    return playerlist;
}

Application::Application()
{
    fetchPlayersData();
}

Application::~Application()
{
    fetchPlayersData();
    savePlayersData();
}

void Application::savePlayersData()
{
    QJsonObject mainObj;
    QJsonArray mainArray;
    for (int i = 0; i < playerlist.size(); i++)
    {
        QJsonObject playerObj;
        playerObj["ID"] = playerlist[i].get_ID();
        playerObj["name"] = playerlist[i].get_name();
        playerObj["username"] = playerlist[i].get_username();
        playerObj["password"] = playerlist[i].get_password();
        playerObj["email"] = playerlist[i].get_email();
        playerObj["level"] = playerlist[i].get_level();
        playerObj["XP"] = playerlist[i].get_XP();
        playerObj["coins"] = playerlist[i].get_coins();
        playerObj["nails"] = playerlist[i].getNail();
        playerObj["shovel"] = playerlist[i].getShovel();
        playerObj["hay"] = playerlist[i].getHay();
        playerObj["egg"] = playerlist[i].getEgg();
        playerObj["milk"] = playerlist[i].getMilk();
        playerObj["wool"] = playerlist[i].getWool();
        playerObj["wheat"] = playerlist[i].getWheat();
        playerObj["cow"] = playerlist[i].getCow();
        playerObj["sheep"] = playerlist[i].getSheep();
        playerObj["hen"] = playerlist[i].getHen();
        playerObj["day"] = playerlist[i].getDay();

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

void Application::fetchPlayersData()
{
    playerlist.erase(playerlist.begin(), playerlist.end());

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
        int ID= val.toObject().value("ID").toInteger();
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
        //Map _map;
        playerlist.push_back(Player(name, username, password, email, coins, XP, level,
                                    nails , shovel, hay , egg ,milk,wool, wheat , cow , sheep,  hen , day));
    }
}

void Application::addPlayer(Player player)
{
    playerlist.push_back(player);
    savePlayersData();
}

void Application::addPlayer(QString name, QString username, QString password, QString email)
{
    playerlist.push_back(Player(name, username, password, email));
    savePlayersData();
}

Player *Application::findPlayer(QString username)
{
    for (int i = 0; i < playerlist.size(); i++)
    {
        if (playerlist[i].get_username() == username)
            return &playerlist[i];
    }
    return nullptr;
}

void Application::refresh(int ID)
{
    fetchPlayersData();
    setCurrentPlayer(ID);
}

void Application::refresh()
{
    fetchPlayersData();
}

bool Application::login(QString username, QString password)
{
    qDebug()<<"in application.login.";
    for (int i = 0; i < playerlist.size(); i++)
    {
        if (playerlist[i].get_username() == username && playerlist[i].get_password() == password)
        {
            currentPlayer = &playerlist[i];
            playerID = playerlist[i].get_ID();
            //TODO
            message.setText("login successfull");
            message.setStandardButtons(QMessageBox::Ok);
            loginstatus = true;

            if(message.exec() == QMessageBox::Ok)
                return loginstatus;

        }
    }
    if(loginstatus==false)
    {
        message.setText("username or password is incorrect!");
        message.setStandardButtons(QMessageBox::Ok);
        if(message.exec() == QMessageBox::Ok)
            return loginstatus;
    }
}

void Application::logout()
{
    refresh(getplayerID());
    savePlayersData();
}

void Application::setCurrentPlayer(int ID)
{
    for (int i = 0; i < playerlist.size(); i++)
    {
        if (playerlist[i].get_ID() == ID)
            currentPlayer = &playerlist[i];
    }
}

bool Application::setScoreboard(int ID)
{
    for (int i = 0; i < playerlist.size(); i++)
        if (playerlist[i].get_ID() == ID)
            return true;
    return false;
}

bool Application::setMap(int ID)
{
    for (int i = 0; i < playerlist.size(); i++)
        if (playerlist[i].get_ID() == ID)
            return true;
    return false;
}

int Application::getplayerID()
{
    return playerID;
}
