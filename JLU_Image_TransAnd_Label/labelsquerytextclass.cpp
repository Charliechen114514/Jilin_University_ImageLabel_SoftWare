#include "labelsquerytextclass.h"

labelsQueryTextClass::labelsQueryTextClass(QWidget *parent)
    : smartLineEditClass(parent)
{
    this->setValidator(new QRegularExpressionValidator(QRegularExpression("[a-z]+$")));
    connect(this,&QLineEdit::editingFinished,this,&labelsQueryTextClass::getTextAndCheckIsValid);
}

unsigned int labelsQueryTextClass::getTextAndCheckIsValid()
{
    resultFromEditing = this->text();
    return 1;
}

QString labelsQueryTextClass::getResultedLabelName()
{
    return QString(resultFromEditing);
}
