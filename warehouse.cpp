#include "warehouse.h"
#include "ui_warehouse.h"

Warehouse::Warehouse(QWidget *parent, Player &current_player) : QDialog(parent),
                                                                ui(new Ui::Warehouse)
{
    ui->setupUi(this);
    this->setFixedSize(this->geometry().width(), this->geometry().height());
    level = 1;
    capacity = 5;
    int inv = current_player.getNail() + current_player.getShovel() + current_player.getSheep() + current_player.getMilk() + current_player.getHay() + current_player.getEgg();
    QString nail = QString::number(current_player.getNail());
    QString shovel = QString::number(current_player.getShovel());
    QString sheep = QString::number(current_player.getSheep());
    QString milk = QString::number(current_player.getMilk());
    QString hay = QString::number(current_player.getHay());
    QString egg = QString::number(current_player.getEgg());
    QString lev = QString::number(level);
    QString cap = QString::number(capacity);
    QString inventory = QString::number(inv);

    ui->capacitylbl->setText(cap);
    ui->levellbl->setText(lev);
    ui->invlbl->setText(inventory);
    ui->naillbl->setText(nail);
    ui->shovellbl->setText(shovel);
    ui->sheeplbl->setText(sheep);
    ui->milklbl->setText(milk);
    ui->haylbl->setText(hay);
    ui->egglbl->setText(egg);
}

Warehouse::~Warehouse()
{
    delete ui;
}

void Warehouse::set_capacity()
{
}

void Warehouse::levelup(Player &current_player)
{
    int _nails = level;
    int _shovels = level - 1;
    int _coins = ((level) ^ 3) * 100;

    level++;
    _nails -= _nails;
    _shovels -= _shovels;
    _coins -= _coins;
    current_player.setNail(_nails);
    current_player.setShovel(_shovels);
    current_player.set_coins(_coins);
}

int Warehouse::get_inv()
{
    return inv;
}

void Warehouse::on_pushButton_clicked(Player &current_player)
{
    int _nails = level;
    int _shovels = level - 1;
    int _coins = ((level) ^ 3) * 100;
    if ((current_player.getNail() >= _nails) && (current_player.getShovel() >= _shovels) && (current_player.get_coins() >= (_coins)))
    {
        levelup(current_player);
    }
    else
    {
        QMessageBox *message = new QMessageBox(this);
        message->setText("No Inventory");
        message->exec();
    }
}
