#include "scoreboard.h"
#include "ui_scoreboard.h"

Scoreboard::Scoreboard(QWidget *parent, QVector<Player> &players, int ID) : QDialog(parent),
                                                                            ui(new Ui::Scoreboard)
{
    //players.erase(players.begin(), players.end());

    std::sort(players.begin(), players.end(), [](Player p1, Player p2)
              {
                  if (p1.get_level() > p2.get_level())
                      return true;
                  else if (p1.get_level() == p2.get_level())
                      if (p1.get_XP() > p2.get_XP())
                          return true;
                  return false;
              });

    int rowCount = players.size();

    QTableWidgetItem *username = new QTableWidgetItem();
    QTableWidgetItem *level = new QTableWidgetItem();
    QTableWidgetItem *xp = new QTableWidgetItem();

    for (int i = 0; i < rowCount; i++)
    {

        ui->tableWidget->insertRow(i);
        username->setText(players[i].get_username());
        level->setText(QString ::number(players[i].get_level()));
        xp->setText(QString ::number(players[i].get_XP()));

        ui->tableWidget->setItem(i, 0, username);
        ui->tableWidget->setItem(i, 1, level);
        ui->tableWidget->setItem(i, 2, xp);
        if (ID == players[i].get_ID())
        {
            ui->tableWidget->item(i, 0)->setBackground(Qt::lightGray);
            ui->tableWidget->item(i, 0)->setBackground(Qt::lightGray);
            ui->tableWidget->item(i, 0)->setBackground(Qt::lightGray);
        }
    }
    ui->setupUi(this);
}

Scoreboard::~Scoreboard()
{
    delete ui;
}
