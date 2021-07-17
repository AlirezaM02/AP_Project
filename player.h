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
    int cow;
    int level;
    long int coins;
    long int XP;
    long int nail;
    long int shovel;
    long int hay;
    long int egg;
    long int milk;
    long int wool;
    long int wheat;
  
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

    long getNail() const;
    void setNail(long newNail);

    long getShovel() const;
    void setShovel(long newShovel);

    long getHay() const;
    void setHay(long newHay);

    long getEgg() const;
    void setEgg(long newEgg);

    long getMilk() const;
    void setMilk(long newMilk);

    long getWool() const;
    void setWool(long newWool);

    long getWheat() const;
    void setWheat(long newWheat);

    bool check_email(QString _email);
    bool check_username(QString _username);
    bool check_password(QString _password); //for strength

};

#endif // PLAYER_H
