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
    void initUsrPen();
    QPen getUsrPenInfo();
    void initTabTextBox();
    QPen& getInterFaceQPen();
    QColor helper_getColorRGBs();
    void getCurPointListLabel();
    void setCurAllowMaxPointsCount(unsigned int labelMethodPointsMax){CurAllowMaxPointsCount = labelMethodPointsMax;};
    void resetPenToDef();
    unsigned int getCurAllowMaxPointsCount(){return CurAllowMaxPointsCount;};
    QPixmap                 curPixPicMap;
    QMainWindow*             showThePic;
signals:
    void finishBothPointsRecordAndLabelsRecord();
private:
    QPen                    usrPen;
    int                     CurAllowMaxPointsCount;
};

const int* helper_getColorRGBs(QColor color);

#endif // EDITPICLABELCLASS_H
