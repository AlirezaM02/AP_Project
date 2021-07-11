#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QDialog>
#include <QVector>
#include <algorithm>
#include <vector>
#include <QString>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QTextStream>
#include <QDir>
#include <QTableWidgetItem>
#include <iostream>
#include "player.h"

namespace Ui {
class Scoreboard;
}

class Scoreboard : public QDialog
{
    Q_OBJECT

public:
    explicit Scoreboard(QWidget *parent, QVector<Player>&players);
    ~Scoreboard();

private:
    Ui::Scoreboard *ui;

};

#endif // SCOREBOARD_H
