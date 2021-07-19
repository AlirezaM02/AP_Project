#include "shop.h"
#include "ui_shop.h"

Shop::Shop(QWidget *parent ,Player* current_player) :
    QDialog(parent),
    ui(new Ui::Shop)
{
    ui->setupUi(this);
}

Shop::~Shop()
{
    delete ui;
}

void Shop::sell_wheat()
{

}
