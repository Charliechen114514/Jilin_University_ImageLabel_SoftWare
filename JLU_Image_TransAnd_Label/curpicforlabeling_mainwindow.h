#ifndef CURPICFORLABELING_MAINWINDOW_H
#define CURPICFORLABELING_MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QAction>
#include <QColor>
#include <QMenu>
#include <QFileDialog>
#include <QTextStream>

#include <labelquerydialog.h>

#define LABLE_TEXT_INDEX_PREFIX QString("[labels_index]: ")
#define LABLE_TEXT_LABLENAME_PREFIX QString("[labels_name]: ")
#define LABLE_TEXT_POINTSET_SHOW_PREFIX QString("{")
#define LABLE_TEXT_POINT_SHOW_PREFIX QString("[")
#define LABLE_TEXT_INSERT_SLASH QString("\n")
#define LABLE_TEXT_POINT_SPLIT QString(", ")
#define LABLE_TEXT_POINT_SHOW_SUFFIX QString("]")
#define LABLE_TEXT_POS_X_PREFIX QString("x: ")
#define LABLE_TEXT_POS_Y_PREFIX QString("y: ")
#define LABLE_TEXT_POINTSET_END_SHOW QString("}")

typedef QList<QPoint> CurPolyPoints;
typedef unsigned int LabelIndex;
typedef QString      LabelName;
typedef QPair<LabelIndex,LabelName> LabelPair;

namespace Ui {
class curPicForLabeling_MainWindow;
}

class curPicForLabeling_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit curPicForLabeling_MainWindow(QWidget *parent = nullptr);
    void getPictures(QString picPath);
    ~curPicForLabeling_MainWindow();

   QPair<QList<CurPolyPoints>,QList<LabelPair>> returnLabelResToManuallyLabel(){return finalSigCurPicInfo;}


    QList<CurPolyPoints> curPicPoly;
    QList<LabelPair> labels;
    QPoint curPos;
    unsigned int curAllowMaxPointsCount;
    /*for get the one label pointList*/
    QList<QPoint> tempPointsList;
    QPair<QList<QList<QPoint>>,QList<LabelPair>> finalSigCurPicInfo;

    /*保存标签与图片*/

    /*只保存图片*/
    void saveForResultCurPicButPicOnly();
    /*只保存标签*/
    void saveForResultCurPicButLabelOnly();
    /*他妈的我全都要*/
    void saveForResultCurPicAll();

protected:
    void paintEvent(QPaintEvent *);//重写窗体重绘事件
    void mousePressEvent(QMouseEvent *);//重写鼠标按下事件
signals:
    void finishEditingPoints();

private:
    Ui::curPicForLabeling_MainWindow *ui;
    int ispress = 0; //左键按下标志
    int isopen = 0; //打开图片标志
    QPixmap pixmap;
    labelQuerydialog *dialog;
    QString picsPath;
    QStringList imagesList;
    float width_ratio = 1.0f;
    float height_ratio = 1.0f;
    int num = 0;
    int ticks;
private slots:
    void reLoadLabelPairList();
    void pushBackToFinalSigCurPicInfo();
};

#endif // CURPICFORLABELING_MAINWINDOW_H
