#include "autolabelwindow.h"
#include "ui_autolabelwindow.h"

#define NUM(n) QString::number(n)
#define DEF_SAVE_PATH "D:/QT projects/build-JLU_Image_TransAnd_Label-Desktop_Qt_6_6_0_MSVC2019_64bit_qt_qt6-Debug/res/1.txt"
/* AutoLableWindow defines here*/
AutoLabelWindow::AutoLabelWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AutoLabelWindow)
{
    setMouseTracking(true);
    curViewIndex = 0;
    ticks = 0;
    isROISet =false;
    isROIRefreshed = false;
    picPathLists.clear();
    labelList.clear();
    tracker = cv::TrackerCSRT::create();
    ui->setupUi(this);
}

AutoLabelWindow::~AutoLabelWindow()
{
    delete ui;
}

void AutoLabelWindow::keyPressEvent(QKeyEvent* env)
{
    if(env->key() == Qt::Key_Right){
        if(!isROISet)
        {
            QMessageBox::critical(this,"ERROR","WK,大哥你告诉我检测啥！");
            return;
        }

        curViewIndex++;
        pushBackToDataLists();
        updateRectByTracker();
        showPicOnWnd();
    }

}

void AutoLabelWindow::mousePressEvent(QMouseEvent* env)
{
    /* TODO: waiting for better solution */
    if(env->button() == Qt::LeftButton)
    {
        ticks++;
        tmp_ROIPoint.push_back(env->pos());
        if(ticks == 1)
        {
            isROIRefreshed = true;
        }
        if(ticks == 2){
            setROIRect();
            ticks = 0;
            autoWork();
        }
    }
}

void AutoLabelWindow::updateRectByTracker()
{
    if(isROISet == false)
    {
        QMessageBox::critical(this,"ERROR","尚未设置ROI呢，你在干什么（恼）");
        return;
    }

    if(isROIRefreshed)
    {
        QMessageBox::critical(this,"ERROR","111哥们你还没选♂完ROI区域");
        return;
    }
    if(curViewIndex >= picPathLists.size())
    {
        return;
    }
    cv::Mat curCVPic = cv::imread(picPathLists[curViewIndex].toStdString());
    tracker->update(curCVPic,curRect);
}

void AutoLabelWindow::showPicOnWnd()
{
    if(curViewIndex >= picPathLists.size()){
        QMessageBox::information(this,"过头了","你已经到达最后一张，结束标记！");
        this->close();
        return; // 防止子窗口进程没有析构带来后面的访问溢出
    }
    curPic.load(picPathLists[curViewIndex]);
    curPic = curPic.scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    QPainter painter(&curPic);
    painter.drawPixmap(0, 0, curPic);
    this->resize(curPic.size());
    update();
}

void AutoLabelWindow::autoWork()
{
    cv::Mat curCVPic = cv::imread(picPathLists[curViewIndex].toStdString());
    tracker->init(curCVPic,curRect);
    repaint();
}

void AutoLabelWindow::setROIRect()
{
    if(tmp_ROIPoint.size() != 2)
    {
        QMessageBox::critical(this,"OOOPPPSSS","ROI表点出现了问题——大小不是2，导致歧义标注!");
        return;
    }

    curRect = QRectToCVRect(QRect(tmp_ROIPoint[0],tmp_ROIPoint[1]));
    isROIRefreshed = false;
    isROISet = true;

    tmp_ROIPoint.clear();
}

void AutoLabelWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor(255,0,0));
    painter.drawPixmap(0,0,curPic);
    painter.end();
    painter.begin(this);
    painter.setPen(pen);
    painter.drawRect(CVRectToQRect(curRect));
}

void AutoLabelWindow::pushBackToDataLists()
{
    qDebug() << curRect.x << "  " << curRect.y <<"  " << this->width() <<"  " << this->height();
    dataList.push_back(

        SinglePicData(
            CVRectToQRect(curRect),
            labelList[0].first,
            this->width(),
            this->height()
            )
        );

#if 1
    SinglePicData test(
        CVRectToQRect(curRect),
        labelList[0].first,
        this->width(),
        this->height()
        );

    qDebug() << test.m_cx << test.m_cy << test.m_x << test.m_y;
#endif
}

void AutoLabelWindow::mouseMoveEvent(QMouseEvent* env[[maybe_unused]])
{
    if(isROIRefreshed)
    {
        qDebug() << "111";
        QPen pen;
        pen.setWidth(5);
        pen.setColor(QColor(255,0,0));
        QPainter tmp(this);
        QRect rect(tmp_ROIPoint[0],env->pos());
        tmp.drawRect(rect);
        repaint();
    }
}

/* singeldata */
SinglePicData::SinglePicData(QRect rect,LabelIndex labelIndex, unsigned int picSizeX, unsigned int picSizeY)
{
    qDebug() << picSizeX;
    m_cx = (double)rect.center().x() / picSizeX;
    qDebug() << m_cx;
    m_cy = (double)rect.center().y() / picSizeY;
    m_x =  (double)rect.width() / picSizeX;
    m_y = (double)rect.height() / picSizeY;
    this->labelIndex = labelIndex;
    this->picSizeX = picSizeX;
    this->picSizeY = picSizeY;
}

void AutoLabelWindow::saveToPlace()
{
    QString reslist = writingMethod();
    QFile saveFile(savePath);
    if(saveFile.open(QIODevice::ReadWrite|QIODevice::Text))
    {
        QTextStream out(&saveFile);
        out << reslist;
        saveFile.close();
    }
    qDebug() << "写完！";
    return;
}

QString AutoLabelWindow::writingMethod()
{

    QString tmp;
    for(unsigned int i = 0; i < dataList.size();i++)
    {
        qDebug() << dataList[i].m_cx;
        tmp += NUM(dataList[i].labelIndex) + " "
              + NUM(dataList[i].m_cx)+ " "
              + NUM(dataList[i].m_cy)+ " "
              + NUM(dataList[i].m_x) + " "
              + NUM(dataList[i].m_y)+ "\n";
    }
    return tmp;
}

void AutoLabelWindow::closeEvent(QCloseEvent* env[[maybe_unused]])
{
    saveToPlace();
}


