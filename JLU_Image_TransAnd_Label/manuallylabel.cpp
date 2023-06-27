#include "manuallylabel.h"
#include "ui_manuallylabel.h"

manuallyLabel::manuallyLabel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manuallyLabel)
{
setMouseTracking(true);
    showWindow = new setPenWidthWindows;
    isIgnoredAllAndLeave = false;
    ui->setupUi(this);
    ui->editPicLable->initUsrPen();
    qDebug() << "初始化显示标签框代码";
    initTabTextBox();
    initBasicConnection();
    initBasicQuickKey();
}

void manuallyLabel::initBasicConnection()
{
    connect(showWindow,&setPenWidthWindows::finishedEdit,this,&manuallyLabel::updatePenWidth);
    /*connect 一下菜单栏*/

    /*链接更改款式：笔的颜色*/
    connect(ui->actionchangePenColor,&QAction::triggered,this,&manuallyLabel::on_changeColorBtn_clicked);

    /*链接更改款式：笔的粗细*/
    connect(ui->actionchangePenWidth,&QAction::triggered,this,&manuallyLabel::on_changeWidthBtn_clicked);

    /*链接标签管理：增加标签*/
    connect(ui->actionnewLabel,&QAction::triggered,this,&manuallyLabel::on_manageLabelBtn_clicked);

    /*链接标签管理：减少标签*/
    connect(ui->actiondeleteOldLabel,&QAction::triggered,this,&manuallyLabel::on_manageLabelBtn_clicked);

}

void manuallyLabel::initBasicQuickKey()
{
    QAction* toPrevious = new QAction;
    toPrevious->setShortcut(QKeySequence(tr("A")));
    ui->menubar->addAction(toPrevious);
    connect(toPrevious,&QAction::triggered,this,&manuallyLabel::on_toPreviousPic_clicked);

    QAction* toAfter = new QAction;
    toAfter->setShortcut(QKeySequence(tr("D")));
    ui->menubar->addAction(toAfter);
    connect(toAfter,&QAction::triggered,this,&manuallyLabel::on_toPreviousPic_clicked);

    QAction* toPrevious2 = new QAction;
    toPrevious2->setShortcut(QKeySequence(tr("Left")));
    ui->menubar->addAction(toPrevious2);
    connect(toPrevious2,&QAction::triggered,this,&manuallyLabel::on_toPreviousPic_clicked);

    QAction* toAfter2 = new QAction;
    toAfter2->setShortcut(QKeySequence(tr("Right")));
    ui->menubar->addAction(toAfter2);
    connect(toAfter2,&QAction::triggered,this,&manuallyLabel::on_toAfterPic_clicked);
}

void manuallyLabel::initTabTextBox()
{
    QString colorTextSet = "当前的颜色是: RGB(";
    colorTextSet += QString::number(
        *helper_getColorRGBs((ui->editPicLable->getUsrPenInfo().color()))
        );

    colorTextSet += ",";
    colorTextSet += QString::number(
        *(helper_getColorRGBs((ui->editPicLable->getUsrPenInfo().color())) + 1)
        );
    colorTextSet += ",";
    colorTextSet += QString::number(
        *(helper_getColorRGBs((ui->editPicLable->getUsrPenInfo().color())) + 2)
        );

    colorTextSet += ")";
    qDebug() << colorTextSet;
    ui->showCurColorTextBrowser->setText(colorTextSet);

    QString shapeAndPointText = QString("\n当前，你选择了") + QString::number(ui->editPicLable->getCurAllowMaxPointsCount())
                                + QString("点的标注,也就是说你标注的图形状是:") + QString::number(ui->editPicLable->getCurAllowMaxPointsCount())
                                + QString("边形");

    ui->showCurShapeTypeTextBrowser->setText(shapeAndPointText);

    ui->showCurTextLabelCountTextBrowser->setText(USR_DEF_LABLE_COUNT_TEXT);
}

