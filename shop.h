#ifndef SHOP_H
#define SHOP_H

#include <QDialog>
#include <player.h>
namespace Ui {
class Shop;
}

class Shop : public QDialog
{
    Q_OBJECT

public:
    explicit Shop(QWidget *parent ,Player* current_player);
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

private:
    Ui::Shop *ui;
};

#endif // SHOP_H
