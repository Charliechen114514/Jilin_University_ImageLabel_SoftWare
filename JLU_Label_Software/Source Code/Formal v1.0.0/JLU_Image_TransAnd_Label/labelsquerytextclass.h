<<<<<<< HEAD
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
=======
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
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
