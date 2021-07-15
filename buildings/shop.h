#ifndef SHOP_H
#define SHOP_H
#include <building.h>

class Shop:public Building
{
public:
    Shop();
    void sell();
    void buy();
    void show_crops();
};

#endif // SHOP_H
