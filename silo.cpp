#include "silo.h"
#include "ui_silo.h"


Silo::Silo(QWidget *parent, long &nails, long &coins, long &wheat) :
    QDialog(parent),
    ui(new Ui::Silo)
{
    ui->setupUi(this);
    capacity=10;
    level=1;
}

Silo::~Silo()
{
    delete ui;
}

void Silo::set_capacity()
{

}
void Silo::levelup()
{

}

void Silo::levelup(long &cois)
{

}
void Silo::levelup(long int &coins , long int& nails)
{
    if((coins >= 100*(2^(2*level)))&& (nails>=(level*2)))
    {

        coins -= 100*(2^(2*level));
        nails-= (level*2);
        capacity*=2;
        level++;

    }
    else
    {
        //message!
    }
}

void Silo::levelup(long &coins, long int &nails, long int &shovel)
{

}

void Silo::rise_experience()
{

}

void Silo::check_buildings_level()
{

}
