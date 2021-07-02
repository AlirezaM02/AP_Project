#ifndef APPLICATION_H
#define APPLICATION_H
#include <QVector>
#include "player.h"
class Application
{
private:
    QVector <Player> playerlist;
    Player currentPlayer;


public:
    Application();
};

#endif // APPLICATION_H
