#ifndef CATTLE_H
#define CATTLE_H
#include "building.h"
#include <QDialog>

namespace Ui {
class Cattle;
}

class Cattle : public QDialog, public Building
{
    Q_OBJECT

public:
    explicit Cattle(QWidget *parent = nullptr);
    ~Cattle();

private:
    Ui::Cattle *ui;
};

#endif // CATTLE_H
