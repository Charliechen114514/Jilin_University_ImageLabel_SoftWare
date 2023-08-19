<<<<<<< HEAD
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
=======
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
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
