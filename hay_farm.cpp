#include "hay_farm.h"
#include "ui_hay_farm.h"

Hay_Farm::Hay_Farm(QWidget *parent, Player& current_player) :
    QDialog(parent),
    ui(new Ui::Hay_Farm)
{
    ui->setupUi(this);
    area = 4;
    plow_check = false;
    message = new QMessageBox(this);
}

Hay_Farm::~Hay_Farm()
{
    delete ui;
}

void Hay_Farm::levelup(Player &current_player)
{
    int _shovel = current_player.getShovel();
    int _coins = current_player.get_coins();
    int _xp = current_player.get_XP();
    if (_shovel >= 2 * area && _coins >= 5 * area && current_player.get_level() >= 4)
    {
        area *= 2;
        _xp += 3;
        _shovel -= 2 * area;
        _coins -= 5 * area;
    }
}

void Hay_Farm::plow(Player& current_player)
{
    int _coins = current_player.get_coins();
    if ((current_player.get_coins() >= 5 * area) && (!plow_check))
    {
        plow_check = true;
        _coins -= 5 * area;
        current_player.set_coins(_coins);
    }

    else
    {
        if (plow_check)
            message->setText("Already Done :)");

        else if (current_player.get_coins() <= 5 * area)
            message->setText("Not Enough coins");

        message->exec();
    }
}
