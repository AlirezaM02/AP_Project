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
    explicit Silo(QWidget *parent, Player& current_player);  //non default constructor
    ~Silo();
    void set_capacity();
    void levelup();
    void levelup(Player& current_player);
    void rise_experience();
    void check_buildings_level();

private:
    Ui::Silo *ui;
};

#endif // SILO_H
