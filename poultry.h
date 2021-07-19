#ifndef POULTRY_H
#define POULTRY_H

#include <QDialog>
#include "building.h"
namespace Ui {
class Poultry;
}

class Poultry : public QDialog, public Building
{
    Q_OBJECT

public:
    explicit Poultry(QWidget *parent ,Player &current_player);
    ~Poultry();
    void set_capacity();
    void levelup(Player& current_player);
    void feed(Player &current_player);
    bool feed_check;

private:
    Ui::Poultry *ui;
};

#endif // POULTRY_H
