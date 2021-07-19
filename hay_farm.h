#ifndef HAY_FARM_H
#define HAY_FARM_H
#include <farm.h>
#include <QDialog>
#include <player.h>
namespace Ui {
class Hay_Farm;
}

class Hay_Farm : public QDialog,public Farm
{
    Q_OBJECT

public:
    explicit Hay_Farm(QWidget *parent, Player& current_player);
    ~Hay_Farm();
    void levelup(Player& current_player);
    void plow(Player& current_player);

private:
    Ui::Hay_Farm *ui;
    bool plow_check;
};

#endif // HAY_FARM_H
