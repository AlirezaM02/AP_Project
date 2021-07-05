#include "scoreboard.h"
#include "ui_scoreboard.h"

Scoreboard::Scoreboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scoreboard)
{
    std::sort(players.begin(), players.end(), [](showPlayers p1, showPlayers p2)
    {
        if (p1.getLevel() > p2.getLevel()) return true;
        else if (p1.getLevel() == p2.getLevel())
            if (p1.getXP() > p2.getXP())
                return true;
        return false;
    }
    );
    ui->setupUi(this);
}

Scoreboard::~Scoreboard()
{
    delete ui;
}

void showPlayers::setXP(int newXP)
{
    XP = newXP;
}

int showPlayers::getXP() const
{
    return XP;
}

void showPlayers::setID(int newID)
{
    ID = newID;
}

int showPlayers::getID() const
{
    return ID;
}

void showPlayers::setLevel(int newLevel)
{
    level = newLevel;
}

int showPlayers::getLevel() const
{
    return level;
}

void showPlayers::setName(const QString &newName)
{
    name = newName;
}

const QString &showPlayers::getName() const
{
    return name;
}
