
#ifndef MAP_H
#define MAP_H

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

private:
    Silo* silo;
    Warehouse* warehouse;
    Ui::Map *ui;
};

#endif // MAP_H
