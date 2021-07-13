#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

namespace Ui { class Signup; }

class Signup : public QDialog
{
    Q_OBJECT

private:
    Ui::Signup *ui;

private slots:
    void on_signupbtn_clicked();
    void check_line_edits();

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

signals:
    void sendNewUserData(QString, QString, QString, QString);

};

#endif // SIGNUP_H
