#include "application.h"

Application::Application(){
    savePlayersData();
}
Application::~Application(){}
void Application::savePlayersData(){}
void Application::fetchPlayersData(){}
Player Application::*findPlayer(QString username){}
bool Application::login(QString username, QString password){}
void Application::logout(){}
void Application::setCurrentUser(int accID){}
