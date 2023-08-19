<<<<<<< HEAD
#ifndef SMARTLINEEDITCLASS_H
#define SMARTLINEEDITCLASS_H

#include <QObject>
#include <QWidget>
#include<QLineEdit>
#include<QMouseEvent>
#include<QMessageBox>
#include<QRegularExpressionValidator>
class smartLineEditClass : public QLineEdit
{
    Q_OBJECT
public:
    explicit smartLineEditClass(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void textSetAfterClick();
    virtual unsigned int getTextAndCheckIsValid();
    unsigned int getFinalWidthFromPrivate(){return finWidth;}

signals:
    void clicked();
    void finisheEditedAndReturnRes();

private:
    unsigned int finWidth;
};

#endif // SMARTLINEEDITCLASS_H
=======
#ifndef SMARTLINEEDITCLASS_H
#define SMARTLINEEDITCLASS_H

#include <QObject>
#include <QWidget>
#include<QLineEdit>
#include<QMouseEvent>
#include<QMessageBox>
#include<QRegularExpressionValidator>
class smartLineEditClass : public QLineEdit
{
    Q_OBJECT
public:
    explicit smartLineEditClass(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);
    void textSetAfterClick();
    virtual unsigned int getTextAndCheckIsValid();
    unsigned int getFinalWidthFromPrivate(){return finWidth;}

signals:
    void clicked();
    void finisheEditedAndReturnRes();

private:
    unsigned int finWidth;
};

#endif // SMARTLINEEDITCLASS_H
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
