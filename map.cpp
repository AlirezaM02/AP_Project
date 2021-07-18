#include "map.h"
#include "ui_map.h"
#include "map.h"
#include "ui_map.h"
Map::Map(QWidget *parent, Player& current_player, int ID , QVector<Player> &players ):
    QDialog(parent),
    ui(new Ui::Map)
{
    emit send_Player(current_player);
    connect(this, SIGNAL(send_Player(Player&)), this , SLOT(on_nextdaybtn_clicked(Player&)));
    silo= new Silo(this, current_player);
    warehouse= new Warehouse(this, current_player);
    if (current_player.get_level()>=4)
    {

    }
    ui->setupUi(this);
    ui->daylbl->setText(QString::number(current_player.getDay()));
    ui->userlbl->setText(current_player.get_username());
}

Map::~Map()
{
    delete ui;
}

void Map::on_nextdaybtn_clicked(Player& current_player)
{
    qDebug()<<"on next btn clicked!";
    int DAY= current_player.getDay();
    DAY++;
    current_player.setDay(DAY);
}

