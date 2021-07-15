#include "silo.h"
#include "ui_silo.h"

Silo::Silo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Silo)
{
    ui->setupUi(this);
}

Silo::~Silo()
{
    delete ui;
}

void Silo::setWheat_amount(int newWheat_amount)
{
    wheat_amount = newWheat_amount;
}

int Silo::getWheat_amount() const
{
    return wheat_amount;
}
