#ifndef POULTRY_H
#define POULTRY_H
#include <building.h>
#include <QDate>
class Poultry:public Building
{
public:
    Poultry();
    void feed();
    void collect_egg();
    void set_hen_number(int hen_number);
    int get_hen_number();
    void set_collection_date(QDate DateTime);
    QDate get_collection_date();
private:
    int hen_counter;
    QDate egg_collection_date;
};

#endif // POULTRY_H
