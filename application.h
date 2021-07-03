#ifndef APPLICATION_H
#define APPLICATION_H
#include <QFile>
#include <QJsonArray>
#include<QJsonObject>
#include <QVector>
#include <QString>
#include "player.h"
class Application
{
private:
    QVector <Player> playerlist;
    Player currentPlayer;
public:
    Application();
    ~Application();
    void savePlayersData();
    void fetchPlayersData();
    Player *findPlayer(QString username);
    bool login(QString username, QString password);
    void logout();
    void setCurrentUser(int accID);
};

#endif // APPLICATION_H
