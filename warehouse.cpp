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

void Warehouse::levelup(long &coins)
{

}

void Warehouse::levelup(long &coins, long &nail, long &shovel)
{
    int _nails= level;
    int _shovels =level-1;
    int _coins = ((level)^3)*100;
    if((nail>=_nails)&&(shovel>=_shovels)&&(coins>=(_coins)))
    {
        level++;
        nail-=_nails;
        shovel-=_shovels;
        coins-=_coins;

    }
    else
    {
        //message!
    }

}

void Warehouse::levelup(long &coins, long int& nails)
{

}

void Warehouse::rise_experience()
{

}

void Warehouse::check_buildings_level()
{

}
