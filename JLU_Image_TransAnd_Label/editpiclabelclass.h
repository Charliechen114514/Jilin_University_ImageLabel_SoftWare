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
typedef unsigned int MouseSignal;
typedef unsigned int LabelIndex;
typedef QString      LabelName;
typedef QPair<LabelIndex,LabelName> LabelPair;
typedef QList<QPoint> ShapePointsList;
typedef QPair<QList<ShapePointsList>,QList<LabelPair>> Pair_Label_Shape;

class editpiclabelClass : public QLabel
{
    Q_OBJECT
public:
    explicit editpiclabelClass(QWidget *parent = nullptr);
    void initPixelMap(QString filePath);
    void initUsrPen();
    QPen getUsrPenInfo();
    void initTabTextBox();
    QPen& getInterFaceQPen();
    unsigned int getCurAllowMaxPointsCount(){return curAllowMaxPointsCount;}
    QColor helper_getColorRGBs();
    void getCurPointListLabel();
    Pair_Label_Shape returnBackToManuallyWindow(){return Pair_Label_Shape(pointsRecord,labelList);}
    QPixmap getAfterEditedPixMap(){return curPixPicMap;}
    QPixmap                 curPixPicMap;
    QMainWindow*             showThePic;
    //debug
    void printCurLabel();
signals:
    void finishBothPointsRecordAndLabelsRecord();
private:
    QList<QRect>            labelRects;
    QList<QList<QPoint>>    pointsRecord;
    QPen                    usrPen;
    QPen                    followLinePen;
    int                     curAllowMaxPointsCount;
    int                     ticksForRect;
    MouseSignal             mouseSignal;
    QList<QPoint>           tempPointsList;
    QList<LabelPair>        labelList;
    int                     ticks;
    QPoint                  followLines;
    bool                    isPress;
    labelQuerydialog*       dialog;
};

const int* helper_getColorRGBs(QColor color);

#endif // EDITPICLABELCLASS_H
