#ifndef FARM_H
#define FARM_H
#include "player.h"

class Farm
{
public:
    Farm();
    void set_planting(int area_croping);
    ~Farm();
    virtual void levelup(Player& current_player)= 0;
    void set_area(int _area);
protected:
    int area;
    int planting_area;

};

#endif // FARM_H
