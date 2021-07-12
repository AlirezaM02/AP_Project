#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui
{
class loginDialog;
}

class loginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loginDialog(QWidget *parent = nullptr);
    ~loginDialog();
    QString getUsername();
    QString getPassword();

private slots:
    void check_line_edits();
    void on_loginbtn_clicked();
    void on_signupbtn_clicked();


private:
    Ui::loginDialog *ui;
};

#endif // LOGINDIALOG_H
