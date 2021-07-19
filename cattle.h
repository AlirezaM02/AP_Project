#ifndef CATTLE_H
#define CATTLE_H

#include <QDialog>
#include "building.h"
namespace Ui { class Cattle; }

class Cattle : public QDialog , public Building
{
    Q_OBJECT

public:
    explicit Cattle(QWidget *parent,Player& current_player);
    ~Cattle();
    void set_capacity();
    void levelup(Player &current_player);
    void feed(Player &current_player);
    bool feed_check;

private:
    Ui::Cattle *ui;
};

#endif // CATTLE_H
