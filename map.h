
#ifndef MAP_H
#define MAP_H
#include "cattle.h"
#include <QDialog>
#include "player.h"
#include "silo.h"
#include "warehouse.h"
#include "cattle.h"
#include <poultry.h>
#include "sheep_farm.h"
#include <farm.h>
#include <wheat_farm.h>
#include <hay_farm.h>
namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent, Player& current_player, int ID , QVector<Player>&players );
    ~Map();

private slots:
    void on_nextdaybtn_clicked();
signals:
    void send_Player(Player&);
private:
    Silo* silo;
    Warehouse* warehouse;
    Cattle* cattle;
    Poultry* poultry;
    Sheep_Farm* sheepfarm;
    Wheat_Farm* wheatfarm;
    Hay_Farm* hayfarm;
    Ui::Map *ui;
    Player& current_player;
};

#endif // MAP_H
