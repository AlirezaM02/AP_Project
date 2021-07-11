#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui {
class signup;
}

class signup : public QWidget
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = nullptr);
    ~signup();

signals:
    void sendNewUserData(QString, QString, QString, QString);

private slots:
    void on_signupbtn_clicked();
    void check_line_edits();

private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
