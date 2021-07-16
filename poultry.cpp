#include "poultry.h"
#include "ui_poultry.h"

Poultry::Poultry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Poultry)
{
    ui->setupUi(this);
}

Poultry::~Poultry()
{
    delete ui;
}
