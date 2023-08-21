<<<<<<< HEAD
#include "smartlineeditclass.h"

#define USR_DEF_TEXT ""


smartLineEditClass::smartLineEditClass(QWidget *parent)
    : QLineEdit{parent}
{
    this->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+$")));
    finWidth = 3;
    connect(this,&smartLineEditClass::clicked,this,&smartLineEditClass::textSetAfterClick);
    connect(this,&smartLineEditClass::editingFinished,this,&smartLineEditClass::getTextAndCheckIsValid);
}

void smartLineEditClass::mousePressEvent(QMouseEvent* e)
{
    //如果单击了就触发clicked信号
    if (e->button() == Qt::LeftButton)
    {
        //触发clicked信号
        emit clicked();
    }
    //将该事件传给父类处理
    QLineEdit::mousePressEvent(e);
}

void smartLineEditClass::textSetAfterClick()
{
    this->setText(USR_DEF_TEXT);
}

unsigned int smartLineEditClass::getTextAndCheckIsValid()
{
    int getter = this->text().toInt();
    if(getter <= 0)
    {
        QString thisText = QString("欸呀呀，知道你小子要整活！爬！");
        QMessageBox::critical(NULL,"Oppppps",thisText);
        return finWidth;
    }
    if(getter > 50){
        QString thisText = QString("什么几把玩意，你确定你小子是") +QString::number(getter) + QString("pixels? 别闹！不理会这一数值!");
        QMessageBox::critical(NULL,"Oppppps",thisText);
        return finWidth;
    }
    finWidth = getter;
    emit finisheEditedAndReturnRes();
    return static_cast<unsigned int>(getter);
}
=======
#include "smartlineeditclass.h"

#define USR_DEF_TEXT ""


smartLineEditClass::smartLineEditClass(QWidget *parent)
    : QLineEdit{parent}
{
    this->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]+$")));
    finWidth = 3;
    connect(this,&smartLineEditClass::clicked,this,&smartLineEditClass::textSetAfterClick);
    connect(this,&smartLineEditClass::editingFinished,this,&smartLineEditClass::getTextAndCheckIsValid);
}

void smartLineEditClass::mousePressEvent(QMouseEvent* e)
{
    //如果单击了就触发clicked信号
    if (e->button() == Qt::LeftButton)
    {
        //触发clicked信号
        emit clicked();
    }
    //将该事件传给父类处理
    QLineEdit::mousePressEvent(e);
}

void smartLineEditClass::textSetAfterClick()
{
    this->setText(USR_DEF_TEXT);
}

unsigned int smartLineEditClass::getTextAndCheckIsValid()
{
    int getter = this->text().toInt();
    if(getter <= 0)
    {
        QString thisText = QString("欸呀呀，知道你小子要整活！爬！");
        QMessageBox::critical(NULL,"Oppppps",thisText);
        return finWidth;
    }
    if(getter > 50){
        QString thisText = QString("什么几把玩意，你确定你小子是") +QString::number(getter) + QString("pixels? 别闹！不理会这一数值!");
        QMessageBox::critical(NULL,"Oppppps",thisText);
        return finWidth;
    }
    finWidth = getter;
    emit finisheEditedAndReturnRes();
    return static_cast<unsigned int>(getter);
}
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
