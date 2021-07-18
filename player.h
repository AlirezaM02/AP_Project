#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QString>
#include <QRegularExpression>
#include <QWidget>

class Player
{
private:
    static int counter;
    int ID;
    QString name;
    QString username;
    QString password;
    QString email;
    int level;
    int XP;
    int coins;
    int nail;
    int shovel;
    int hay;
    int egg;
    int milk;
    int wool;
    int wheat;
    int cow;
    int sheep;
    int hen;
    int day;


    // Map map;

public:
    Player(QString _name, QString _username, QString _password, QString _email, int  _coins = 20, int  _XP = 0,
           int _level = 1,   int _nail = 1,   int _shovel = 0,   int _hay = 1,   int _egg = 0,   int _milk = 0,
           int _wool = 0, int _wheat=0,int _cow=0, int _sheep=0, int _hen=0,  int _day=1);
    Player();
    ~Player();

    int get_counter();

    int get_ID();

    int get_coins();
    const  int& getcoinsref() const {return coins;}
    int& getcoinsref()       {return coins;}
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

     int getNail() const;
    const  int& getNailref() const {return nail;}
     int& getNailref()       {return nail;}
    void setNail( int newNail);

    int getShovel() const;
    const  int& getShovelref() const {return shovel;}
    int& getShovelref()       {return shovel;}
    void setShovel( int newShovel);

    int getHay() const;
    const  int& getHayref() const {return hay;}
    int& getHayref()       {return hay;}
    void setHay( int newHay);

    int getEgg() const;
    const  int& getEggref() const {return nail;}
    int& getEggref()       {return nail;}
    void setEgg( int newEgg);

    int getMilk() const;
    const  int& getMilkref() const {return milk;}
    int& getMilkref()       {return milk;}
    void setMilk( int newMilk);

    int getWool() const;
    const  int& getWoolref() const {return wool;}
    int& getWoolref()       {return wool;}
    void setWool( int newWool);

    int getWheat() const;
    const  int& getWheatref() const {return wheat;}
    int& getWheatref()       {return wheat;}
    void setWheat( int newWheat);

    int getCow() const;
    const int& getCowref() const {return cow;}
    int& getCowref()       {return cow;}
    void setCow(int newCow);

    int getSheep() const;
    const int& getSheepref() const {return sheep;}
    int& getSheepref()       {return sheep;}
    void setSheep(int newSheep);

    bool check_email(QString _email);
    bool check_username(QString _username);
    bool check_password(QString _password); //for strength


    int getDay() const;
    const int& getDayref() const {return day;}
    int& getDayref()       {return day;}
    void setDay(int newDay);
    int getHen() const;
    void setHen(int newHen);
};

#endif // PLAYER_H
