#ifndef HAY_FARM_H
#define HAY_FARM_H
#include <QDialog>
#include <player.h>
#include"farm.h"
namespace Ui {
class Hay_Farm;
}

class Hay_Farm : public QDialog, public Farm
{
    Q_OBJECT

public:
    explicit Hay_Farm(QWidget *parent, Player &current_player);
    ~Hay_Farm();
    void levelup(Player &current_player);
    void plow(Player &current_player);

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::Hay_Farm *ui;
    bool plow_check;
};

#endif // HAY_FARM_H
