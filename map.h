#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include "player.h"

namespace Ui { class Map; }

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent, Player &currentPlayer, int playerID, QVector <Player> &players);
    ~Map();

private:
    Ui::Map *ui;
};

#endif // MAP_H
