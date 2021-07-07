#include "scoreboard.h"
#include "ui_scoreboard.h"

Scoreboard::Scoreboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scoreboard)
{
    players.erase(players.begin(), players.end());

    QTextStream ts(stdout);
    ts << QDir::currentPath();
    QFile file("C:\\Users\\Alireza\\My Documents\\GitRepos\\AP_Project\\data\\data.json");

    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "Json file couldn't be opened/found";
        return;
    }

    QByteArray byteArray;
    byteArray = file.readAll();
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc;
    jsonDoc = QJsonDocument::fromJson(byteArray, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        qWarning() << "Parse error at " << parseError.offset << ":" << parseError.errorString();
        exit(0);
    }

    QJsonObject Obj = jsonDoc.object();
    QJsonArray Arr = Obj.value("users").toArray();
    foreach (const QJsonValue &val, Arr)
    {
        long int XP = val.toObject().value("XP").toInteger();
        int level = val.toObject().value("level").toInteger(), ID = val.toObject().value("ID").toInteger();
        QString username = val.toObject().value("username").toString();
        //Map _map;
        players.push_back(showPlayers(ID, username, level, XP));
    }

    std::sort(players.begin(), players.end(), [](showPlayers p1, showPlayers p2)
    {
        if (p1.getLevel() > p2.getLevel()) return true;
        else if (p1.getLevel() == p2.getLevel())
            if (p1.getXP() > p2.getXP())
                return true;
        return false;
    }
    );
    ui->setupUi(this);
}

Scoreboard::~Scoreboard()
{
    delete ui;
}

void showPlayers::setXP(int newXP)
{
    XP = newXP;
}

int showPlayers::getXP() const
{
    return XP;
}

void showPlayers::setID(int newID)
{
    ID = newID;
}

int showPlayers::getID() const
{
    return ID;
}

void showPlayers::setLevel(int newLevel)
{
    level = newLevel;
}

int showPlayers::getLevel() const
{
    return level;
}

void showPlayers::setUsername(const QString &newUsername)
{
    username = newUsername;
}

const QString &showPlayers::getUsername() const
{
    return username;
}
