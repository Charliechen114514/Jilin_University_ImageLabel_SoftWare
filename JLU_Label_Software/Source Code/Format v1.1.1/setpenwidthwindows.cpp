#include "setpenwidthwindows.h"
#include "ui_setpenwidthwindows.h"

setPenWidthWindows::setPenWidthWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setPenWidthWindows)
{
    ui->setupUi(this);
    connect(ui->widthSelfGetter,&smartLineEditClass::finisheEditedAndReturnRes,this,&setPenWidthWindows::getFinalEditWidth);
}

setPenWidthWindows::~setPenWidthWindows()
{
    delete ui;
}

void setPenWidthWindows::on_qulifiedOrRefuse_rejected()
{
    this->close();
}


void setPenWidthWindows::on_qulifiedOrRefuse_accepted()
{
    QString thisText = QString("确认一下是不是这个长度AwA: ") + QString::number(finWidth);
    if(QMessageBox::Yes == QMessageBox::question(this,"确认一下",thisText))
    {
        QString ensureText = QString("确认成功YAY: ") + QString::number(finWidth);
        emit finishedEdit();
        QMessageBox::information(this,"Successful!",ensureText);
        this->close();
    }
    else
    {
        QMessageBox::information(this,"取消!","好好好，我当作没看见");
        return;
    }
}


void setPenWidthWindows::on_checkBox_clicked()
{
    finWidth = 3;
}


void setPenWidthWindows::on_checkBox_2_clicked()
{
    finWidth = 5;
}


void setPenWidthWindows::on_checkBox_3_clicked()
{
    finWidth = 7;
}

void setPenWidthWindows::on_checkBox_4_clicked()
{
    finWidth = 9;
}

void setPenWidthWindows::getFinalEditWidth()
{
    finWidth = ui->widthSelfGetter->getFinalWidthFromPrivate();
}

