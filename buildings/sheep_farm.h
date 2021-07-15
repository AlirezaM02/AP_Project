#ifndef SHEEP_FARM_H
#define SHEEP_FARM_H
#include <building.h>

class Sheep_Farm:public Building
{
public:
    Sheep_Farm();
    void feed();
    void shave();
    void set_sheep_number(int sheep_number);
    int get_sheep_number();
    void set_shave_date(QDate _date);
    QDate get_shave_date();
private:
    int sheep_counter;
    QDate shave_date;

};

#endif // SHEEP_FARM_H
