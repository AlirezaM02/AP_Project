#ifndef SILO_H
#define SILO_H

#include <QDialog>
#include "building.h"

namespace Ui
{
    class Silo;
}

class Silo : public QDialog, public Building
{
    Q_OBJECT

public:
    explicit Silo(QWidget *parent, Player &current_player); //non default constructor
    ~Silo();
    void set_capacity();
    void levelup(Player &current_player);

private slots:
    void on_upgradebtn_clicked(Player &current_player);

    void on_pushButton_2_clicked();

private:
    Ui::Silo *ui;
    QMessageBox *message;
};

#endif // SILO_H
