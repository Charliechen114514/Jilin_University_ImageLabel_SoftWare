#include "editpiclabelclass.h"
#define USR_DEF_PEN_COLOR QColor(0,0,255)
#define USR_DEF_PEN_WIDTH 7
#define USR_DEF_POLY_NUMS 5
#define USR_DEF_METHOD 2
editpiclabelClass::editpiclabelClass(QWidget *parent)
    : QLabel{parent}
{
    initUsrPen();
}


void editpiclabelClass::initPixelMap(QString path)
{
    curPixPicMap = QPixmap(path);
}

void editpiclabelClass::resetPenToDef()
{
    usrPen.setColor(USR_DEF_PEN_COLOR);
    usrPen.setWidth(USR_DEF_PEN_WIDTH);
}


void editpiclabelClass::initUsrPen(){
    usrPen.setColor(USR_DEF_PEN_COLOR);
    usrPen.setWidth(USR_DEF_PEN_WIDTH);
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

