#include "scoreboard.h"
#include "ui_scoreboard.h"

Scoreboard::Scoreboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Scoreboard)
{
    ui->setupUi(this);
}

Scoreboard::~Scoreboard()
{
    delete ui;
}
