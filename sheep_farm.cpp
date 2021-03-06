#include "sheep_farm.h"
#include "ui_sheep_farm.h"

Sheep_Farm::Sheep_Farm(QWidget *parent, Player &current_player) : QDialog(parent),
                                                                  ui(new Ui::Sheep_Farm)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog | Qt::WindowStaysOnTopHint | Qt::BypassWindowManagerHint | Qt::WindowTitleHint);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    capacity = 2;
    level = 1;
    feed_check = false;

    QString lev = QString::number(level);
    QString cap = QString::number(capacity);
    QString sheepnum = QString::number(current_player.getSheep());
    ui->sheeplbl->setText(sheepnum);
    ui->levellbl->setText(lev);
    ui->capacitylbl->setText(cap);
}

Sheep_Farm::~Sheep_Farm()
{
    delete ui;
}

void Sheep_Farm::set_capacity()
{
}

void Sheep_Farm::levelup(Player &current_player)
{
    int _nail = current_player.getNail();
    int _shovel = current_player.getShovel();
    int _coins = current_player.get_coins();
    int _xp = current_player.get_XP();

    capacity *= 2;
    _nail -= 3;
    _coins -= 50;
    _shovel -= 1;
    _xp += 15;
    current_player.setNail(_nail);
    current_player.set_coins(_coins);
    current_player.setShovel(_shovel);
    current_player.set_XP(_xp);
}

void Sheep_Farm::feed(Player &current_player)
{
    int _hay = current_player.getHay();
    int needed_hay = current_player.getSheep();

    feed_check = true;
    _hay -= needed_hay;
    current_player.setHay(_hay);
}

void Sheep_Farm::on_upgradebtn_clicked(Player &current_player)
{
    int _nail = current_player.getNail();
    int _shovel = current_player.getShovel();
    int _coins = current_player.get_coins();

    if (_nail >= 3 && _shovel >= 1 && _coins >= 50 && current_player.get_level() >= 7)
        levelup(current_player);

    else
    {
        message->setText("Not enough Inventory");
        message->exec();
    }
}

void Sheep_Farm::on_feedbtn_clicked(Player &current_player)
{
    int _hay = current_player.getHay();
    int needed_hay = current_player.getSheep();

    if ((_hay >= needed_hay) && (!feed_check))
        levelup(current_player);

    else
    {
        message->setText("Lack Of Hay!");
        message->exec();
    }
}

void Sheep_Farm::on_pushButton_4_clicked()
{
    this->close();
}
