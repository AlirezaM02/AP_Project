#include "cattle.h"
#include "ui_cattle.h"

Cattle::Cattle(QWidget *parent,Player &current_player) :
    QDialog(parent),
    ui(new Ui::Cattle)
{
    ui->setupUi(this);
        setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint | Qt::BypassWindowManagerHint | Qt::WindowTitleHint);
    capacity=2;
    level=1;
    feed_check=false;
    QString lev=QString::number(level);
    ui->levellbl->setText(lev);
    QString cownum=QString::number(current_player.getCow());
    ui->cowlbl->setText(cownum);
    QString cap=QString::number(capacity);
    ui->capacitylbl->setText(cap);

}

Cattle::~Cattle()
{
    delete ui;
}

void Cattle::set_capacity()
{

}
void Cattle::levelup(Player &current_player){
    int _coins=current_player.get_coins();
    int _nail=current_player.getNail();
    int _xp= current_player.get_XP();

        _coins-=15;
        _nail-=2;
        _xp+=6;
        capacity*=2;
        current_player.setNail(_nail);
        current_player.set_coins(_coins);
        current_player.set_XP(_xp);


}


void Cattle::feed(Player &current_player)
{
    int _hay=current_player.getHay();
    int needed_hay= 2*current_player.getCow();
    if((_hay>=needed_hay) && (!feed_check))
    {
        feed_check = true;
        _hay -= needed_hay;
        current_player.setHay(_hay);
    }
    else{
        //Message
    }
}

void Cattle::on_pushButton_clicked(Player &current_player)
{
    int _coins=current_player.get_coins();
    int _nail=current_player.getNail();
    int _xp= current_player.get_XP();
    if(current_player.getNail()>=2 && current_player.get_coins()>=15 && current_player.get_level()>=5){
        levelup(current_player);
    }
    else
    {
        QMessageBox* message=new QMessageBox(this);
        message->setText("No Inventory");
        message->exec();
    }
}


void Cattle::on_feedbtn_clicked(Player &current_player)
{
    int _hay=current_player.getHay();
    int needed_hay= 2*current_player.getCow();
    if((_hay>=needed_hay) && (!feed_check))
    {
       feed(current_player);
    }
    else{
        QMessageBox* message=new QMessageBox(this);
        message->setText("No Inventory");
        message->exec();
    }
}


void Cattle::on_pushButton_4_clicked()
{
     this->close();
}

