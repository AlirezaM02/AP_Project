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
    explicit Silo(QWidget *parent = nullptr);
    //non default constructor
    ~Silo();
    void setWheat_amount(int newWheat_amount);
    int getWheat_amount() const;
    void set_capacity();
    void levelup();
    void rise_experience();
    void check_buildings_level();
private:
    int wheat_amount;
    Ui::Silo *ui;
};

#endif // SILO_H
