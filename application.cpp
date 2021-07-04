#include "application.h"

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
        playerObj["XP"] = playerlist[i].getXP();
        playerObj["coins"] = playerlist[i].get_coins();
        //playerObj["map"]=playerlist[i].getMap();
        mainArray.append(playerObj);
    }
    mainObj["users"] = mainArray;
    QByteArray byteArray;
    byteArray = QJsonDocument(mainObj).toJson();
    QFile file("C:\\Users\\Alireza\\My Documents\\GitRepos\\AP_Project\\data\\data.json");
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
    QTextStream ts(stdout);
    ts << QDir::currentPath();
    QFile file("C:\\Users\\Alireza\\My Documents\\GitRepos\\AP_Project\\data\\data.json");
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
        playerlist.push_back(Player(coins, XP, level, name, username, password, email));
    }
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
    for (int i = 0; i < playerlist.size(); i++)
    {
        if (playerlist[i].get_username() == username && playerlist[i].get_password() == password)
        {
            currentPlayer = &playerlist[i];
            playerID = playerlist[i].get_ID();
            //TODO
            savePlayersData();
            return true;
        }
    }
    return false;
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

int Application::getplayerID()
{
    return playerID;
}
