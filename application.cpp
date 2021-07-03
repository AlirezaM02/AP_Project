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
    file.setFileName("file.json");
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
/*void Application::fetchPlayersData(){
}*/
Player* Application::findPlayer(QString playername){
    for(int i=0;i<playerlist.size();i++)
    {
         return &playerlist[i];
    }
}
bool Application::login(QString playername, QString password){}
void Application::logout(){}
void Application::setCurrentplayer(int accID){}
