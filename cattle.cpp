#include "cattle.h"
#include "ui_cattle.h"

Cattle::Cattle(QWidget *parent,Player &current_player) :
    QDialog(parent),
    ui(new Ui::Cattle)
{
    ui->setupUi(this);
    capacity=2;
    level=1;

}

Cattle::~Cattle()
{
    delete ui;
}
void Cattle::levelup(Player &current_player){
    int _coins=current_player.get_coins();
    int _nail=current_player.getNail();
    int _xp;
    if(current_player.getNail()>=2 && current_player.get_coins()>=15 && current_player.get_level()>=5){
        _coins-=15;
        _nail-=2;
        _xp+=6;
        capacity*=2;
        current_player.setNail(_nail);
        current_player.set_coins(_coins);
        current_player.set_XP(_xp);
    }
    else{
        //Message
    }

}

void Cattle::feed(Player &current_player)
{
    if(current_player.getHay()>=2*current_player.getCow()){
        int _hay=current_player.getHay();
        feed_check=true;
        _hay-=current_player.getCow()*2;
        current_player.setHay(_hay);
    }
}
