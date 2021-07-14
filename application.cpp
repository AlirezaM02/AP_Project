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
        playerObj["level"] = playerlist[i].get_level();
        playerObj["XP"] = playerlist[i].get_XP();
        playerObj["coins"] = playerlist[i].get_coins();
        //playerObj["map"]=playerlist[i].getMap();
        mainArray.append(playerObj);
    }
    mainObj["users"] = mainArray;
    QByteArray byteArray;
    byteArray = QJsonDocument(mainObj).toJson();
    QFile file("C:\\data.json");
    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "No write access for json file";
        return;
    }
    file.write(byteArray);
    file.close();
}

void Application::fetchPlayersData()
{
    playerlist.erase(playerlist.begin(), playerlist.end());
    QFile file("D:\\data.json");
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
        long int coins = val.toObject().value("coins").toInteger(), XP = val.toObject().value("XP").toInteger();
        int level = val.toObject().value("level").toInteger();
        QString name = val.toObject().value("name").toString(), username = val.toObject().value("username").toString(),
                password = val.toObject().value("password").toString(), email = val.toObject().value("email").toString();
        //Map _map;
        playerlist.push_back(Player(name, username, password, email, coins, XP, level));
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
            loginstatus=true;
            savePlayersData();
            if(message.exec()==QMessageBox::Ok)
                return loginstatus;

        }
    }
    if(loginstatus==false)
    {
        message.setText("username or password is incorrect!");
        message.setStandardButtons(QMessageBox::Ok);
        if(message.exec()==QMessageBox::Ok)
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

int Application::getplayerID()
{
    return playerID;
}
