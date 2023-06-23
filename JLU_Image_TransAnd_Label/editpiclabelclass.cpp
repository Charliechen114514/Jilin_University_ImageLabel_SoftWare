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
    connect(dialog,&labelQuerydialog::finishSelectingLabel,this,&editpiclabelClass::getCurPointListLabel);
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

const int* helper_getColorRGBs(QColor color){

    return QVector<int>{color.red(),color.green(),color.blue()}.constData();

}

void editpiclabelClass::getCurPointListLabel()
{
    labelList.push_back(dialog->returnFinalLabelToOutward());
    emit finishBothPointsRecordAndLabelsRecord();
}

void editpiclabelClass::printCurLabel()
{
    for(int i = 0; i < labelList.size();i++)
    {
        qDebug() << labelList[i].second <<" 标签!有下面这些点:";
        for(int j = 0; j < pointsRecord[i].size();j++)
        {
            qDebug() << pointsRecord[i][j];
        }
    }
}
