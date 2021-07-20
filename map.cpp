#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent, Player& _current_player, int ID , QVector<Player> &players ):
    QDialog(parent), ui(new Ui::Map), current_player(_current_player)
{
    ui->setupUi(this);

    current_player = _current_player;

    connect(this, SIGNAL(send_Player(Player&)), this , SLOT(on_nextdaybtn_clicked(Player&)));
    connect(ui->exitBtn, SIGNAL(pressed()), this, SLOT(on_exitBtn_clicked()));

    silo = new Silo(this, current_player);
    warehouse = new Warehouse(this, current_player);
    wheatfarm = new Wheat_Farm(this, current_player);
    shop = new Shop(this, current_player);

    ui->cattlebtn->setDisabled(true);
    if (current_player.get_level() >= 4 && current_player.getNail() >= 3 && current_player.getShovel() >= 1 && current_player.get_coins() >= 20 )
    {
        ui->cattlebtn->setEnabled(true);
        int _nail = current_player.getNail();
        int _shovel = current_player.getShovel();
        int _coins = current_player.get_coins();

        cattle = new Cattle(this, current_player);// check first time

        int _xp = current_player.get_XP();
        _xp += 10;
        _nail -= 3;
        _shovel -= 1;
        _coins -= 20;
        current_player.set_XP(_xp);
        current_player.set_coins(_coins);
        current_player.setShovel(_shovel);
        current_player.setNail(_nail);
    }
    ui->poulterybtn->setDisabled(true);
    if (current_player.getNail() >= 2 && current_player.get_coins() >= 10 && current_player.get_level() >= 2){
        poultry = new Poultry(this, current_player); // check first time
        ui->poulterybtn->setEnabled(true);
        int _xp = current_player.get_XP();
        int _nail = current_player.getNail();
        int _coins = current_player.get_coins();
        _nail -= 2;
        _coins -= 10;
        _xp += 5;
        current_player.set_XP(_xp);
        current_player.set_coins(_coins);
        current_player.setNail(_nail);
    }
   ui->sheepfarmbtn->setDisabled(true);
    if (current_player.get_level() >= 6 && current_player.getNail() >= 4 && current_player.getShovel() >= 2 && current_player.get_coins() >= 50)
    {
        ui->sheepfarmbtn->setEnabled(true);
        sheepfarm = new Sheep_Farm(this, current_player);// check first time
        int _xp = current_player.get_XP();
        int _nail = current_player.getNail();
        int _coins = current_player.get_coins();
        _nail -= 4;
        _coins -= 50;
        _xp += 20;
        current_player.set_XP(_xp);
        current_player.set_coins(_coins);
        current_player.setNail(_nail);
    }
        ui->hayfarmbtn->setDisabled(true);
    if (current_player.get_level() >= 3 && current_player.getNail() >= 1 && current_player.getShovel() >= 1 && current_player.get_coins() >= 15)
    {
        ui->hayfarmbtn->setEnabled(true);
        hayfarm = new Hay_Farm(this, current_player);
        int _xp = current_player.get_XP();
        int _nail = current_player.getNail();
        int _coins = current_player.get_coins();
        int _shovel = current_player.getShovel();
        _xp += 6;
        _nail -= 1;
        _coins -= 15;
        _shovel -= 1;
        current_player.set_coins(_coins);
        current_player.setNail(_nail);
        current_player.setShovel(_shovel);
        current_player.set_XP(_xp);
    }

    ui->daylbl->setText(QString::number(current_player.getDay()));
    ui->xplbl->setText(QString::number(current_player.get_XP()));
    ui->levellbl->setText(QString::number(current_player.get_level()));
}

Map::~Map()
{
    delete ui;
}

void Map::on_nextdaybtn_clicked()
{

    qDebug()<<"on next btn clicked!";
    int DAY= current_player.getDay();
    DAY ++;
    current_player.setDay(DAY);
    ui->daylbl->setText(QString::number(current_player.getDay()));
}

void Map::on_exitBtn_clicked()
{
    emit exitBtn_clicked();
}


void Map::on_scoreboardbtn_clicked()
{
    emit scoreboardclicked();
}


void Map::on_cattlebtn_clicked()
{

    cattle->show();
}


void Map::on_poulterybtn_clicked()
{
    poultry->show();
}


void Map::on_silobtn_clicked()
{
    silo->show();
}


void Map::on_warehousebtn_clicked()
{
    warehouse->show();
}


void Map::on_shoptbn_clicked()
{
    shop->show();
}


void Map::on_hayfarmbtn_clicked()
{
    hayfarm->show();
}


void Map::on_wheatfarmbtn_clicked()
{
    wheatfarm->show();
}

