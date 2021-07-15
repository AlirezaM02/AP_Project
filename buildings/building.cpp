#include "building.h"
#include "ui_building.h"

Building::Building(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Building)
{
    ui->setupUi(this);
}

Building::~Building()
{
    delete ui;
}

