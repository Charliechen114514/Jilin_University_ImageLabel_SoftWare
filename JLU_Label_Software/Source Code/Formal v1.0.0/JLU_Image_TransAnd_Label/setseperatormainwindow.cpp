<<<<<<< HEAD
#include "setseperatormainwindow.h"
#include "ui_setseperatormainwindow.h"

SetSeperatorMainWindow::SetSeperatorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetSeperatorMainWindow)
{
    isSave = false;
    ui->setupUi(this); 
}

void SetSeperatorMainWindow::getSeperatorFromMainWindow(QString seperator)
{
    fromMainWindowSeperator = seperator;
    ui->showCurSeperator->setText("当前你的分割符是:\n" + fromMainWindowSeperator);
}


void SetSeperatorMainWindow::getSeperatorFromUsrEditLine()
{
    finalEditResult = ui->lineEdit->text();
    refreshTextBrowser();
}

SetSeperatorMainWindow::~SetSeperatorMainWindow()
{
    delete ui;
}

void SetSeperatorMainWindow::on_ensureTheEditAndWaitedForFinalEnsure_clicked()
{
    getSeperatorFromUsrEditLine();
    if(isSeperatorValid())
    {
        isSave = true;
        return;
    }
    else
    {
        QMessageBox::critical(this,"无效分割符","你输入的分割符无效，请自己重新像一个罢（悲）");
        return;
    }
}


void SetSeperatorMainWindow::on_setSemiBtn_clicked()
{
    finalEditResult = ";";
    refreshTextBrowser();
    isSave = true;
}

void SetSeperatorMainWindow::refreshTextBrowser()
{
    ui->showCurSeperator->setText("当前你的分割符是:\n" + finalEditResult);
    if(finalEditResult == "\n")
    {
        ui->showCurSeperator->setText("当前你的分割符是: Enter键");
    }
    isSave = true;
}

void SetSeperatorMainWindow::on_setEnterBtn_clicked()
{
    finalEditResult = "\n";
    refreshTextBrowser();
    isSave = true;
}

bool SetSeperatorMainWindow::isSeperatorValid()
{
    if(finalEditResult == "")
    {
        return false;
    }

    for(int i = 0; i < finalEditResult.size();i++)
    {
        if(finalEditResult[i] == ' ')
        {
            return false;
        }
    }
    return true;
}

void SetSeperatorMainWindow::on_ensureAndReturnBtn_clicked()
{
    if(finalEditResult == ""){
        QMessageBox::critical(this,"错误","不可以为空");
        return;
    }
    if(isSave == false)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"你没保存","是否保存捏？"))
        {
            getSeperatorFromUsrEditLine();
            if(isSeperatorValid())
            {
                QMessageBox::critical(this,"无效分割符","你输入的分割符无效，请自己重新像一个罢（悲）");
                return;
            }
            isSave = true;
        }
    }
    emit finishEditAndReadyReturn();
    qDebug() << finalEditResult;
    QString showTxt = finalEditResult;
    if(finalEditResult == "\n")
    {
        showTxt = "Enter";
    }
    QMessageBox::information(this,"设置成功！","你设置为" + showTxt);
    this->close();
}


void SetSeperatorMainWindow::on_rejectAndReturnBtn_clicked()
{
    qDebug() << finalEditResult;
    isSave = true;
    this->close();
}

=======
#include "setseperatormainwindow.h"
#include "ui_setseperatormainwindow.h"

SetSeperatorMainWindow::SetSeperatorMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SetSeperatorMainWindow)
{
    isSave = false;
    ui->setupUi(this); 
}

void SetSeperatorMainWindow::getSeperatorFromMainWindow(QString seperator)
{
    fromMainWindowSeperator = seperator;
    ui->showCurSeperator->setText("当前你的分割符是:\n" + fromMainWindowSeperator);
}


void SetSeperatorMainWindow::getSeperatorFromUsrEditLine()
{
    finalEditResult = ui->lineEdit->text();
    refreshTextBrowser();
}

SetSeperatorMainWindow::~SetSeperatorMainWindow()
{
    delete ui;
}

void SetSeperatorMainWindow::on_ensureTheEditAndWaitedForFinalEnsure_clicked()
{
    getSeperatorFromUsrEditLine();
    if(isSeperatorValid())
    {
        isSave = true;
        return;
    }
    else
    {
        QMessageBox::critical(this,"无效分割符","你输入的分割符无效，请自己重新像一个罢（悲）");
        return;
    }
}


void SetSeperatorMainWindow::on_setSemiBtn_clicked()
{
    finalEditResult = ";";
    refreshTextBrowser();
    isSave = true;
}

void SetSeperatorMainWindow::refreshTextBrowser()
{
    ui->showCurSeperator->setText("当前你的分割符是:\n" + finalEditResult);
    if(finalEditResult == "\n")
    {
        ui->showCurSeperator->setText("当前你的分割符是: Enter键");
    }
    isSave = true;
}

void SetSeperatorMainWindow::on_setEnterBtn_clicked()
{
    finalEditResult = "\n";
    refreshTextBrowser();
    isSave = true;
}

bool SetSeperatorMainWindow::isSeperatorValid()
{
    if(finalEditResult == "")
    {
        return false;
    }

    for(int i = 0; i < finalEditResult.size();i++)
    {
        if(finalEditResult[i] == ' ')
        {
            return false;
        }
    }
    return true;
}

void SetSeperatorMainWindow::on_ensureAndReturnBtn_clicked()
{
    if(finalEditResult == ""){
        QMessageBox::critical(this,"错误","不可以为空");
        return;
    }
    if(isSave == false)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"你没保存","是否保存捏？"))
        {
            getSeperatorFromUsrEditLine();
            if(isSeperatorValid())
            {
                QMessageBox::critical(this,"无效分割符","你输入的分割符无效，请自己重新像一个罢（悲）");
                return;
            }
            isSave = true;
        }
    }
    emit finishEditAndReadyReturn();
    qDebug() << finalEditResult;
    QString showTxt = finalEditResult;
    if(finalEditResult == "\n")
    {
        showTxt = "Enter";
    }
    QMessageBox::information(this,"设置成功！","你设置为" + showTxt);
    this->close();
}


void SetSeperatorMainWindow::on_rejectAndReturnBtn_clicked()
{
    qDebug() << finalEditResult;
    isSave = true;
    this->close();
}

>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
