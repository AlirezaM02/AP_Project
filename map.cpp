#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent, Player &currentPlayer, int playerID, QVector<Player> &players) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
}

Map::~Map()
{
    delete ui;
}
