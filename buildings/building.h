#ifndef BUILDING_H
#define BUILDING_H
#include <QDate>
#include <QMainWindow>
#include <map.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Building; }
QT_END_NAMESPACE

class Building : public QMainWindow
{
    Q_OBJECT

public:
    Building(QWidget *parent = nullptr);
    ~Building();
    void set_capacity();
    void levelup();
    void rise_experience();
    void check_buildings_level();
private:
    Ui::Building *ui;
protected:
    int level;
    int capacity;
};
#endif // BUILDING_H
