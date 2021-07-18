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
    void levelup(Player& current_player);

private:
    Ui::Silo *ui;
};

#endif // SILO_H
