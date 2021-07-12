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
#include "login.h"

class Application
{
private:
    static int playerCounter;
    static int lastID;
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
    bool setscoreboard(int ID);
    Player *getCurrentPlayer() const;
    const QVector<Player> &getPlayerlist() const;
    QVector<Player> &getPalayerlistref()    { return playerlist; }
    const QVector<Player> &getPalayerlistref() const { return playerlist; }
    void log_in();
    void addPlayer(Player player); // Preferred
    void addPlayer(QString name, QString username, QString password, QString email);
};

#endif // APPLICATION_H
