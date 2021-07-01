#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;
#include <QString>
#include "map.h"
class Player
{
private:
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
    Player();
};

#endif // PLAYER_H
