#include "silo.h"
#include "ui_silo.h"


Silo::Silo(QWidget *parent, Player& current_player) :
    QDialog(parent),
    ui(new Ui::Silo)
{
    ui->setupUi(this);
    capacity=10;
    level=1;
}

Silo::~Silo()
{
    delete ui;
}

void Silo::set_capacity()
{

}
void Silo::levelup()
{

}

void Silo::levelup(Player &current_player)
{
    int _coins= current_player.get_coins();
    int _nails= current_player.getNail();
    if(( _coins >= 100*(2^(2*level)))&& (_nails >=(level*2)))
    {

        _coins -= 100*(2^(2*level));
        _nails-= (level*2);
        capacity*=2;
        level++;
        current_player.set_coins(_coins);
        current_player.setNail(_nails);

    }
    else
    {
        //message!
    }
}

void Silo::rise_experience()
{

}

void Silo::check_buildings_level()
{

}
