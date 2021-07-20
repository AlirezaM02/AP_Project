#include "poultry.h"
#include "ui_poultry.h"

Poultry::Poultry(QWidget *parent,Player &current_player) :
    QDialog(parent),
    ui(new Ui::Poultry)
{
    ui->setupUi(this);
     this->setFixedSize(this->geometry().width(), this->geometry().height());
    capacity=2;
    level=1;
    feed_check=false;

}

Poultry::~Poultry()
{
    delete ui;
}

void Poultry::set_capacity()
{

}

void Poultry::levelup(Player &current_player)
{
    int _nail=current_player.getNail();
    int _coins=current_player.get_coins();
    int _xp=current_player.get_XP();
    if(_nail>=1 && _coins>=10 && current_player.get_level()>=3){
        capacity*=2;
        _nail-=1;
        _coins-=10;
        _xp+=5;
        current_player.setNail(_nail);
        current_player.set_coins(_coins);
        current_player.set_XP(_xp);
    }
    else{
        //Message
    }
}

void Poultry::feed(Player &current_player)
{
    int _wheat=current_player.getWheat();
    int needed_wheat= current_player.getHen();
    if((_wheat>=needed_wheat) && (!feed_check))
    {
        feed_check = true;
        _wheat -= needed_wheat;
        current_player.setHay(_wheat);
    }
    else{
        //Message
    }
}
