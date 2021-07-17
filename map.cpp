#include "map.h"
#include "ui_map.h"
#include "map.h"
#include "ui_map.h"
Map::Map(QWidget *parent, Player& current_player, int ID , QVector<Player> &players ):
    QDialog(parent),
    ui(new Ui::Map)
{
    silo= new Silo(this, current_player.getNailref(), current_player.getcoinsref(), current_player.getWheatref());
    warehouse= new Warehouse(this, current_player.getcoinsref(), current_player.getNailref(), current_player.getShovelref(), current_player.getHayref(), current_player.getEggref(), current_player.getMilkref(), current_player.getWoolref());
    ui->setupUi(this);
    if (current_player.get_level()>=4)
    {

    }
}

Map::~Map()
{
    delete ui;
}
