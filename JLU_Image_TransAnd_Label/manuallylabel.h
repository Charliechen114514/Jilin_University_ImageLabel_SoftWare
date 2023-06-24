#ifndef MANUALLYLABEL_H
#define MANUALLYLABEL_H
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>
#include <QPoint>
#include <QAction>
#include <QColor>
#include<QColorDialog>
#include <setpenwidthwindows.h>
#include <labelquerydialog.h>
#include <QFileDialog>
#define DEF_PEN_COLOR QColor(255,0,0)
#define DEF_PEN_CURDRAW_COLOR QColor(255,0,0)
#define DEF_PRN_WIDTH 3
#define USR_DEF_LABLE_COUNT_TEXT "当前有标签 0 种"
#include <curpicforlabeling_mainwindow.h>


typedef unsigned int SAVESIG;
typedef unsigned int LabelIndex;
typedef QString      LabelName;
typedef QPair<LabelIndex,LabelName> LabelPair;
typedef QList<QPoint> ShapePointsList;
typedef QPair<QList<QList<QPoint>>,QList<LabelPair>> Pair_Label_Shape;

namespace Ui {
class manuallyLabel;
}

class manuallyLabel : public QMainWindow
{
    Q_OBJECT

public:
    /*初始化构造函数，于是需要图片路径以供这个类的初始化*/
    explicit manuallyLabel(QString curViewPath,QWidget *parent = nullptr);

    /*构造当前的用户描点的🖊*/
    void initUsrPen();

    void setManuallyWindowLabelList(QList<LabelPair> Labellist);
    /**/
    void initTabTextBox();

    void initshowPicWindows();

    void getEditedChangedWidth();

    void getPixmapPath(QString path);

    ~manuallyLabel();

    void updateCursingelPictureLabelsRecord();

    void updateExistedLabelList();

    void updateTextBrowsers();

    Pair_Label_Shape returnSingelPictureLabelsRecord();

    QList<LabelPair> returnUsableLabelPairListToMainWindow();

    void closeEvent(QCloseEvent*);

signals:
    void finishWholeEditing_ReturnCurSinglePagePointsAndLabelInfo();
    void refreshMainWindowLabelList();


private slots:
    void on_changeColorBtn_clicked();

    void on_changeWidthBtn_clicked();


    void on_activeToLabel_clicked();


    void on_cancelAllAndBackToMainWindow_clicked();

private:
    Ui::manuallyLabel *ui;
    QString curViewPicPath;
    QPixmap curPixPicMap;
    setPenWidthWindows* showWindow;
    ShapePointsList currentPointList;
    LabelPair currentLabelPair;
    QList<LabelPair> usableLabels;
    Pair_Label_Shape singelPictureLabelsRecord;
    curPicForLabeling_MainWindow* showPicWindows;
    bool isIgnoredAllAndLeave;
};

#endif // MANUALLYLABEL_H
