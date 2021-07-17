#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QDir>
#include "signup.h"
#include "map.h"

namespace Ui { class Login; }

class Login : public QDialog
{
    Q_OBJECT

private:
    Ui::Login *ui;
    Signup *signup;
    Map *playerMap;
    bool loginStat;
    bool signupStat;
    QVector <Player> players;
    Player *currentPlayer;

public slots:
    void saveNewUserData(QString, QString, QString, QString);
    void check_line_edits(const QString &a_strString);
    void on_signupbtn_clicked();
    void on_loginbtn_clicked();
    void on_buttonBox_rejected();

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString getUsername();
    QString getPassword();
    void addPlayer(Player p);
    void addPlayer(QString name, QString username, QString password, QString email);
    bool ok;
};

#endif // LOGINDIALOG_H
