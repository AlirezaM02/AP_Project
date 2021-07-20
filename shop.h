#ifndef SHOP_H
#define SHOP_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "player.h"

namespace Ui
{
    class Shop;
}

class Shop : public QDialog
{
    Q_OBJECT

public:
    explicit Shop(QWidget *parent, Player &current_player);
    ~Shop();
    void sell_wheat();
    void buy_wheat();
    void sell_hay();
    void buy_hay();
    void sell_hen();
    void buy_hen();
    void sell_cow();
    void buy_cow();
    void sell_sheep();
    void buy_sheep();
    void sell_nail();
    void buy_nail();
    void sell_shovel();
    void buy_shovel();

private slots:
    void on_wheatsellbtn_clicked(Player &current_player);
    void on_haysellbtn_clicked(Player &current_player);
    void on_hensellbtn_clicked(Player &current_player);
    void on_cowsellbtn_clicked(Player &current_player);
    void on_sheepsellbtn_clicked(Player &current_player);
    void on_nailsellbtn_clicked(Player &current_player);
    void on_shovelsellbtn_clicked(Player &current_player);
    void on_milksellbtn_clicked(Player &current_player);
    void on_eggsellbtn_clicked(Player &current_player);
    void on_woolsellbtn_clicked(Player &current_player);
    void on_wheatbuybtn_clicked(Player &current_player);
    void on_haybuybtn_clicked(Player &current_player);
    void on_henbuybtn_clicked(Player &current_player);
    void on_cowbuybtn_clicked(Player &current_player);
    void on_sheepbuybtn_clicked(Player &current_player);
    void on_nailbuybtn_clicked(Player &current_player);
    void on_shovelbuybtn_clicked(Player &current_player);

private:
    Ui::Shop *ui;
    QMessageBox *message;
};

#endif // SHOP_H
