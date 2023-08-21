#ifndef EDITPICLABELCLASS_H
#define EDITPICLABELCLASS_H
#include<QMainwindow>
#include <QLabel>
#include<QImage>
#include<QPixmap>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QAction>
#include <QColor>
#include <labelquerydialog.h>
/* from author: 这个类先前是编辑图片和标注的，但是因为计算问题和图片失真导致可能会产生标注不准确的问题，这个类实际上可以被替代为
* 一个普通的图片展示类，但是有小丑（就是我）不愿意去除屎山
* */

class editpiclabelClass : public QLabel
{
    Q_OBJECT
public:
    explicit        editpiclabelClass(QWidget *parent = nullptr);
    /* 初始化 */
    void            initUsrPen();
    QPen            getUsrPenInfo();
    QPen&           getInterFaceQPen();
    void            setCurAllowMaxPointsCount(unsigned int labelMethodPointsMax)    {CurAllowMaxPointsCount = labelMethodPointsMax;};
    void            resetPenToDef();
    unsigned int    getCurAllowMaxPointsCount()                                     {return CurAllowMaxPointsCount;};
    QPixmap         curPixPicMap;
    QMainWindow*    showThePic;
signals:
    void            finishBothPointsRecordAndLabelsRecord();
private:
    QPen            usrPen;
    int             CurAllowMaxPointsCount;
};


#endif // EDITPICLABELCLASS_H
