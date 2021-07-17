#ifndef POULTRY_H
#define POULTRY_H

#include <QDialog>
#include "building.h"
namespace Ui {
class Poultry;
}

class Poultry : public QDialog, public Building
{
    Q_OBJECT

public:
    explicit Poultry(QWidget *parent = nullptr);
    ~Poultry();

private:
    Ui::Poultry *ui;
};

#endif // POULTRY_H
