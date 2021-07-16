#include "sheep_farm.h"
#include "ui_sheep_farm.h"

Sheep_Farm::Sheep_Farm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sheep_Farm)
{
    ui->setupUi(this);
}

Sheep_Farm::~Sheep_Farm()
{
    delete ui;
}
