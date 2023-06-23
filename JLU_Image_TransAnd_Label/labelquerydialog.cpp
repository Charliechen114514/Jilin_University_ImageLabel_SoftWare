#include "labelquerydialog.h"
#include "ui_labelquerydialog.h"

labelQuerydialog::labelQuerydialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labelQuerydialog)
{
    ui->setupUi(this);
    labelList.clear();
    connect(ui->getTextedLineEdit,&labelsQueryTextClass::finisheEditedAndReturnRes,
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
        ui->showLabelCountsTxtBrowser->setText("现在尚无标签，添加一个吧！awa");
        return;
    }

    for(int i =0; i < labelList.size(); i++)
    {
        QString textCount = QString("现在有标签") + QString::number(labelList.size()) + QString("个！");
        ui->showLabelCountsTxtBrowser->setText(textCount);
        QCheckBox* curBox = new QCheckBox;
        QString curText = QString::number(labelList[i].first) + QString(": ") + labelList[i].second;
        curBox->setText(curText);
        curBox->autoExclusive();
        checkedBoxLists.append(curBox);
    }
}

void labelQuerydialog::on_acceptAndAddBtn_clicked()
{
    labelList.append(QPair<LabelIndex,LabelName>(labelList.size(),ui->getTextedLineEdit->getResultedLabelName()));
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
    qDebug() << labelList.size()+1 << ui->getTextedLineEdit->getResultedLabelName();
    QCheckBox* newBox = new QCheckBox();
    QString checkBoxText = QString::number(labelList.size()) + QString(": ") + ui->getTextedLineEdit->getResultedLabelName();
    newBox->setText(checkBoxText);
    checkedBoxLists.append(newBox);
    for(int i=0; i<checkedBoxLists.size(); i++)
    {
        for(int j=i+1; j<checkedBoxLists.size(); j++)
        {
            if(checkedBoxLists.at(i)->text() == checkedBoxLists.at(j)->text())
            {
                checkedBoxLists.removeAt(j);
                j--;
            }
        }
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


