#include "autolabel.h"
#include "ui_autolabel.h"

void autolabel::setSeperator(QString seperator)
 {
    this->seperator = seperator;
 }

 QList<LabelPair> autolabel::returnUsableLabelPairListToMainWindow()
 {
    return usableLabels;
 }
autolabel::autolabel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::autolabel)
{
    ui->setupUi(this);
}

autolabel::~autolabel()
{
    delete ui;
}
