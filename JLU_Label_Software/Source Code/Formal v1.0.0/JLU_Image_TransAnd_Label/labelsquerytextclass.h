#ifndef LABELSQUERYTEXTCLASS_H
#define LABELSQUERYTEXTCLASS_H

#include <QWidget>
#include <smartlineeditclass.h>
#include <QRegularExpressionValidator>
class labelsQueryTextClass : public smartLineEditClass
{
    Q_OBJECT
public:
    explicit labelsQueryTextClass(QWidget *parent = nullptr);
    QString getResultedLabelName();
signals:
    void finishEditingLabels();
private:
};

#endif // LABELSQUERYTEXTCLASS_H
