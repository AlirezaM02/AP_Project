#ifndef POULTRY_H
#define POULTRY_H

#include <QDialog>
#include "building.h"

namespace Ui
{
    class Poultry;
}

class Poultry : public QDialog, public Building
{
    Q_OBJECT

public:
    explicit Poultry(QWidget *parent, Player &current_player);
    ~Poultry();
    void set_capacity();
    void levelup(Player &current_player);
    void feed(Player &current_player);
    bool feed_check;

private slots:
    void on_feedbtn_clicked(Player &current_player);
    void on_eggcollectbtn_clicked(Player &current_player);
    void on_upgradebtn_clicked(Player &current_player);

private:
    Ui::Poultry *ui;
    QMessageBox *message;
};

#endif // POULTRY_H
