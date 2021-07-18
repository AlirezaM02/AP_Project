#ifndef CATTLE_H
#define CATTLE_H
#include "building.h"
#include <QDialog>

namespace Ui {
class Cattle;
}

class Cattle : public QDialog, public Building
{
    Q_OBJECT

public:
    explicit Cattle(QWidget *parent = nullptr,Player &current_player);
    ~Cattle();
    virtual void set_capacity();
    virtual void levelup(Player &current_player) ;
    virtual void rise_experience(Player &current_player);
    virtual void check_buildings_level(Player &current_player);
    void feed(Player &current_player);
    bool feed_check;

private:
    Ui::Cattle *ui;
};

#endif // CATTLE_H
