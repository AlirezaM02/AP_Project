#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include <building.h>
#include <player.h>
class Warehouse:public Building
{
public:
    Warehouse(int _capacity=5,int _hay=1,int _stud=1);
    void set_shovel_number(int _shovel);
    void set_stud_number(int _stud);
    void set_hay_number(int _hay);
    void set_egg_number(int _egg);
    void set_milk_number(int _milk);
    void set_wool_number(int _wool);
    int get_shovel_number();
    int get_stud_number();
    int get_hay_number();
    int get_egg_number();
    int get_milk_number();
    int get_wool_number();
    bool checkupdate();

private:
    int shovel_counter;
    int stud_counter;
    int hay_counter;
    int milk_counter;
    int egg_counter;
    int wool_counter;
};

#endif // WAREHOUSE_H