void manuallyLabel::initshowPicWindows()
{
    showPicWindows = new curPicForLabeling_MainWindow;
    showPicWindows->initPicturesListWithPicsPath(groupPicPathLists);
    showPicWindows->initCurUsrPenFromManuallyLabel(ui->editPicLable->getInterFaceQPen());
    showPicWindows->initLabelListFromManuallyLabelWindow(usableLabels);
    connect(showPicWindows,&curPicForLabeling_MainWindow::finishEveryThingAndReturnsTheNewLyLabelPair,
            this,&manuallyLabel::updateExistedLabelList);
    connect(showPicWindows,&curPicForLabeling_MainWindow::refreshLabelMethod,
            this,&manuallyLabel::updateLabelMethod);

    showPicWindows->show();
}

void manuallyLabel::updatePenWidth()
{
    ui->editPicLable->getInterFaceQPen().setWidth(showWindow->getFinalSetPenWidth());
    updateTextBrowsers();
}


void manuallyLabel::updateExistedLabelList()
{
    usableLabels = showPicWindows->returnThelabelsToManuallyLabel();
    for(int i = 0; i < usableLabels.size();i++)
    {
        qDebug() << usableLabels[i];
    }
    updateTextBrowsers();
}

void manuallyLabel::getPixmapPath(QString path)
{
    curViewPicPath = path;
    QImage tmp;
    tmp.load(path);
    ui->editPicLable->setPixmap(QPixmap::fromImage(tmp.scaled(ui->editPicLable->size(),Qt::IgnoreAspectRatio)));
}

void manuallyLabel::setManuallyWindowLabelList(QList<LabelPair> Labellist)
{
    usableLabels = Labellist;
    updateTextBrowsers();
}

void manuallyLabel::setManuallyWindowPixMapLists(QList<QString> mapPicLists)
{

    if(mapPicLists.isEmpty()){
        QMessageBox::critical(this,"？","不是哥们怎么到这里的?");
        return;
    }
    groupPicPathLists = mapPicLists;
    for(int i = 0; i < mapPicLists.size();i++)
    {
        FromMainWindowMapList.push_back(
            QPixmap::fromImage(
                QImage(mapPicLists[i]).scaled(ui->editPicLable->size(),Qt::IgnoreAspectRatio)
                )
            );
    }
    curViewIndex = 0;
    ui->editPicLable->setPixmap(FromMainWindowMapList.first());
    ui->showProgressBar->setRange(0,FromMainWindowMapList.size());
    return;
}

manuallyLabel::~manuallyLabel()
{
    delete ui;
}

void manuallyLabel::closeEvent(QCloseEvent* e){

    if(isIgnoredAllAndLeave){
        emit refreshMainWindowLabelList();
        e->accept();
    }

    if(QMessageBox::Yes == QMessageBox::question(this,"小小的疑问","你确定离开吗?"))
    {
        emit refreshMainWindowLabelList();
        e->accept();
    }
    else{
        e->ignore();
    }
}


void manuallyLabel::on_changeColorBtn_clicked()
{
    ui->editPicLable->getInterFaceQPen().setColor(QColorDialog::getColor());
    updateTextBrowsers();
}

void manuallyLabel::on_changeWidthBtn_clicked()
{
    showWindow->show();

}


void manuallyLabel::getEditedChangedWidth()
{
    ui->editPicLable->getInterFaceQPen().setWidth(showWindow->getFinalSetPenWidth());
}

void manuallyLabel::updateCursingelPictureLabelsRecord()
{
    singelPictureLabelsRecord = showPicWindows->returnLabelResToManuallyLabel();
    updateTextBrowsers();
}

