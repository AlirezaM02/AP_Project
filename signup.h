#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QCloseEvent>
#include <QDir>
#include "player.h"

namespace Ui { class Signup; }

class Signup : public QDialog
{
    Q_OBJECT

private:
    Ui::Signup *ui;

private slots:
    void on_signupbtn_clicked();
    void check_line_edits(const QString& a_strString);

public slots:
    void on_signupBtn_clicked();
    void on_exitBtn_clicked();

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

signals:
    void sendNewUserData(QString, QString, QString, QString);
    void exitBtn_clicked();
};

#endif // SIGNUP_H
