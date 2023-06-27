#include "setorshiftcurmaxpointcountswindows.h"
#include "ui_setorshiftcurmaxpointcountswindows.h"

setOrShiftCurMaxPointCountsWindows::setOrShiftCurMaxPointCountsWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setOrShiftCurMaxPointCountsWindows)
{
    ui->setupUi(this);
    initBasicSelectionCheckBox();
    showSelections();
}


void setOrShiftCurMaxPointCountsWindows::initBasicSelectionCheckBox()
{
    checkBoxNameList.push_back(QString("2. 标准输入"));
    checkBoxNameList.push_back(QString("4. 任意四边形标注"));
    checkBoxNameList.push_back(QString("5. 任意五边形标注"));
    for(int i = 0; i < checkBoxNameList.size(); i++)
    {
        QCheckBox* curBox = new QCheckBox;
        curBox->setText(checkBoxNameList[i]);
        curBox->autoExclusive();
        checkBoxList.push_back(curBox);
    }
    qDebug() << checkBoxList.size();
    showSelections();
}

void setOrShiftCurMaxPointCountsWindows::showSelections()
{
    QPoint showPoint(QPoint(startShowPoint));
    qDebug() << "当前的盒子链表大小"<<checkBoxList.size();
    for(int i = 0; i < checkBoxList.size(); i++)
    {
        ui->verticalLayout->addWidget(checkBoxList[i]);
        checkBoxList[i]->setGeometry(showPoint.x(),showPoint.y(),Show_WIDTH,Show_Height);
        showPoint.setY(showPoint.y() + ShowPoint_OFFSET_Y);
        checkBoxList[i]->show();
        selections.addButton(checkBoxList[i]);
        update();
    }
    return;
}

setOrShiftCurMaxPointCountsWindows::~setOrShiftCurMaxPointCountsWindows()
{
    delete ui;
}


void setOrShiftCurMaxPointCountsWindows::on_ensureSelectAndCheckIfLegal_clicked()
{
    if(selections.checkedId() == -1)
    {
        QMessageBox::critical(this,"喂喂喂","别跑，你还没选");
        return;
    }

    QString numGetter = selections.checkedButton()->text().split(".").first();
    selectedFinalCurMaxPointCount = numGetter.toInt();

    qDebug() << selectedFinalCurMaxPointCount;
    emit finishSelectAndReadyReturn();
    qDebug() << "向标记窗口发送了 " << selectedFinalCurMaxPointCount;
    this->close();
}