void manuallyLabel::updateTextBrowsers()
{
    QString colorTextSet = "当前的颜色是: RGB(";
    colorTextSet += QString::number(
        *helper_getColorRGBs((ui->editPicLable->getUsrPenInfo().color()))
        );

    colorTextSet += ",";
    colorTextSet += QString::number(
        *(helper_getColorRGBs((ui->editPicLable->getUsrPenInfo().color())) + 1)
        );
    colorTextSet += ",";
    colorTextSet += QString::number(
        *(helper_getColorRGBs((ui->editPicLable->getUsrPenInfo().color())) + 2)
        );

    colorTextSet += ")";
    qDebug() << colorTextSet;
    ui->showCurColorTextBrowser->setText(colorTextSet);
    QString shapeAndPointText;
    if(ui->editPicLable->getCurAllowMaxPointsCount() == 2){
        shapeAndPointText = QString("\n当前，你选择了标准矩形标注");
    }
    else
    {
        shapeAndPointText =   QString("\n当前，你选择了") + QString::number(ui->editPicLable->getCurAllowMaxPointsCount())
                            + QString("点的标注,也就是说你标注的图形状是:")
                            + QString::number(ui->editPicLable->getCurAllowMaxPointsCount())
                            + QString("边形");
    }
    ui->showCurShapeTypeTextBrowser->setText(shapeAndPointText);
    QString showLabel = QString("当前已有标签：") + QString::number(usableLabels.size()) + QString("\n") ;
    for(int i = 0; i < usableLabels.size(); i++)
    {
        showLabel += QString("第") + QString::number(i + 1) + QString("种标签，种类代号为");
        showLabel += ( QString::number(usableLabels[i].first)+ QString(": ") + usableLabels[i].second + QString("\n"));
    }

    ui->showCurTextLabelCountTextBrowser->setText(showLabel);
}

void manuallyLabel::updateLabelMethod()
{
    ui->editPicLable->setCurAllowMaxPointsCount(showPicWindows->curAllowMaxPointsCount);
    updateTextBrowsers();
}

Pair_Label_Shape manuallyLabel::returnSingelPictureLabelsRecord()
{
    return Pair_Label_Shape(singelPictureLabelsRecord);
}



void manuallyLabel::on_activeToLabel_clicked()
{
    initshowPicWindows();
}

 QList<LabelPair> manuallyLabel::returnUsableLabelPairListToMainWindow()
{
    return usableLabels;
 }

void manuallyLabel::on_cancelAllAndBackToMainWindow_clicked()
{
    usableLabels.clear();
    singelPictureLabelsRecord.first.clear();
    singelPictureLabelsRecord.second.clear();
    isIgnoredAllAndLeave = true;
    this->close();
}

void manuallyLabel::updateUsabelLabelsFromLabelQueryDialog()
{
    usableLabels = dialog->reFreshMainWindowsLabelList();
    for(int i = 0; i < usableLabels.size(); i++){
        usableLabels[i].first = i + 1;
    }
    updateTextBrowsers();
}

void manuallyLabel::on_manageLabelBtn_clicked()
{
    dialog = new labelQuerydialog;
    /*通过添加标签获得新的标签*/
    connect(dialog,&labelQuerydialog::finishSelectingLabel,this,&manuallyLabel::updateUsabelLabelsFromLabelQueryDialog);
    dialog->getTheCurrentLabelList(usableLabels);
    dialog->initTextLableShow();
    dialog->showcheckedBoxListsSelections();
    dialog->show();
}


void manuallyLabel::on_saveAllAndExportTheImage_clicked()
{
    QMessageBox::information(this,"保存成功！","你完成了保存！");
    this->close();
}


void manuallyLabel::on_backToDefPen_clicked()
{
    ui->editPicLable->resetPenToDef();
    updateTextBrowsers();
}




void manuallyLabel::on_toPreviousPic_clicked()
{
    curViewIndex--;

    if(curViewIndex <= 0 ){
        QMessageBox::information(this,"注意！","你已经结束浏览最后一张照片，将自动为你跳转到第一张");
        curViewIndex = FromMainWindowMapList.size() - 1;
    }
    ui->editPicLable->setPixmap(FromMainWindowMapList[curViewIndex]);
    refreshProcessBarAndTextBrowser();
}

void manuallyLabel::on_toAfterPic_clicked()
{
    curViewIndex++;
    if(curViewIndex >= FromMainWindowMapList.size()){
        QMessageBox::information(this,"注意！","你已经结束浏览最后一张照片，将自动为你跳转到第一张");
        curViewIndex = 0;
    }
    qDebug() << curViewIndex;
    ui->editPicLable->setPixmap(FromMainWindowMapList[curViewIndex]);
    refreshProcessBarAndTextBrowser();
}

void manuallyLabel::refreshProcessBarAndTextBrowser()
{
    ui->showProgressBar->setValue(curViewIndex);
    ui->showCurProcess->setText("当前你在第 " + QString::number(curViewIndex-1) +" 张图片处！");
}


