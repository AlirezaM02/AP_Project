#ifndef WHEAT_FARM_H
#define WHEAT_FARM_H

#include <QDialog>
#include "farm.h"
#include "building.h"

namespace Ui
{
    class Wheat_Farm;
}

class Wheat_Farm : public QDialog, public Farm
{
    Q_OBJECT

public:
    explicit Wheat_Farm(QWidget *parent, Player &current_player);
    ~Wheat_Farm();
    void levelup(Player &current_player);

private:
    Ui::Wheat_Farm *ui;
    QMessageBox *message;
};

#endif // WHEAT_FARM_H
