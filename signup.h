#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>

namespace Ui { class Signup; }

class Signup : public QWidget
{
    Q_OBJECT

public:
    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

signals:
    void sendNewUserData(QString, QString, QString, QString);

private slots:
    void on_signupbtn_clicked();
    void check_line_edits();

private:
    Ui::Signup *ui;
};

#endif // SIGNUP_H
