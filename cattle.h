#ifndef CATTLE_H
#define CATTLE_H

#include <QDialog>

namespace Ui {
class Cattle;
}

class Cattle : public QDialog
{
    Q_OBJECT

public:
    explicit Cattle(QWidget *parent = nullptr);
    ~Cattle();

private:
    Ui::Cattle *ui;
};

#endif // CATTLE_H
