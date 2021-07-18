#ifndef BUILDING_H
#define BUILDING_H
#include <QDate>
#include <QMainWindow>
#include "player.h"
class Building
{

public:
    Building();
    ~Building();
    virtual void set_capacity() = 0;
    virtual void levelup() = 0;
  /*  virtual void levelup(long int &coins) = 0;
    virtual void levelup(long int &coins, long int &nails) = 0;
    virtual void levelup(long int &coins, long int& nails , long int &shovel)=0;*/
    virtual void levelup(Player& current_player)= 0;
    virtual void rise_experience() = 0;
    virtual void check_buildings_level() = 0;
protected:
    int level;
    int capacity;
};

#endif // BUILDING_H
