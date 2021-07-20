#ifndef BUILDING_H
#define BUILDING_H

#include <QDate>
#include <QMainWindow>
#include "player.h"
#include <QString>
#include <QMessageBox>
class Building
{
public:
    Building();
    ~Building();
    virtual void set_capacity() = 0;
    virtual void levelup(Player& current_player)= 0;
protected:
    int level;
    int capacity;
};

#endif // BUILDING_H
