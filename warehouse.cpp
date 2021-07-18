#include "warehouse.h"
#include "ui_warehouse.h"

Warehouse::Warehouse(QWidget *parent, long &coins, long &nail, long &shovel, long &hay, long &egg, long &milk, long &wool):
    QDialog(parent),
    ui(new Ui::Warehouse)
{
    ui->setupUi(this);
    level=1;
    capacity=5;

}

Warehouse::~Warehouse()
{
    delete ui;
}

void Warehouse::set_capacity()
{

}

void Warehouse::levelup()
{

}

void Warehouse::levelup(Player &current_player)
{
    int _nails= level;
    int _shovels =level-1;
    int _coins = ((level)^3)*100;
    if((current_player.getNail()>=_nails)&&(current_player.getShovel()>=_shovels)&&(current_player.get_coins()>=(_coins)))
    {
        level++;
        _nails-=_nails;
        _shovels-=_shovels;
        _coins-=_coins;
        current_player.setNail(_nails);
        current_player.setShovel(_shovels);
        current_player.set_coins(_coins);

    }
    else
    {
        //message!
    }

}



void Warehouse::rise_experience()
{

}

void Warehouse::check_buildings_level()
{

}
