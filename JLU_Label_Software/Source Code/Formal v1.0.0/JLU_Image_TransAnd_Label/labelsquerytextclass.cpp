<<<<<<< HEAD
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
=======
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
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
