#ifndef POULTRY_H
#define POULTRY_H

#include <QDialog>

namespace Ui {
class Poultry;
}

class Poultry : public QDialog
{
    Q_OBJECT

public:
    explicit Poultry(QWidget *parent = nullptr);
    ~Poultry();

private:
    Ui::Poultry *ui;
};

#endif // POULTRY_H
