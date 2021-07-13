#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "signup.h"

namespace Ui { class Login; }

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString getUsername();
    QString getPassword();

private slots:
    void check_line_edits();
    void on_signupbtn_clicked();
    void on_loginbtn_clicked();

private:
    Ui::Login *ui;
    bool ok;
};

#endif // LOGINDIALOG_H
