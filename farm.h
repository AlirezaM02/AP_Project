#ifndef FARM_H
#define FARM_H
#include "player.h"

class Farm
{
public:
    Farm();
    ~Farm();
    void set_planting(int area_croping);
    void set_area(int _area);
    virtual void levelup(Player &current_player)= 0;

protected:
    int area;
    int planting_area;
};

#endif // FARM_H
