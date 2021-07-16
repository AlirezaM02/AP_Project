#include "cattle.h"
#include "ui_cattle.h"

Cattle::Cattle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Cattle)
{
    ui->setupUi(this);
}

Cattle::~Cattle()
{
    delete ui;
}
