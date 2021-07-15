#ifndef CATTLE_H
#define CATTLE_H
#include <building.h>
#include <player.h>

class Cattle:public Building
{
public:
    Cattle();
    void feed();
    void collect_milk();
    void set_cow_number(int cow_number);
    int get_cow_number();
    void set_collection_date(QDate _date);
    QDate get_collection_date();
private:
    int cow_counter;
    QDate date_milk_collecting;
};

#endif // CATTLE_H
