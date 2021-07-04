#ifndef APPLICATION_H
#define APPLICATION_H

#include <QVector>
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>
#include <QDir>
#include "player.h"

class Application
{
private:
    QVector <Player> playerlist;
    Player *currentPlayer;
    int playerID;
public:
    Application();
    ~Application();
    void savePlayersData();
    void fetchPlayersData();
    Player *findPlayer(QString username);
    bool login(QString username, QString password);
    void logout();
    void refresh();
    void refresh(int ID);
    int getplayerID();
    void setCurrentPlayer(int ID);
};

#endif // APPLICATION_H
