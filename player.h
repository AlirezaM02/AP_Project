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
    int ID;
    long int coins;
    long int XP;
    int level;
    QString name;
    QString username;
    QString password;
    QString email;
    Map map;

public:
    Player(long _coins = 0, long _XP = 0, int _level = 0, QString _name = "", QString _username = "", QString _password = "", QString _email = "", Map _map = Map());
    ~Player();
    int get_counter();
    int get_ID();
    int get_coins();
    void set_coins(int newCoins);
    int getXP();
    void setXP(int newXP);
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
    bool check_email(QString _email);
    bool check_username(QString _username);
    bool check_password(QString _password); //for strength
    const Map &getMap() const;
    void setMap(const Map &newMap);
};

#endif // PLAYER_H
