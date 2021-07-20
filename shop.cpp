#include "shop.h"
#include "ui_shop.h"
#include <QMessageBox>

Shop::Shop(QWidget *parent, Player &current_player) : QDialog(parent),
                                                      ui(new Ui::Shop)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    QString scoin = QString::number(current_player.get_coins());
    ui->show_coinslbl->setText(scoin);
    QString sxp = QString::number(current_player.get_XP());
    ui->show_xplbl->setText(sxp);
}

Shop::~Shop()
{
    delete ui;
}

void Shop::sell_wheat()
{
}

void Shop::on_wheatsellbtn_clicked(Player &current_player)
{
    if (current_player.getWheat() >= ui->numberwheatlbl->text().toInt())
    {
        int _wheat = current_player.getWheat();
        _wheat -= ui->numberwheatlbl->text().toInt();
        current_player.setWheat(_wheat);

        int _coins = current_player.get_coins();
        _coins += ui->numberwheatlbl->text().toInt() * 2;
        current_player.set_coins(_coins);

        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Inventory");
        message->exec();
    }
}

void Shop::on_haysellbtn_clicked(Player &current_player)
{
    if (current_player.getHay() >= ui->numberhaylbl->text().toInt())
    {
        int _hay = current_player.getHay();
        _hay -= ui->numberhaylbl->text().toInt();
        current_player.setHay(_hay);

        int _coins = current_player.get_coins();
        _coins += ui->numberhaylbl->text().toInt() * 4;
        current_player.set_coins(_coins);

        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Inventory");
        message->exec();
    }
}

void Shop::on_hensellbtn_clicked(Player &current_player)
{
    if (current_player.getHen() >= ui->hennumber->text().toInt())
    {
        int _hen = current_player.getHen();
        _hen -= ui->hennumber->text().toInt();
        current_player.setHen(_hen);
        int _coins = current_player.get_coins();
        _coins += ui->hennumber->text().toInt() * 15;
        current_player.set_coins(_coins);
        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Inventory");
        message->exec();
    }
}

void Shop::on_cowsellbtn_clicked(Player &current_player)
{
    if (current_player.getCow() >= ui->cownumber->text().toInt())
    {
        int _cow = current_player.getCow();
        _cow -= ui->cownumber->text().toInt();
        current_player.setCow(_cow);

        int _coins = current_player.get_coins();
        _coins += ui->cownumber->text().toInt() * 50;
        current_player.set_coins(_coins);

        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Inventory");
        message->exec();
    }
}

