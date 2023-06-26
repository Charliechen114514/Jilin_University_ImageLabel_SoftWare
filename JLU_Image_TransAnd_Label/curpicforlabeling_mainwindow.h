#ifndef CURPICFORLABELING_MAINWINDOW_H
#define CURPICFORLABELING_MAINWINDOW_H
/* Import the essential Qt Headers*/
/*导入Qt的基本库*/
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QPoint>
#include <QColor>
#include <QFileDialog>
#include <QColorDialog>
#include <QTextStream>

/* 导入自己书写的窗口从而方便标注 */
#include <labelquerydialog.h>
#include <setpenwidthwindows.h>
/* Enumerate the usrChoice, here provides the basic*/
/* 枚举可能的情况 */
enum curPicChoosePolyPointsCount{
    CCSTDC_JLU_IMAGE_LABLE_STANDARD_RECT    =  2,
    CCSTDC_JLU_IMAGE_LABLE_ANYFOURPOLY      =  4,
    CCSTDC_JLU_IMAGE_LABLE_ANYFIVEPOLY      =  5
};

/* Enumerate the save Flags*/
/* 是否保存的标志*/
enum isSaveFlag{
    CCSTDC_JLU_IMAGE_LABLE_SAVE             = 1,
    CCSTDC_JLU_IMAGE_LABLE_UNSAVE           = 0
};

#define USR_DEF_LABEL_METHOD 5

/*Save's Action Related macros*/
// 打印标签编号的前缀
#define LABLE_TEXT_INDEX_PREFIX             QString("[labels_index]: ")
// 打印标签名的前缀
#define LABLE_TEXT_LABLENAME_PREFIX         QString("[labels_name]: ")
// 打印点集的前缀
#define LABLE_TEXT_POINTSET_SHOW_PREFIX     QString("{")
// 打印单个点的坐标前缀
#define LABLE_TEXT_POINT_SHOW_PREFIX        QString("[")
// 换行
#define LABLE_TEXT_INSERT_SLASH             QString("\n")
// 点坐标分割符
#define LABLE_TEXT_POINT_SPLIT              QString(", ")
// 打印单个点的坐标后缀
#define LABLE_TEXT_POINT_SHOW_SUFFIX        QString("]")
// 打印X坐标的前缀
#define LABLE_TEXT_POS_X_PREFIX             QString("x: ")
// 打印Y坐标的前缀
#define LABLE_TEXT_POS_Y_PREFIX             QString("y: ")
// 打印点集的后缀
#define LABLE_TEXT_POINTSET_END_SHOW        QString("}")
// 默认的保存方法
#define LABEL_SAVE_DEF_METHOD               saveForResultCurPicButLabelOnly()

// 默认跟踪线画笔颜色
#define USR_DEF_FOLLOWLINE_COLOR QColor(255,0,0)
#define USR_DEF_FOLLOWLINE_WIDTH 5
// 数字标签的偏移大小
#define LABEL_INDEX_TEXT_SHOW_OFFSET_X -10
#define LABEL_INDEX_TEXT_SHOW_OFFSET_Y -10

// 设置默认是否打开辅助标记
#define USR_DEF_LABEL_HELPER true;

typedef QList<QPoint> CurPolyPoints;
typedef unsigned int LabelIndex;
typedef QString      LabelName;
typedef QPair<LabelIndex,LabelName> LabelPair;
typedef QPair<QList<CurPolyPoints>,QList<LabelPair>> curPoints_LabelPair_Pair ;
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

    QList<LabelPair> returnThelabelsToManuallyLabel(){return labels;};
    /*初始化画笔*/
    void                                initCurUsrPenFromManuallyLabel(QPen pen);
    /*从标记窗口初始化标签列*/
    void                                initLabelListFromManuallyLabelWindow(QList<LabelPair> labelsget);
    /*初始化连接关系*/
    void                                initBasicConnection();

    /*更改画笔颜色*/
    void                                changeUsrCurPenColor();
    /*更改画笔宽度*/
    void                                changeUsrCurPenWidth();
    /*更改辅助标记笔颜色*/
    void                                changeFollowLinePenColor();
    /*更改辅助标记笔宽度*/
    void                                changeFollowLinePenWidth();
    /*更改标注点数量*/

    /*更改到标准矩形*/ /*实际上是只需要标注两个点即可*/
    void                                setcurAllowMaxPointsCountToStandardRect();
    /*更改到任意四边形*/
    void                                setcurAllowMaxPointsCountToAnyFourPolys();
    /*更改到任意五边形*/
    void                                setcurAllowMaxPointsCountToAnyFivePolys();
    /* 打开或者关闭辅助标记 */
    void                                openModeOfLabelHelper();
    void                                closeModeOfLabelHelper();
    void                                changeModeOfLabelHelperDirect();
    /*保存标签与图片*/

    /*只保存图片*/
    void                                saveForResultCurPicButPicOnly();
    /*只保存标签*/
    void                                saveForResultCurPicButLabelOnly();
    /*他妈的我全都要*/
    void                                saveForResultCurPicAll();
    /*书写标签文件方法*/
    QString                             writingMethod();
    /*ONLY IN DEBUG: 查看所有的已有标签:从当前的窗口得到的*/
    void                                qDebugTheLabelRes();
    QList<CurPolyPoints>                curPicPoly;
    /*专门存放种类标签*/
    QList<LabelPair>                    labels;

    QPoint                              curPos;
    unsigned int                        curAllowMaxPointsCount;

    /*for get the one label pointList*/
    QList<QPoint>                       tempPointsList;

    curPoints_LabelPair_Pair            finalSigCurPicInfo;


protected:
    /*重写窗体重绘事件*/
    void                                paintEvent(QPaintEvent *);
    /*重写鼠标按下事件*/
    void                                mousePressEvent(QMouseEvent *);
    /*重写窗口关闭防止没保存导致发颠的窗口提示保存*/
    void                                closeEvent(QCloseEvent* events);
    /*重写摁扭事件*/
    void                                keyPressEvent(QKeyEvent *e);
    /*重写鼠标移动事件*/
    void                                mouseMoveEvent(QMouseEvent *);
signals:
    void                                finishEditingPoints();
    void                                finishEveryThingAndReturnsTheNewLyLabelPair();
    void                                refreshLabelMethod();
private:
    Ui::curPicForLabeling_MainWindow    *ui;
    QPixmap                             pixmap;
    QPixmap                             AfterEditedPixMap;
    QPen                                usrCurPen;
    QPen                                followLinePen;
    labelQuerydialog                    *dialog;
    setPenWidthWindows                  *setPenWidwindow;
    QPoint                              mousePosRecorder; /*for focusing on*/
    float width_ratio =                 1.0f;
    float height_ratio =                1.0f;
    unsigned int                        ticks;
    bool                                isSave;
    bool                                isSaveShape;
    bool                                isLabelHelperOpen;
private slots:
    void                                reLoadLabelPairList();
    void                                pushBackToFinalSigCurPicInfo();
    void                                showSetPenEidthWindow();
    void                                removeTheLastPolyAndLabel();
};

#endif // CURPICFORLABELING_MAINWINDOW_H
