#include "labelquerydialog.h"
#include "ui_labelquerydialog.h"



labelQuerydialog::labelQuerydialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labelQuerydialog)
{
    ui->setupUi(this);
    firstIndex = 0;
    ui->getTextedLineEdit->setText(LABELEDIT_DEF_LABLE);
    connect(ui->getTextedLineEdit,&labelsQueryTextClass::finishEditingLabels,
            this,&labelQuerydialog::on_acceptAndAddBtn_clicked);
    checkBoxLists = new QButtonGroup;
}

labelQuerydialog::~labelQuerydialog()
{
    delete ui;
}

void labelQuerydialog::getTheCurrentLabelList(QList<LabelPair> labelListFrowOutward)
{
    labelList = labelListFrowOutward;
}

void labelQuerydialog::initTextLableShow()
{
    if(labelList.empty())
    {
        ui->showLabelCountsTxtBrowser->setText(LABELEDIT_DEFSHOW);
        return;
    }

    for(int i =0; i < labelList.size(); i++)
    {
        QString textCount = QString("现在有标签") + QString::number(labelList.size()) + QString("个！");
        ui->showLabelCountsTxtBrowser->setText(textCount);
        QCheckBox* curBox = new QCheckBox;
        QString curText = QString::number(labelList[i].first) + QString(":") + labelList[i].second;
        curBox->setText(curText);
        curBox->autoExclusive();
        checkedBoxLists.append(curBox);
    }
}

void labelQuerydialog::on_acceptAndAddBtn_clicked()
{
    if(ui->getTextedLineEdit->text() == QString(LABELEDIT_DEF_LABLE)
        || ui->getTextedLineEdit->text() == QString(""))
    {
        QMessageBox::critical(NULL,"你小子","小子，还没label呢点个锤子");
        return;
    }
    /*成功优化：不必每次链表去重！*/
    QString curLabelName = ui->getTextedLineEdit->getResultedLabelName();
    qDebug() << "拿到标签" << curLabelName;
    bool isAlreadyExisted = false;
    for(int i = 0; i < labelList.size(); i++)
    {
        if(labelList.at(i).second == curLabelName)
        {
            QMessageBox::warning(this,"注意！","已经存在这个标签了！");
            isAlreadyExisted = true;
        }
    }
    if(isAlreadyExisted == false)
    {
        labelList.append(QPair<LabelIndex,LabelName>(labelList.size() - 1,curLabelName));
        QCheckBox* newBox = new QCheckBox();
        QString checkBoxText = QString::number(static_cast<const int>(labelList.size()) + firstIndex) + QString(":") + ui->getTextedLineEdit->getResultedLabelName();
        newBox->setText(checkBoxText);
        checkedBoxLists.append(newBox);
    }
    showcheckedBoxListsSelections();
}

void labelQuerydialog::showcheckedBoxListsSelections()
{
    if(checkedBoxLists.empty()){
        return;
    }
    else
    {
        QString textCount = QString("现在有标签") + QString::number(labelList.size()) + QString("个！");
        ui->showLabelCountsTxtBrowser->setText(textCount);
        QPoint showStart = QPoint(CHECKBOXSTARTSHOW_X ,CHECKBOXSTARTSHOW_Y);
        for(int i = 0; i < checkedBoxLists.size(); i++)
        {
            ui->showbox->addWidget(checkedBoxLists[i]);
            if(showStart.y() + CHECKBOXSHOW_HEIGHT >= height())
            {
                showStart.setY(CHECKBOXSTARTSHOW_Y);
                showStart.setX(CHECKBOXSTARTSHOW_X + CHECKBOXSHOW_INTERNAL_X);
            }
            checkedBoxLists[i]->setGeometry(showStart.x(),showStart.y(),CHECKBOXSHOW_WIDTH,CHECKBOXSHOW_HEIGHT);
            checkedBoxLists[i]->show();
            showStart.setY(showStart.y() + CHECKBOXSHOW_INTERNAL_Y);
        }
        for(int i = 0; i < checkedBoxLists.size();i++)
        {
            checkBoxLists->addButton(checkedBoxLists[i],i);
        }
    }
}

void labelQuerydialog::on_rejectAndTryAgainBtn_clicked()
{
    ui->getTextedLineEdit->setText(LABELEDIT_DEFSHOW);
}


void labelQuerydialog::on_ensureTheLabelRes_clicked()
{
    if(checkBoxLists->checkedId() == -1)
    {
        QMessageBox::critical(NULL,"啊？","你这不还没选标签嘛，急啥啊?");
        return;
    }

    finalLabel = QPair<LabelIndex,LabelName>(checkBoxLists->checkedId() + 1,checkBoxLists->checkedButton()->text().split(":").last());
    for(int i=0; i<labelList.size(); i++)
    {
        for(int j=i+1; j<labelList.size(); j++)
        {
            if(labelList.at(i).second == labelList.at(j).second)
            {
                labelList.removeAt(j);
                j--;
            }
        }
    }
    emit finishSelectingLabel();

    this->close();
}

