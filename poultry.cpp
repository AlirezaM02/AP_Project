#include "poultry.h"
#include "ui_poultry.h"

Poultry::Poultry(QWidget *parent, Player &current_player) : QDialog(parent),
                                                            ui(new Ui::Poultry)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint | Qt::BypassWindowManagerHint | Qt::WindowTitleHint);
    this->setFixedSize(this->geometry().width(), this->geometry().height());

    capacity = 2;
    level = 1;
    feed_check = false;

    QString lev = QString::number(level);
    QString cap = QString::number(capacity);
    QString hennum = QString::number(current_player.getHen());

    ui->capacitylbl->setText(cap);
    ui->levellbl->setText(lev);
    ui->henlbl->setText(hennum);
}

Poultry::~Poultry()
{
    delete ui;
}

void Poultry::set_capacity() {}

void Poultry::levelup(Player &current_player)
{
    int _nail = current_player.getNail();
    int _coins = current_player.get_coins();
    int _xp = current_player.get_XP();

    capacity *= 2;
    _nail -= 1;
    _coins -= 10;
    _xp += 5;

    current_player.setNail(_nail);
    current_player.set_coins(_coins);
    current_player.set_XP(_xp);
}

void Poultry::feed(Player &current_player)
{
    int _wheat = current_player.getWheat();
    int needed_wheat = current_player.getHen();

    feed_check = true;
    _wheat -= needed_wheat;
    current_player.setHay(_wheat);
}

void Poultry::on_feedbtn_clicked(Player &current_player)
{
    int _wheat = current_player.getWheat();
    int needed_wheat = current_player.getHen();

    if ((_wheat >= needed_wheat) && (!feed_check))
    {
        levelup(current_player);
    }
    else
    {
        if (_wheat <= needed_wheat)
            message->setText("Lack Of Wheat !");
        else
            message->setText("Already Done");
        message->exec();
    }
}

void Poultry::on_eggcollectbtn_clicked(Player &current_player)
{
}

void Poultry::on_upgradebtn_clicked(Player &current_player)
{
    int _nail = current_player.getNail();
    int _coins = current_player.get_coins();

    if (_nail >= 1 && _coins >= 10 && current_player.get_level() >= 3)
        levelup(current_player);

    else
    {
        message->setText("Lack Of Inventory !");
        message->exec();
    }
}

void Poultry::on_pushButton_2_clicked()
{
    this->close();
}
