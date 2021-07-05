#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QDialog>
#include <QVector>
#include <algorithm>
#include <vector>
#include "player.h"
using std::vector;

class showPlayers
{
    int level, XP, ID;
    QString name;
public:
    showPlayers(int _ID, QString _name, int _level, int _XP)
    {
        ID = _ID;
        name = _name;
        XP = _XP;
        level = _level;
    }
    void setLevel(int newLevel);
    void setXP(int newXP);
    int getID() const;
    void setID(int newID);
    int getXP() const;
    int getLevel() const;
    const QString &getName() const;
    void setName(const QString &newName);
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
