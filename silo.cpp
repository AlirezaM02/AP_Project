#include "silo.h"
#include "ui_silo.h"

Silo::Silo(QWidget *parent, Player &current_player) : QDialog(parent),
                                                      ui(new Ui::Silo)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    capacity = 10;
    level = 1;
    QString lev = QString::number(level);
    ui->levellbl->setText(lev);
    QString wheatnum = QString::number(current_player.getWheat());
    ui->wheatlbl->setText(wheatnum);
    QString cap = QString::number(capacity);
    ui->capacitlbl->setText(cap);
}

Silo::~Silo()
{
    delete ui;
}

void Silo::set_capacity()
{
}

void Silo::levelup(Player &current_player)
{
    int _coins = current_player.get_coins();
    int _nails = current_player.getNail();

    _coins -= 100 * (2 ^ (2 * level));
    _nails -= (level * 2);
    capacity *= 2;
    level++;
    current_player.set_coins(_coins);
    current_player.setNail(_nails);
}

void Silo::on_upgradebtn_clicked(Player &current_player)
{
    int _coins = current_player.get_coins();
    int _nails = current_player.getNail();
    if ((_coins >= 100 * (2 ^ (2 * level))) && (_nails >= (level * 2)))
        levelup(current_player);

    else
    {
        message->setText("No Inventory");
        message->exec();
    }
}
