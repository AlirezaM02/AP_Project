
#ifndef MAP_H
#define MAP_H
#include "cattle.h"
#include <QDialog>
#include "player.h"
#include "silo.h"
#include "warehouse.h"
namespace Ui {
class Map;
}

class Map : public QDialog
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent, Player& current_player, int ID , QVector<Player>&players );
    ~Map();

private slots:
    void on_nextdaybtn_clicked();
signals:
    void send_Player(Player&);
private:
    Silo* silo;
    Warehouse* warehouse;
    Cattle* cattle;
    Ui::Map *ui;
    Player& current_player;
};

#endif // MAP_H
