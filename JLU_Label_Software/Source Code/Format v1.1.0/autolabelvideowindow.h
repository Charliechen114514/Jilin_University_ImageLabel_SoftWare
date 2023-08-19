#ifndef AUTOLABELVIDEOWINDOW_H
#define AUTOLABELVIDEOWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>
#include <opencv2/core/utility.hpp>
#include <opencv2/tracking.hpp>
#include <QPainter>
#include <QPaintEvent>
#include <QKeyEvent>
#include <QMouseEvent>
#include "opencv_Qt_TransFormInterface.h"
namespace Ui {
class AutoLabelVideoWindow;
}

class AutoLabelVideoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit                    AutoLabelVideoWindow(QWidget *parent = nullptr);
    void                        showVideoOnWnd();
    void                        updateTracker();
    void                        paintEvent(QPaintEvent* env);
    void        keyPressEvent(QKeyEvent* env);
    void                        mousePressEvent(QMouseEvent* env);
    ~AutoLabelVideoWindow();
    void                        initVideo(QString videoAddr)
                            {videoHandle = new cv::VideoCapture(0/*videoAddr.toStdString().c_str()*/);*videoHandle >> curFrame;}
    void                        setROIRect();
    void                        autoWork();
private:
    Ui::AutoLabelVideoWindow *ui;
    void                        initBasicConnection();
    QTimer*                     spliter;
    QTimer*                     displayer;
    cv::VideoCapture*           videoHandle;
    QImage                      disImage;
    QPixmap                     disPicMap;
    bool                        isSelectedTrack;
    bool                        isROISet;
    bool                        isROIRefreshed;
    bool                        isFinishPlaying;
    bool                        shallPlaying;
    int                         ticks;
    QList<QPoint>               tmp_ROIRect;
    cv::Rect                    curRect;
    cv::Ptr<cv::Tracker>        tracker;
    cv::Mat                     curFrame;
};

#endif // AUTOLABELVIDEOWINDOW_H
