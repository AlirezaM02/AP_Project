#ifndef APPLICATION_H
#define APPLICATION_H

#include <QVector>
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QMessageBox>
#include "player.h"
#include "login.h"

class Application
{
private:
    static int playerCounter;
    static int lastID;
    QVector <Player> playerlist;
    Player *currentPlayer;
    int playerID;
    QMessageBox message;
    bool loginstatus= false;

public:
    Application();
    ~Application();

    void savePlayersData();
    void fetchPlayersData();

    bool login(QString username, QString password);
    void logout();
    void refresh();
    void refresh(int ID);

    bool setScoreboard(int ID);
    bool setMap(int ID);
    //bool setMap(Player player);
    void setCurrentPlayer(int ID);

    int getplayerID();
    const QVector<Player> &getPlayerlist() const;
    QVector<Player> &getPlayerlistref()    { return playerlist; }
    const QVector<Player> &getPlayerlistref() const { return playerlist; }
    Player *getCurrentPlayer() const;
    Player *findPlayer(QString username);

    void addPlayer(Player player); // Preferred
    void addPlayer(QString name, QString username, QString password, QString email);
};

#endif // APPLICATION_H
