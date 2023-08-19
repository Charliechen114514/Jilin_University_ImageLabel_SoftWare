#ifndef AUTOLABELWINDOW_H
#define AUTOLABELWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QFile>
#include <QMessageBox>
#include <QPainter>
#include <QPaintEvent>
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>
#include "opencv_Qt_TransFormInterface.h"
typedef unsigned int LabelIndex;
typedef QString      LabelName;
typedef QPair<LabelIndex,LabelName> LabelPair; /* 编号 - 标签名对 */

namespace Ui {
class AutoLabelWindow;
}

struct SinglePicData
{
    double m_cx;
    double m_cy;
    double m_x;
    double m_y;
    LabelIndex labelIndex;
    double picSizeX;
    double picSizeY;
    SinglePicData(double cx, double cy, double x, double y, LabelIndex index):
        m_cx{cx},m_cy{cy},m_x{x},m_y{y},labelIndex{index}{};
    SinglePicData(QRect rect,LabelIndex labelIndex, unsigned int picSizeX,unsigned int picSizeY);
};


class AutoLabelWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AutoLabelWindow(QWidget *parent = nullptr);
    // setter
    void setLabelLists(QList<LabelPair> List){labelList = List;}
    void setPicturePaths(QStringList pics){picPathLists = pics;showPicOnWnd();}
    void setResSavePath(QString path){savePath = path;}
    // 显示图片
    void showPicOnWnd();
    void pushBackToDataLists();
    void saveToPlace();
    QString writingMethod();
    void mouseMoveEvent(QMouseEvent* env);
    void keyPressEvent(QKeyEvent* env);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent* env);
    void closeEvent(QCloseEvent* env);
    ~AutoLabelWindow();

private:
    Ui::AutoLabelWindow     *ui;
    QList<LabelPair>        labelList;
    QList<QPoint>           tmp_ROIPoint;
    QStringList             picPathLists;
    QString                 savePath;
    int                     curViewIndex; // same as the array group
    QPixmap                 curPic;
    cv::Rect                curRect;
    int                     ticks;
    // auto work
    void                    autoWork();
    void                    setROIRect();
    void                    updateRectByTracker();
    cv::Ptr<cv::Tracker>    tracker;
    bool                    isROISet;
    bool                    isROIRefreshed;
    QList<SinglePicData>    dataList;
};







#endif // AUTOLABELWINDOW_H
