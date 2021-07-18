#include "map.h"
#include "ui_map.h"
#include "map.h"
#include "ui_map.h"
Map::Map(QWidget *parent, Player& _current_player, int ID , QVector<Player> &players ):
    QDialog(parent), current_player(_current_player),
    ui(new Ui::Map)
{
    current_player=_current_player;
    connect(this, SIGNAL(send_Player(Player&)), this , SLOT(on_nextdaybtn_clicked(Player&)));
    silo= new Silo(this, current_player);
    warehouse= new Warehouse(this, current_player);
    if(current_player.get_level()>=4 && current_player.getNail() >= 3 && current_player.getShovel()>=1 && current_player.get_coins()>=20 )
    {
        cattle = new Cattle(this, current_player);
        int _xp=current_player.get_XP();
        _xp+=10;
        current_player.set_XP(_xp);
    }
    ui->setupUi(this);
    ui->daylbl->setText(QString::number(current_player.getDay()));
    ui->userlbl->setText(current_player.get_username());
}

Map::~Map()
{
    delete ui;
}

void Map::on_nextdaybtn_clicked()
{

    qDebug()<<"on next btn clicked!";
    int DAY= current_player.getDay();
    DAY++;
    current_player.setDay(DAY);
    ui->daylbl->setText(QString::number(current_player.getDay()));
}

