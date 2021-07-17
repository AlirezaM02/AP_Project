#ifndef SHEEP_FARM_H
#define SHEEP_FARM_H

#include <QDialog>

namespace Ui {
class Sheep_Farm;
}

class Sheep_Farm : public QDialog
{
    Q_OBJECT

public:
    explicit Sheep_Farm(QWidget *parent = nullptr);
    ~Sheep_Farm();

private:
    Ui::Sheep_Farm *ui;
};

#endif // SHEEP_FARM_H
