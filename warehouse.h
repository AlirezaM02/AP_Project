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
    explicit Warehouse(QWidget *parent , Player& current_player);
    ~Warehouse();
    void set_capacity();
    void levelup();
    void levelup(Player& current_player);
    void rise_experience();
    void check_buildings_level();

private:
    Ui::Warehouse *ui;

};

#endif // WAREHOUSE_H
