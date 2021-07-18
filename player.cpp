#include "player.h"
#include "map.h"

int Player::counter = 0;

int Player::getCow() const
{
    return cow;
}

void Player::setCow(int newCow)
{
    cow = newCow;
}

int Player::getSheep() const
{
    return sheep;
}

void Player::setSheep(int newSheep)
{
    sheep = newSheep;
}

int Player::getDay() const
{
    return day;
}

void Player::setDay(int newDay)
{
    day = newDay;
}

int Player::getHen() const
{
    return hen;
}

void Player::setHen(int newHen)
{
    hen = newHen;
}

Player::Player(QString _name, QString _username, QString _password, QString _email,  int _coins,  int _XP, int _level,  int _nail ,  int _shovel,  int _hay,  int _egg , int _milk ,  int _wool , int _day)
{
    counter++;
    ID = counter;
    coins = _coins;
    XP = _XP;
    level = _level;
    name = _name;
    username =_username;
    password =_password;
    email = _email;
    nail = _nail;
    shovel = _shovel;
    hay = _hay;
    egg = _egg;
    milk = _milk;
    wool = _wool;
    day=_day;
}

Player::Player()
{
    coins = 20;
    XP = 0;
    level = 1;
    name = "";
    username = "";
    password = "";
    email = "";
    nail= 1;
    shovel=0;
    hay=1;
    egg=0;
    milk=0;
    wool=0;
    day=1;
    counter ++;
}

Player::~Player() {}

int Player::get_counter()
{
    return counter;
}

int Player::get_ID()
{
    return ID;
}

int Player::get_coins()
{
    return coins;
}

void Player::set_coins(int _coins)
{
    coins = _coins;
}

int Player::get_XP()
{
    return XP;
}

void Player::set_XP(int _XP)
{
    XP = _XP;
}

int Player::get_level()
{
    return level;
}

void Player::set_level(int _level)
{
    level = _level;
}

QString Player::get_name()
{
    return name;
}

void Player::set_name(QString _name)
{
    name = _name;
}

QString Player::get_username()
{
    return username;
}

void Player::set_username(QString _username)
{
    username = _username;
}

QString Player::get_password()
{
    return password;
}

void Player::set_password(QString _password)
{
    password = _password;
}

QString Player::get_email()
{
    return email;
}

void Player::set_email(QString _email)
{
    email = _email;
}

int Player::getNail() const
{
    return nail;
}

void Player::setNail( int newNail)
{
    nail = newNail;
}

int Player::getShovel() const
{
    return shovel;
}

void Player::setShovel( int newShovel)
{
    shovel = newShovel;
}

 int Player::getHay() const
{
    return hay;
}

void Player::setHay( int newHay)
{
    hay = newHay;
}

 int Player::getEgg() const
{
    return egg;
}

void Player::setEgg( int newEgg)
{
    egg = newEgg;
}

int Player::getMilk() const
{
    return milk;
}

void Player::setMilk( int newMilk)
{
    milk = newMilk;
}

int Player::getWool() const
{
    return wool;
}

void Player::setWool( int newWool)
{
    wool = newWool;
}

int Player::getWheat() const
{
    return wheat;
}

void Player::setWheat( int newWheat)
{
    wheat = newWheat;
}

bool Player::check_email(QString _email)
{
    QChar c= _email[0];
    if (!c.isLetter())
    {
        return false;
    }
    int at = -1;
    int dot = -1;
    for(int i = 0; i < _email.length(); i++)
    {
        if (_email[i] == '@')
            at = i;
        else if (_email[i] == '.')
            dot = i;
    }
    if (at==-1 || dot==-1)
        return false;
    if (dot < at)
        return false;
    return !(dot >= (_email.length() - 1));
}

bool Player::check_username(QString _username)
{
    return true;
}

bool Player::check_password(QString _password)
{
    int lower = 0, digit = 0, symbol = 0, upper = 0, passlen = _password.length();
    for (const auto& character : _password)
    {
        if (character.isUpper())
            upper++;
        else if (character.isLower())
            lower++;
        else if (character.isDigit())
            digit++;
        else
            symbol++;
    }
    if (upper >= 1 and lower >= 1 and digit >= 1 and symbol >= 1 and passlen >=6)
        return true;
    return false;
}
