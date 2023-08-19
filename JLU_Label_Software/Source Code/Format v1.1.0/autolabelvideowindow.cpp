#include "autolabelvideowindow.h"
#include "ui_autolabelvideowindow.h"

AutoLabelVideoWindow::AutoLabelVideoWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AutoLabelVideoWindow)
{
    ui->setupUi(this);
    isSelectedTrack = false;
    ticks = 0;
    tracker = cv::TrackerCSRT::create();
    spliter = new QTimer;
    spliter->setInterval(500);
    spliter->start();
    displayer = new QTimer;
    displayer->setInterval(30);
    displayer->start();
    shallPlaying = false;
    isROISet =false;
    isROIRefreshed = false;
    initBasicConnection();
}

void AutoLabelVideoWindow::updateTracker()
{
    if(isROISet){
        tracker->update(curFrame,curRect);
    }
}


void AutoLabelVideoWindow::initBasicConnection()
{
    connect(displayer,&QTimer::timeout,this,&AutoLabelVideoWindow::showVideoOnWnd);
}

void AutoLabelVideoWindow::mousePressEvent(QMouseEvent* env)
{
    if(env->button() == Qt::LeftButton)
    {
        ticks++;
        tmp_ROIRect.push_back(env->pos());
        if(ticks == 1)
        {
            shallPlaying = false;
            isROIRefreshed = true;
        }
        if(ticks == 2)
        {
            setROIRect();
            ticks = 0;
            autoWork();
        }
    }
}

void AutoLabelVideoWindow::autoWork()
{
    if(curFrame.empty()){
        QMessageBox::critical(this,"OOOPPPSSS","无法标注！记载帧curFrame为空！");
        return;
    }
    tracker->init(curFrame,curRect);
    repaint();
}

void AutoLabelVideoWindow::setROIRect()
{
    if(tmp_ROIRect.size() != 2){
        QMessageBox::critical(this,"Error","ROI表点出现了问题——大小不是2，导致歧义标注!");
    }

    curRect = QRectToCVRect(QRect(tmp_ROIRect[0],tmp_ROIRect[1]));
    isROIRefreshed = false;
    isROISet = true;
    isFinishPlaying = false;
    QMessageBox::information(this,"OK!","成功设置ROI!");
    isSelectedTrack = true;
    spliter->start();
    tmp_ROIRect.clear();
}


void AutoLabelVideoWindow::showVideoOnWnd()
{
    if(shallPlaying)
    {
        *videoHandle >> curFrame;
        if(curFrame.empty()){
            isFinishPlaying = true;
            return;
        }
        updateTracker();
        repaint();
    }
}

void AutoLabelVideoWindow::paintEvent(QPaintEvent* env[[maybe_unused]])
{
    QPainter painter(this);
    if(!curFrame.empty())
    {
        cv::cvtColor(curFrame, curFrame, cv::COLOR_BGR2RGB);//图像格式转换
        disImage = QImage(
            (const unsigned char*)(curFrame.data),
            curFrame.cols,
            curFrame.rows,
            curFrame.cols*curFrame.channels(),
            QImage::Format_RGB888);
        disPicMap = QPixmap::fromImage(disImage).scaled(this->width(),this->height(),Qt::KeepAspectRatio);
    }
    painter.drawPixmap(0, 0,disPicMap);
    QPen pen;
    pen.setWidth(5);
    pen.setColor(QColor(255,0,0));
    painter.end();
    painter.begin(this);
    painter.setPen(pen);
    painter.drawRect(CVRectToQRect(curRect));

}

void AutoLabelVideoWindow::keyPressEvent(QKeyEvent* env)
{
    if(env->key() == Qt::Key_Right){
        shallPlaying = true;
    }

    if(env->key() == Qt::Key_Left){
        shallPlaying = false;
    }
}

AutoLabelVideoWindow::~AutoLabelVideoWindow()
{
    delete ui;
}
