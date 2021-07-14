#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "signup.h"

namespace Ui { class Login; }

class Login : public QDialog
{
    Q_OBJECT

private:
    Ui::Login *ui;
    Signup *signup;
private slots:
    void check_line_edits();
    void on_signupbtn_clicked();
    void on_loginbtn_clicked();

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

    QString getUsername();
    QString getPassword();

    bool ok;
};

#endif // LOGINDIALOG_H
