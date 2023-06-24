#include "manuallylabel.h"
#include "ui_manuallylabel.h"
#define UNSAVE  0
#define SAVE    1

#define DEF_PEN_COLOR QColor(255,0,0)
#define DEF_PEN_CURDRAW_COLOR QColor(255,0,0)
#define DEF_PRN_WIDTH 3

manuallyLabel::manuallyLabel(QString curViewPath,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::manuallyLabel)
{
setMouseTracking(true);
    QImage tmp;
    tmp.load(curViewPath);
    showWindow = new setPenWidthWindows;
    curViewPicPath = curViewPath;
    ui->setupUi(this);
    isSave = UNSAVE;
    ui->editPicLable->initPixelMap(curViewPath);
    ui->editPicLable->setPixmap(QPixmap::fromImage(tmp.scaled(ui->editPicLable->size(),Qt::IgnoreAspectRatio)));
    ui->editPicLable->initUsrPen();
    initTabTextBox();
    connect(showWindow,&setPenWidthWindows::finishedEdit,this,&manuallyLabel::updateCursingelPictureLabelsRecord);

    connect(showPicWindows,&curPicForLabeling_MainWindow::finishEveryThingAndReturnsTheNewLyLabelPair,
            this,&manuallyLabel::updateExistedLabelList);
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
    emit refreshMainWindowLabelList();
    if(QMessageBox::Yes == QMessageBox::question(this,"小小的疑问","你确定离开吗?"))
    {
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
    QString showLabel = QString("当前已有标签：") + QString::number(singelPictureLabelsRecord.second.size()) + QString("\n") ;
    for(int i = 0; i < usableLabels.size(); i++)
    {
        showLabel += QString("第") + QString::number(i + 1) + QString("张轮廓: 标签种类代号为");
        showLabel += ( QString::number(usableLabels[i].first)+ QString(": ") + usableLabels[i].second + QString("\n"));
    }

    ui->showCurTextLabelCountTextBrowser->setText(showLabel);
}

void manuallyLabel::on_cancelAllAndBackToMainWindow_clicked()
{
    if(isSave == UNSAVE)
    {
        if(QMessageBox::Yes == QMessageBox::question(NULL,"喂！！等等！","拜托兄弟，真的不保存一下嘛(点击确定保存哦)，你做出的更改会消失很久很久的!"))
        {
            saveProcess();
            isSave = SAVE;
        }

    }
}

void manuallyLabel::saveProcess()
{
    if(curPixPicMap.isNull())
    {
        QMessageBox::critical(NULL,"阿哲","嗯，我很是怀疑你怎么到达这里的...快点反馈给我bug!");
        return;
    }
Cancel:
    QString savePath = QFileDialog::getExistingDirectory(this,"选择目录");
    if(savePath.isNull()){
        if(QMessageBox::Yes == QMessageBox::question(NULL,"确认一下","不保存了？"))
        {
            return;
        }
        else
        {
            goto Cancel;
        }
    }

    savePath += QString("/") + (curViewPicPath.split("/").last().split(".").first());
    savePath += QString("afterLabeled.png");
    qDebug()<< savePath;

    qDebug()<<ui->editPicLable->getAfterEditedPixMap().save(savePath);

    return;
}

Pair_Label_Shape manuallyLabel::returnSingelPictureLabelsRecord()
{
    return Pair_Label_Shape(singelPictureLabelsRecord);
}

void manuallyLabel::on_saveAllAndExportTheImage_clicked()
{
    saveProcess();
}

void manuallyLabel::initshowPicWindows()
{
    showPicWindows = new curPicForLabeling_MainWindow;
    showPicWindows->getPictures(curViewPicPath);
    showPicWindows->initCurUsrPenFromManuallyLabel(ui->editPicLable->getInterFaceQPen());
    showPicWindows->initLabelListFromManuallyLabelWindow(usableLabels);
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
