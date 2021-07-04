#include "application.h"

Application::Application(){
    fetchPlayersData();
}
Application::~Application(){
        savePlayersData();
}
void Application::savePlayersData(){


    QJsonObject mainObj;
    QJsonArray mainArray;
    for(int i = 0 ; i<playerlist.size() ; i++){
          QJsonObject playerObj;
          playerObj["ID"]=playerlist[i].get_ID();
          playerObj["name"]=playerlist[i].get_name();
          playerObj["username"]=playerlist[i].get_username();
          playerObj["password"]=playerlist[i].get_password();
          playerObj["level"]=playerlist[i].get_level();
          playerObj["XP"]=playerlist[i].getXP();
          playerObj["coins"]=playerlist[i].get_coins();
          //playerObj["map"]=playerlist[i].getMap();
          mainArray.append(playerObj);
    }
    mainObj["users"] = mainArray;
    QByteArray byteArray;
    byteArray = QJsonDocument(mainObj).toJson();
    QFile file(":/data/data.json");
    file.setFileName("data.json");
    if(!file.open(QIODevice::WriteOnly)){
           qDebug() << "No write access for json file";
           return;
       }
    file.write(byteArray);
    file.close();
    /*file.open(QIODevice::WriteOnly);
    QJsonParseError *error = new QJsonParseError();
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(),error);
    file.write(mainDoc.toJson());
    file.close();
    */
}
void Application::fetchPlayersData(){
}
Player* Application::findPlayer(QString username){
    for(int i=0;i<playerlist.size();i++)
    {
        if(playerlist[i].get_username()==username)
            return &playerlist[i];
    }
}

void Application::refresh(int ID)
{
    fetchPlayersData();
    setCurrentPlayer(ID);
}

void Application::refresh()
{
    fetchPlayersData();
}
bool Application::login(QString username, QString password){
    for(int i=0; i<playerlist.size(); i++)
    {
        if(playerlist[i].get_username()==username&&playerlist[i].get_password()==password)
        {
            currentPlayer=&playerlist[i];
            playerID=playerlist[i].get_ID();
            //TODO
            savePlayersData();
            return true;
        }
        else
        {
            //TODO
            return false;
        }
    }
}
void Application::logout(){
    refresh(getplayerID());
    savePlayersData();
}
void Application::setCurrentPlayer(int ID){
    for(int i=0; i<playerlist.size(); i++)
    {
        if (playerlist[i].get_ID()==ID)
            currentPlayer=&playerlist[i];
    }
}

int Application::getplayerID()
{
    return playerID;
}
