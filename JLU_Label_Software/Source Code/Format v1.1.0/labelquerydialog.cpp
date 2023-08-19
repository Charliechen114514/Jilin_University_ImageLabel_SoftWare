#include "labelquerydialog.h"
#include "ui_labelquerydialog.h"
labelQuerydialog::labelQuerydialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::labelQuerydialog)
{
    ui->setupUi(this);
    this->setWindowTitle("标签管理窗口");
    isAdded = false;
    deleteProcessIn = false;
    ui->getTextedLineEdit->setText(LABELEDIT_DEF_LABLE);
    seperator = ";";
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
//    for(int i = 0; i < labelList.size(); i++)
//    {
//        qDebug() << labelList[i].first << ":  " << labelList[i].second;
//    }
}

void labelQuerydialog::removePossibleRepititionLabelsAndReEnum()
{
    if(labelList.empty())
    {
        return;
    }

    for(int i = 0; i < labelList.size(); i++)
    {
        for(int j = i; j < labelList.size(); j++)
        {
            if(labelList[i].second == labelList[j].second)
            {
                labelList.removeAt(j);
                j--;
            }
        }
    }

    for(int i = 0; i < labelList.size(); i++)
    {
        labelList[i].first = i + 1;
    }
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
        QString checkBoxText = QString::number(labelList.size()) + QString(":") + ui->getTextedLineEdit->getResultedLabelName();
//        qDebug() << "准备添加复选框内容" << checkBoxText;
//        qDebug() << labelList.size();
//            for(int i = 0; i < labelList.size(); i++)
//            {
//                qDebug() << labelList[i].first << ":  " << labelList[i].second;
//            }
        newBox->setText(checkBoxText);
        checkedBoxLists.append(newBox);
    }
    showcheckedBoxListsSelections();
    isAdded = true;
}

void labelQuerydialog::showcheckedBoxListsSelections()
{
    if(checkedBoxLists.empty()){
        qDebug() << "检测到空显示框";
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
    update();
}

void labelQuerydialog::on_rejectAndTryAgainBtn_clicked()
{
    if(isAdded == false){
        QMessageBox::information(this,"?","哥们没更改啊！");
        return;
    }

    if(labelList.empty()){
        QMessageBox::information(this,"?","别点了别点了，没了没了");
        return;
    }

    labelList.removeLast();
    ui->showbox->removeWidget(checkedBoxLists.last());
    checkedBoxLists.removeLast();
    QMessageBox::information(this,"操作成功","成功撤销你上一步添加");
    QString textCount = QString("现在有标签") + QString::number(labelList.size()) + QString("个！");
    ui->showLabelCountsTxtBrowser->setText(textCount);
    isAdded = false;
}

void labelQuerydialog::closeEvent(QCloseEvent* e)
{
    if(isSave == false)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"你没保存就跑啊","（想跑路？）点击No当作无事发生，Yes请选择标签在x"))
        {
            e->ignore();
        }
        else
        {
            emit refuseSaving();
            e->accept();
        }
    }
}

void labelQuerydialog::on_ensureTheLabelRes_clicked()
{
    if(checkBoxLists->checkedId() == -1)
    {
        QMessageBox::critical(this,"啊？","你这不还没选标签嘛，急啥啊?");
        return;
    }

    if(deleteProcessIn == true)
    {
        deleteProcessIn = false;
        this->close();
    }

    finalLabel = QPair<LabelIndex,LabelName>(checkBoxLists->checkedId() + 1,\
                                            checkBoxLists->checkedButton()->text().split(":").last());
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
    isSave = true;
    this->close();
}


void labelQuerydialog::on_removeLabelButton_clicked()
{
    if(labelList.empty())
    {
        QMessageBox::critical(this,"啊？","你没有办法移除一个本来就是一坨空的东西");
        return;
    }
    if(isAdded == true)
    {
        if(QMessageBox::Yes == QMessageBox::question(this,"阿哲","这边提供按扭撤销操作，想不想我帮你嗯?"))
        {
            on_rejectAndTryAgainBtn_clicked();
            return;
        }
        else
        {
            QMessageBox::information(this,"今日无事","今日无事------路易十六特供（笑）");
            return;
        }
    }
    int RemoveIndex = checkBoxLists->checkedId();
    if(RemoveIndex == -1)
    {
        QMessageBox::critical(this,"啊？","你不告诉我你想移除哪一个，我唯一能做的就是帮你算一卦");
        return;
    }
    if(QMessageBox::No == QMessageBox::question(this,"别反悔兄弟","真的移除标签?这个操作可是不可逆的!!!!!:\n" + labelList[RemoveIndex].second))
    {
        QMessageBox::information(this,"啊哈，就知道","好吧，爬");
        return;
    }
    deleteProcessIn = true;
    qDebug() << " 现在的RemoveIndex是"<< RemoveIndex;
    qDebug() << labelList[RemoveIndex];
    labelList.removeAt(RemoveIndex);
    ui->getTextedLineEdit->setText("");
    update();
    on_ensureTheLabelRes_clicked();

}


void labelQuerydialog::on_btn_importLabels_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this,"选择准备导入的已有的标签文件",".","txt文件(.txt)");
    if(filePath.isEmpty())
    {
        return;
    }
    qDebug() << filePath;
    QFile readLabel(filePath);
    readLabel.open(QIODevice::ReadOnly);
    QStringList labels = QString(readLabel.readAll()).split(seperator);
    if(labels.empty())
    {
        QMessageBox::critical(this,"发生错误","喂！怎么是空的啊！");
    }
    LabelPair temp;
    int curIndex = 0;
    if(labelList.empty())
    {
        curIndex = 1;
    }
    else
    {
        curIndex = labelList.last().first + 1;
    }

    bool duplicateFlag = false;
    for(int i = 0; i < labels.size(); i++)
    {
        qDebug() << labels[i];
        temp.first = curIndex;
        temp.second = labels[i];
        if(temp.second == ""){
            continue;
        }
        for(int j = 0; j < labelList.size();j++)
        {
            if(temp.second == labelList[j].second)
            {
                duplicateFlag = true;
                break;
            }
        }
        if(duplicateFlag)
        {
            duplicateFlag = false;
            continue;
        }
        labelList.push_back(temp);
        curIndex++;
        QCheckBox* newBox = new QCheckBox();
        QString checkBoxText = QString::number(labelList.size()) + QString(":") + temp.second;
        //        qDebug() << "准备添加复选框内容" << checkBoxText;
        //        qDebug() << labelList.size();
        //            for(int i = 0; i < labelList.size(); i++)
        //            {
        //                qDebug() << labelList[i].first << ":  " << labelList[i].second;
        //            }
        newBox->setText(checkBoxText);
        checkedBoxLists.append(newBox);
    }

    showcheckedBoxListsSelections();

    return;
}

