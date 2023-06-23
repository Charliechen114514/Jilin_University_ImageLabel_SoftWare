#ifndef EDITPICLABELCLASS_H
#define EDITPICLABELCLASS_H

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
class editpiclabelClass : public QLabel
{
    Q_OBJECT
public:
    explicit editpiclabelClass(QWidget *parent = nullptr);
    void initPixelMap(QString filePath);
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent *);
    void initUsrPen();
    QPen getUsrPenInfo();
    void showPoints();
    void mouseMoveEvent(QMouseEvent* e);
    QPen& getInterFaceQPen();
signals:

private:
    QList<QRect>            labelRects;
    QList<QList<QPoint>>    pointsRecord;
    QPen                    usrPen;
    QPen                    followLinePen;
    QPixmap                 curPixPicMap;
    int                     curAllowMaxPointsCount;
    int                     ticksForRect;
    MouseSignal             mouseSignal;
    QList<QPoint>           tempPointsList;
    int                     ticks;
    QPoint                  followLines;
    bool                    isPress;
    labelQuerydialog*       dialog;
};

const int* helper_getColorRGBs(QColor color);

#endif // EDITPICLABELCLASS_H
