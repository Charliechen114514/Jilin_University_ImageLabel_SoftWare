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
    /* 初始化构造函数，于是需要图片路径以供这个类的初始化 */
    explicit manuallyLabel(QWidget *parent = nullptr);
    /* destructor  */
    ~manuallyLabel();

    /* 构造当前的用户描点的🖊 */
    void initUsrPen();

    /* 设置加载用户图片 */
    void setManuallyWindowPixMapLists(QList<QString> mapPicLists);

    /* 设置加载用户标签列表 */
    void setManuallyWindowLabelList(QList<LabelPair> Labellist);

    /* 加载当前标注模式的文本提示 */
    void initTabTextBox();

    /* 加载快捷键 */
    void initBasicQuickKey();

    /* 初始化标注窗口显示 */
    void initshowPicWindows();

    /* 加载链接 */
    void initBasicConnection();

    /* 拿到窗口编辑的笔宽 */
    void getEditedChangedWidth();

    /* 获取标注的图片内容 */
    void updateCursingelPictureLabelsRecord();

    /* 获取标签（可能会在标注的时候新增加了标签） */
    void updateExistedLabelList();

    /* 刷新文本显示 */
    void updateTextBrowsers();

    /* 获取标签（但是是主动添加） */
    void updateUsabelLabelsFromLabelQueryDialog();

    /* 向MainWindow返回标注数据 */
    Pair_Label_Shape returnSingelPictureLabelsRecord();

    /* 向MainWindow返回标注标签 */
    QList<LabelPair> returnUsableLabelPairListToMainWindow();

    void closeEvent(QCloseEvent*);

    void resizeEvent(QResizeEvent*);

    // 刷新笔宽
    void updatePenWidth();

    // 刷新标注方法
    void updateLabelMethod();
    // 传递标签方法
    void setSeperator(QString seperator) {this->seperator = seperator;}

signals:
    void finishWholeEditing_ReturnCurSinglePagePointsAndLabelInfo();
    void refreshMainWindowLabelList();


private slots:
    void refreshProcessBarAndTextBrowser();

    void on_changeColorBtn_clicked();

    void on_changeWidthBtn_clicked();


    void on_activeToLabel_clicked();


    void on_cancelAllAndBackToMainWindow_clicked();

    void on_manageLabelBtn_clicked();

    void on_saveAllAndExportTheImage_clicked();

    void on_backToDefPen_clicked();


    void on_toPreviousPic_clicked();

    void on_toAfterPic_clicked();

private:
    Ui::manuallyLabel               *ui;
    QString                         curViewPicPath;
    QImage                          curPixPicMap;
    QList<QString>                  groupPicPathLists;
    setPenWidthWindows*             showWindow;
    ShapePointsList                 currentPointList;
    LabelPair                       currentLabelPair;
    QList<LabelPair>                usableLabels;
    Pair_Label_Shape                singelPictureLabelsRecord;
    curPicForLabeling_MainWindow*   showPicWindows;
    bool                            isIgnoredAllAndLeave;
    labelQuerydialog*               dialog;
    QString                         seperator;
    int                             curViewIndex;
};

#endif // MANUALLYLABEL_H
