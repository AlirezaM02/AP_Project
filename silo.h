#ifndef SILO_H
#define SILO_H

#include <QDialog>
#include "building.h"
namespace Ui {
class Silo;
}

class Silo : public QDialog, public Building
{
    Q_OBJECT

public:
    explicit Silo(QWidget *parent , long int& nails ,long int& coins, long int &wheat);
    //non default constructor
    ~Silo();
    void set_capacity();
    void levelup();
    void levelup(long int &coins);
    void levelup(long int &coins ,long int &nails);
    void levelup(long int &coins,long int& nails ,long int &shovel);
    void rise_experience();
    void check_buildings_level();
private:
    Ui::Silo *ui;
};

#endif // SILO_H
