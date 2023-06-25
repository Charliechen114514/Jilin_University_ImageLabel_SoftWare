#include "helpandcheck.h"
#include "ui_helpandcheck.h"

helpAndCheck::helpAndCheck(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::helpAndCheck)
{
    ui->setupUi(this);
}

helpAndCheck::~helpAndCheck()
{
    delete ui;
}
