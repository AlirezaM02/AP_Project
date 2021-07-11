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
#include <QTableWidgetItem>
#include <iostream>

using std::vector;

namespace Ui {
class Scoreboard;
}

class Scoreboard : public QDialog
{
    Q_OBJECT

public:
    explicit Scoreboard(QWidget *parent, vector<Player> players);
    ~Scoreboard();

private:
    Ui::Scoreboard *ui;
    QVector <Player> players;
};

#endif // SCOREBOARD_H
