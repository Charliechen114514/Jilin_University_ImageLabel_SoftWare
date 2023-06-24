#include "labelsquerytextclass.h"

labelsQueryTextClass::labelsQueryTextClass(QWidget *parent)
    : smartLineEditClass(parent)
{
    this->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-z]+[A-Z]+$")));
}

QString labelsQueryTextClass::getResultedLabelName()
{
    return QString(this->text());
}