void Shop::on_sheepsellbtn_clicked(Player &current_player)
{
    if (current_player.getSheep() >= ui->sheepnumber->text().toInt())
    {
        int _sheep = current_player.getSheep();
        _sheep -= ui->sheepnumber->text().toInt();
        current_player.setSheep(_sheep);

        int _coins = current_player.get_coins();
        _coins += ui->sheepnumber->text().toInt() * 70;
        current_player.set_coins(_coins);

        message->setText("Changes Were Applied");
        message->exec();
    }
    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_nailsellbtn_clicked(Player &current_player)
{
    if (current_player.getNail() >= ui->nailnumber->text().toInt())
    {
        int _nail = current_player.getNail();
        _nail -= ui->nailnumber->text().toInt();
        current_player.setNail(_nail);

        int _coins = current_player.get_coins();
        _coins += ui->nailnumber->text().toInt() * 20;
        current_player.set_coins(_coins);

        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_shovelsellbtn_clicked(Player &current_player)
{
    if (current_player.getShovel() >= ui->shovelnumber->text().toInt())
    {
        int _shovel = current_player.getShovel();
        _shovel -= ui->nailnumber->text().toInt();
        current_player.setShovel(_shovel);

        int _coins = current_player.get_coins();
        _coins += ui->shovelnumber->text().toInt() * 30;
        current_player.set_coins(_coins);

        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_milksellbtn_clicked(Player &current_player)
{
    if (current_player.getMilk() >= ui->milknum->text().toInt())
    {
        int _milk = current_player.getMilk();
        _milk -= ui->milknum->text().toInt();
        current_player.setMilk(_milk);

        int _coins = current_player.get_coins();
        _coins += ui->milknum->text().toInt() * 12;
        current_player.set_coins(_coins);

        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_eggsellbtn_clicked(Player &current_player)
{
    if (current_player.getEgg() >= ui->eggnum->text().toInt())
    {
        int _egg = current_player.getEgg();
        _egg -= ui->eggnum->text().toInt();
        current_player.setEgg(_egg);

        int _coins = current_player.get_coins();
        _coins += ui->eggnum->text().toInt() * 8;
        current_player.set_coins(_coins);

        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_woolsellbtn_clicked(Player &current_player)
{
    if (current_player.getWool() >= ui->woolnum->text().toInt())
    {
        int _wool = current_player.getWool();
        _wool -= ui->woolnum->text().toInt();
        current_player.setWool(_wool);

        int _coins = current_player.get_coins();
        _coins += ui->woolnum->text().toInt() * 23;
        current_player.set_coins(_coins);

        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_wheatbuybtn_clicked(Player &current_player)
{
    if (current_player.get_coins() >= 3 * ui->wheatnumb->text().toInt())
    {
        int _coins = current_player.get_coins();
        _coins -= 3 * ui->wheatnumb->text().toInt();
        current_player.set_coins(_coins);

        int _wheat = current_player.getWheat();
        _wheat += ui->wheatnumb->text().toInt();
        current_player.setWheat(_wheat);

        int _xp = current_player.get_XP();
        _xp += 1;
        current_player.set_XP(_xp);
        message->setText("Changes Were Applied");
        message->exec();
    }

    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_haybuybtn_clicked(Player &current_player)
{
    if (current_player.get_coins() >= 6 * ui->haynumb->text().toInt())
    {
        int _coins = current_player.get_coins();
        _coins -= 6 * ui->haynumb->text().toInt();
        current_player.set_coins(_coins);
        int _hay = current_player.getHay();
        _hay += ui->haynumb->text().toInt();
        current_player.setHay(_hay);
        int _xp = current_player.get_XP();
        _xp += 2;
        current_player.set_XP(_xp);
        message->setText("Changes Were Applied");
        message->exec();
    }
    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_henbuybtn_clicked(Player &current_player)
{
    if (current_player.get_coins() >= 20 * ui->hennumb->text().toInt())
    {
        int _coins = current_player.get_coins();
        _coins -= 20 * ui->hennumb->text().toInt();
        current_player.set_coins(_coins);
        int _hen = current_player.getHen();
        _hen += ui->hennumb->text().toInt();
        current_player.setHen(_hen);
        int _xp = current_player.get_XP();
        _xp += 5;
        current_player.set_XP(_xp);
        message->setText("Changes Were Applied");
        message->exec();
    }
    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_cowbuybtn_clicked(Player &current_player)
{
    if (current_player.get_coins() >= 70 * ui->cownumb->text().toInt())
    {
        int _coins = current_player.get_coins();
        _coins -= 70 * ui->cownumb->text().toInt();
        current_player.set_coins(_coins);
        int _cow = current_player.getCow();
        _cow += ui->cownumb->text().toInt();
        current_player.setCow(_cow);
        int _xp = current_player.get_XP();
        _xp += 10;
        current_player.set_XP(_xp);
        message->setText("Changes Were Applied");
        message->exec();
    }
    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_sheepbuybtn_clicked(Player &current_player)
{
    if (current_player.get_coins() >= 80 * ui->sheepnumb->text().toInt())
    {
        int _coins = current_player.get_coins();
        _coins -= 80 * ui->sheepnumb->text().toInt();
        current_player.set_coins(_coins);
        int _sheep = current_player.getSheep();
        _sheep += ui->sheepnumb->text().toInt();
        current_player.setSheep(_sheep);
        int _xp = current_player.get_XP();
        _xp += 15;
        current_player.set_XP(_xp);
        message->setText("Changes Were Applied");
        message->exec();
    }
    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_nailbuybtn_clicked(Player &current_player)
{
    if (current_player.get_coins() >= 30 * ui->nailnumb->text().toInt())
    {
        int _coins = current_player.get_coins();
        _coins -= 30 * ui->nailnumb->text().toInt();
        current_player.set_coins(_coins);
        int _nail = current_player.getNail();
        _nail += ui->nailnumb->text().toInt();
        current_player.setNail(_nail);
        int _xp = current_player.get_XP();
        _xp += 4;
        current_player.set_XP(_xp);
        message->setText("Changes Were Applied");
        message->exec();
    }
    else
    {
        message->setText("No Money");
        message->exec();
    }
}

void Shop::on_shovelbuybtn_clicked(Player &current_player)
{
    if (current_player.get_coins() >= 50 * ui->shovelnumb->text().toInt())
    {
        int _coins = current_player.get_coins();
        _coins -= 50 * ui->shovelnumb->text().toInt();
        current_player.set_coins(_coins);
        int _shovel = current_player.getShovel();
        _shovel += ui->shovelnumb->text().toInt();
        current_player.setShovel(_shovel);
        int _xp = current_player.get_XP();
        _xp += 8;
        current_player.set_XP(_xp);
        message->setText("Changes Were Applied");
        message->exec();
    }
    else
    {
        message->setText("No Money");
        message->exec();
    }
}
