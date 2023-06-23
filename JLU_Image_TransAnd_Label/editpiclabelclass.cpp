#include "editpiclabelclass.h"
#define USR_DEF_PEN_COLOR QColor(0,0,255)
#define USR_DEF_FOL_COLOR QColor(255,0,0)
#define USR_DEF_PEN_WIDTH 7
#define USR_DEF_FOL_WIDTH 7
#define USR_DEF_POLY_NUMS 5

editpiclabelClass::editpiclabelClass(QWidget *parent)
    : QLabel{parent}
{
    ticksForRect = 0;
    ticks = 0;
    mouseSignal  = false;
    curAllowMaxPointsCount = USR_DEF_POLY_NUMS;
    tempPointsList.clear();
    initUsrPen();

    dialog = new labelQuerydialog;
}


void editpiclabelClass::initPixelMap(QString path)
{
    curPixPicMap = QPixmap(path);
}

void editpiclabelClass::initUsrPen(){
    usrPen.setColor(USR_DEF_PEN_COLOR);
    usrPen.setWidth(USR_DEF_PEN_WIDTH);
    followLinePen.setColor(USR_DEF_FOL_COLOR);
    followLinePen.setWidth(USR_DEF_FOL_WIDTH);
}

QPen editpiclabelClass::getUsrPenInfo()
{
    return QPen(usrPen);
}

QPen& editpiclabelClass::getInterFaceQPen()
{
    return usrPen;
}

void editpiclabelClass::mousePressEvent(QMouseEvent* e){

    if(e->button() == Qt::LeftButton){
        qDebug() << " 左键摁下";

        switch(curAllowMaxPointsCount)
        {
            case 4:
            {

                ticksForRect ++;
                if(ticksForRect == 1)
                {
                    qDebug() << "第一位置点已找好";
                    qDebug() << e->pos();
                    tempPointsList.push_back(e->pos());
                }
                else
                {
                    qDebug() << "第二位置点已找好";
                    qDebug() << e->pos();
                    ticksForRect = 0;
                    tempPointsList.push_back(e->pos());
                    QRect curRect;
                    curRect.setTopLeft(tempPointsList.first());
                    curRect.setBottomRight(tempPointsList.last());
                    labelRects.push_back(curRect);
                    pointsRecord.push_back(tempPointsList);
                    qDebug() <<  tempPointsList.first() << tempPointsList.last();
                    tempPointsList.clear();
                    dialog->show();
                    update();
                }
            }break;

            case 5:
            {
                if(ticks < 4)
                {
                    qDebug() << "第"<< ticks <<"位置点已找好";
                    qDebug() << e->pos();
                    ticks ++;
                    tempPointsList.push_back(e->pos());
                }
                else
                {
                    qDebug() << "第"<< ticks <<"位置点已找好";
                    qDebug() << e->pos();
                    ticks = 0;
                    tempPointsList.push_back(e->pos());
                    QList<QPoint> copyList(tempPointsList);
                    pointsRecord.push_back(copyList);
                    tempPointsList.clear();
                    dialog->show();
                    update();
                }
            }break;
        }
    }

}

void editpiclabelClass::mouseMoveEvent(QMouseEvent* e)
{
    setMouseTracking(true);
    followLines = e->pos();
    qDebug() << followLines;
    update();
}


void editpiclabelClass::paintEvent(QPaintEvent* e)
{

    QLabel::paintEvent(e);
    QPainter painter(this);
    painter.setPen(usrPen);

    switch(curAllowMaxPointsCount){
    case 4:
    {
        for(int i = 0; i < labelRects.size(); i++){
            painter.drawRect(labelRects[i]);
        }

        update();
    }break;

    case 5:
    {
        qDebug() << pointsRecord.size();
        for(int i = 0; i < pointsRecord.size();i++)
        {
            qDebug() << pointsRecord[i].size();
            for(int j = 0; j < pointsRecord[i].size()-1;j++)
            {
                qDebug() << pointsRecord[i][j] << " and "<<pointsRecord[i][j + 1];
                painter.drawLine(pointsRecord[i][j],pointsRecord[i][j + 1]);
            }
            painter.drawLine(pointsRecord[i][pointsRecord[i].size()-1],pointsRecord[i][0]);
        }
    }
    default:
        break;
    }

    painter.setPen(followLinePen);
    painter.drawLine(0, followLines.y(), width(), followLines.y());
    painter.drawLine(followLines.x(), 45, followLines.x(), height());
    painter.end();
}

void editpiclabelClass::showPoints()
{
    for(int i = 0; i < pointsRecord.size();i++)
    {
        qDebug()<<"第" <<i << "个链表里有"<<pointsRecord[i].size() << "个点";
        for(int j = 0; j < pointsRecord[i].size();j++)
        {
            qDebug() << pointsRecord[i][j];
        }
    }
}

const int* helper_getColorRGBs(QColor color){

    return QVector<int>{color.red(),color.green(),color.blue()}.constData();

}

