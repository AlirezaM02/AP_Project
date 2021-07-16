#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <QString>
#include <QRegularExpression>
#include <QWidget>
#include "map.h"

class Player
{
private:
    static int counter;
    int ID, level;
    long int coins, XP, wheat, wool, milk, egg, hay, shovel, nail;
    QString name;
    QString username;
    QString password;
    QString email;
    // Map map;

public:
    Player(QString _name, QString _username, QString _password, QString _email, long _coins = 20, long _XP = 0,
           int _level = 1, long int _nail = 1, long int _shovel = 0, long int _hay = 1, long int _egg = 0, long int _milk = 0, long int _wool = 0);
    Player();
    ~Player();

    int get_counter();

    int get_ID();

    int get_coins();
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

    long getNail() const { return nail; }
    void setNail(long newNail) { nail = newNail; }

    long getShovel() const { return shovel; }
    void setShovel(long newShovel) { shovel = newShovel; }

    long getHay() const { return hay; }
    void setHay(long newHay) { hay = newHay; }

    long getEgg() const { return egg; }
    void setEgg(long newEgg) { egg = newEgg; }

    long getMilk() const { return milk; }
    void setMilk(long newMilk) { milk = newMilk; }

    long getWool() const { return wool; }
    void setWool(long newWool) { wool = newWool; }

    long getWheat() const { return wheat; }
    void setWheat(long newWheat) { wheat = newWheat; }

    bool check_email(QString _email);
    bool check_username(QString _username);
    bool check_password(QString _password); //for strength

};

#endif // PLAYER_H
