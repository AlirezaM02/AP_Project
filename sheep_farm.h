#ifndef SHEEP_FARM_H
#define SHEEP_FARM_H
#include <player.h>
#include <QDialog>
#include <building.h>
namespace Ui {
class Sheep_Farm;
}

class Sheep_Farm : public QDialog,public Building
{
    Q_OBJECT

public:
    explicit Sheep_Farm(QWidget *parent,Player &current_player);
    ~Sheep_Farm();
    void set_capacity();
    void levelup(Player& current_player);
    void feed(Player &current_player);
    bool feed_check;

private slots:
    void on_pushButton_4_clicked();

private:
    Ui::Sheep_Farm *ui;
};

#endif // SHEEP_FARM_H
