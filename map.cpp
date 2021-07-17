#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent, Player &currentPlayer, int playerID, QVector<Player> &players) :
    QWidget(parent),
    ui(new Ui::Map)
{
    silo = new Silo(NULL, currentPlayer->getNail(), currentPlayer->getCoins(), currentPlayer->getWheat());
    warehouse= new Warehouse(NULL, currentPlayer->getCoins(), currentPlayer->getNail(),
                             currentPlayer->getShovel(), currentPlayer->getHay(),
                             currentPlayer->getEgg(), currentPlayer->getMilk(), currentPlayer->getWool());
    if (currentPlayer->get_level() >= 4) {}
}

Map::~Map()
{
    delete ui;
}
