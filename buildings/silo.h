#ifndef SILO_H
#define SILO_H

#include <building.h>
class Silo:public Building
{
public:
    Silo();
    void set_wheat_amount(int wheat_amount);
    int get_wheat_amount();
private:
    int wheat_amount;
};

#endif // SILO_H
