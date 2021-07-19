#ifndef MAP_H
#define MAP_H

#include <QDialog>
#include "cattle.h"
#include "player.h"
#include "silo.h"
#include "warehouse.h"
#include "cattle.h"
#include "poultry.h"
#include "sheep_farm.h"
#include "farm.h"
#include "wheat_farm.h"
#include "hay_farm.h"
#include "shop.h"

namespace Ui { class Map; }

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent, Player &current_player, int ID , QVector<Player> &players);
    ~Map();

private slots:
    void on_nextdaybtn_clicked();
    void on_exitBtn_clicked();

signals:
    void send_Player(Player&);
    void exitBtn_clicked();

private:
    Silo *silo;
    Warehouse *warehouse;
    Cattle *cattle;
    Poultry *poultry;
    Sheep_Farm *sheepfarm;
    Wheat_Farm *wheatfarm;
    Hay_Farm *hayfarm;
    Shop *shop;
    Ui::Map *ui;
    Player &current_player;
};

#endif // MAP_H
