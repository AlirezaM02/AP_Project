#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <QDialog>
#include "building.h"
namespace Ui {
class Warehouse;
}

class Warehouse : public QDialog, public Building
{
    Q_OBJECT

public:
    explicit Warehouse(QWidget *parent , long int & coins, long int &nail , long int &shovel, long int &hay, long int &egg, long int &milk , long int &wool);
    ~Warehouse();

    void set_capacity();
    void levelup();
    void levelup(long int &coins);
    void levelup(long int &coins, long int& nails);
    void levelup(long int &coins, long int& nails , long int &shovel);
    void rise_experience();
    void check_buildings_level();

private:
    Ui::Warehouse *ui;

};

#endif // WAREHOUSE_H
