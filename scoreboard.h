#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QDialog>
#include <QVector>
#include <algorithm>
#include <vector>
#include "player.h"
#include <QVector>
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>
#include <QDir>
using std::vector;

class showPlayers
{
    int level, XP, ID;
    QString username;
public:
    showPlayers(int _ID, QString _username, int _level, int _XP)
    {
        ID = _ID;
        username = _username;
        XP = _XP;
        level = _level;
    }
    void setLevel(int newLevel);
    void setXP(int newXP);
    int getID() const;
    void setID(int newID);
    int getXP() const;
    int getLevel() const;
    const QString &getUsername() const;
    void setUsername(const QString &newUsername);
};

namespace Ui {
class Scoreboard;
}

class Scoreboard : public QDialog
{
    Q_OBJECT

public:
    explicit Scoreboard(QWidget *parent);
    ~Scoreboard();

private:
    Ui::Scoreboard *ui;
    QVector <showPlayers> players;
};

#endif // SCOREBOARD_H
