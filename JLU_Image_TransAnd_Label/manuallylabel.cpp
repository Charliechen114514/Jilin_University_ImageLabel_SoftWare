#include "manuallylabel.h"
#include "ui_manuallylabel.h"


manuallyLabel::manuallyLabel(QString curViewPath,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manuallyLabel)
{
setMouseTracking(true);
    QImage tmp;
    tmp.load(curViewPath);
    showWindow = new setPenWidthWindows;
    curViewPicPath = curViewPath;
    isIgnoredAllAndLeave = false;
    ui->setupUi(this);
    ui->editPicLable->initPixelMap(curViewPath);
    ui->editPicLable->setPixmap(QPixmap::fromImage(tmp.scaled(ui->editPicLable->size(),Qt::IgnoreAspectRatio)));
    ui->editPicLable->initUsrPen();
    qDebug() << "初始化显示标签框代码";
    initTabTextBox();
    connect(showWindow,&setPenWidthWindows::finishedEdit,this,&manuallyLabel::updateCursingelPictureLabelsRecord);
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


manuallyLabel::~manuallyLabel()
{
    delete ui;
}

void manuallyLabel::closeEvent(QCloseEvent* e){

    if(isIgnoredAllAndLeave){
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
void qDebugTheLabelList(QList<LabelPair> listPair)
{
    if(listPair.isEmpty()){
        qDebug() << "LabelList is NULL";
        return;
    }
    for(int i = 0; i < listPair.size();i++)
    {
        qDebug() << "标签号" <<  listPair[i].first << " 标签名称: " << listPair[i].second;
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
    updateTextBrowsers();
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

    QString shapeAndPointText = QString("\n当前，你选择了") + QString::number(ui->editPicLable->getCurAllowMaxPointsCount())
                                + QString("点的标注,也就是说你标注的图形状是:") + QString::number(ui->editPicLable->getCurAllowMaxPointsCount())
                                + QString("边形");

    ui->showCurShapeTypeTextBrowser->setText(shapeAndPointText);
    QString showLabel = QString("当前已有标签：") + QString::number(usableLabels.size()) + QString("\n") ;
    for(int i = 0; i < usableLabels.size(); i++)
    {
        showLabel += QString("第") + QString::number(i + 1) + QString("种标签，种类代号为");
        showLabel += ( QString::number(usableLabels[i].first)+ QString(": ") + usableLabels[i].second + QString("\n"));
    }

    ui->showCurTextLabelCountTextBrowser->setText(showLabel);
}


Pair_Label_Shape manuallyLabel::returnSingelPictureLabelsRecord()
{
    return Pair_Label_Shape(singelPictureLabelsRecord);
}

void manuallyLabel::initshowPicWindows()
{
    showPicWindows = new curPicForLabeling_MainWindow;
    showPicWindows->getPictures(curViewPicPath);
    showPicWindows->initCurUsrPenFromManuallyLabel(ui->editPicLable->getInterFaceQPen());
    showPicWindows->initLabelListFromManuallyLabelWindow(usableLabels);
    connect(showPicWindows,&curPicForLabeling_MainWindow::finishEveryThingAndReturnsTheNewLyLabelPair,
            this,&manuallyLabel::updateExistedLabelList);
    showPicWindows->show();
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

