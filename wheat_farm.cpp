#include "wheat_farm.h"
#include "ui_wheat_farm.h"

Wheat_Farm::Wheat_Farm(QWidget *parent,Player& current_player) :
    QDialog(parent),
    ui(new Ui::Wheat_Farm)
{
    ui->setupUi(this);
     this->setFixedSize(this->geometry().width(), this->geometry().height());
    area =5;
    planting_area=0;
}

Wheat_Farm::~Wheat_Farm()
{
    delete ui;
}

void Wheat_Farm::levelup(Player &current_player)
{
    int _shovel=current_player.getShovel();
    int _coins=current_player.get_coins();
    int _xp=current_player.get_XP();
    if(_shovel>=area && _coins>= area*5 && current_player.get_level()>=2){
        area*=2;
        _shovel-=area;
        _coins-=area*5;
        _xp+=3;
        current_player.set_coins(_coins);
        current_player.setShovel(_shovel);
        current_player.set_XP(_xp);
    }
    else {
        //Message
    }
}
