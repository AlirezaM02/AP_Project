#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QString>
#include <QRegularExpression>
#include <QWidget>
//#include "map.h"

class Player
{
private:
    static int counter;
    int ID;
    long int coins;
    long int XP;
    int level;
    long int nail;
    long int shovel;
    long int hay;
    long int egg;
    long int milk;
    long int wool;
    long int wheat;
    int cow;
    QString name;
    QString username;
    QString password;
    QString email;
   // Map map;

public:
    Player(QString _name, QString _username, QString _password, QString _email, long _coins = 20, long _XP = 0, int _level = 1, long nail=1, long shovel=0, long hay= 1, long egg=0, long milk=0, long wool=0);
    Player();
    ~Player();

    int get_counter();

    int get_ID();

     int get_coins();
    const long& getcoinsref() const {return coins;}
    long& getcoinsref()       {return coins;}
    void set_coins(int newCoins);

    int get_XP();
    void set_XP(int newXP);

    int get_level();
    void set_level(int new_level);

    QString get_name();
    void set_name(QString new_name);

    QString get_username();
    void set_username(QString new_username);

    QString get_password();
    void set_password(QString new_password);

    QString get_email();
    void set_email(QString new_email);

    //Map &get_map();
    //void set_map(Map &newMap);

    bool check_email(QString _email);
    bool check_username(QString _username);
    bool check_password(QString _password); //for strength
    
    long getNail() const;
    const long& getNailref() const {return nail;}
    long& getNailref()       {return nail;}
    void setNail(long newNail);
    
    long getShovel() const;
    const long& getShovelref() const {return shovel;}
    long& getShovelref()       {return shovel;}
    void setShovel(long newShovel);
    
    long getHay() const;
    const long& getHayref() const {return hay;}
    long& getHayref()       {return hay;}
    void setHay(long newHay);
    
    long getEgg() const;
    const long& getEggref() const {return nail;}
    long& getEggref()       {return nail;}
    void setEgg(long newEgg);
    
    long getMilk() const;
    const long& getMilkref() const {return milk;}
    long& getMilkref()       {return milk;}
    void setMilk(long newMilk);

    long getWool() const;
    const long& getWoolref() const {return wool;}
    long& getWoolref()       {return wool;}
    void setWool(long newWool);

    long getWheat() const;
    const long& getWheatref() const {return wheat;}
    long& getWheatref()       {return wheat;}
    void setWheat(long newWheat);
    int getCow() const;
    void setCow(int newCow);
};

#endif // PLAYER_H
