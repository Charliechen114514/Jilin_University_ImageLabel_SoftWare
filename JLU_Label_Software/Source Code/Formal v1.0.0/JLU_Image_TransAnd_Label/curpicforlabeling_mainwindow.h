<<<<<<< HEAD
#ifndef CURPICFORLABELING_MAINWINDOW_H
#define CURPICFORLABELING_MAINWINDOW_H
/* Import the essential Qt Headers*/
/*导入Qt的基本库*/
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPainter>
#include <QPoint>
#include <QColor>
#include <QFileDialog>
#include <QColorDialog>
#include <QTextStream>

/* 导入自己书写的窗口从而方便标注 */
#include <labelquerydialog.h>
#include <setpenwidthwindows.h>
#include <setorshiftcurmaxpointcountswindows.h>
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
#define USR_DEF_FOLLOWLINE_COLOR            QColor(255,0,0)
#define USR_DEF_FOLLOWLINE_WIDTH            5

// 数字标签的偏移大小
#define LABEL_INDEX_TEXT_SHOW_OFFSET_X      -10
#define LABEL_INDEX_TEXT_SHOW_OFFSET_Y      -10

// 设置默认是否打开辅助标记
#define USR_DEF_LABEL_HELPER true;

// 辅助线笔宽极限
#define FOLLOWLINEPEN_WIDTH_MIN 1
#define FOLLOWLINEPEN_WIDTH_MAX 15

typedef QList<QPoint>                       CurPolyPoints;  // 当前轮廓的点
typedef unsigned int                        LabelIndex;     // 标签下表
typedef QString                             LabelName;      // 标签名称
typedef QPair<LabelIndex,LabelName>         LabelPair;      // 标签对
typedef QPair<QList<CurPolyPoints>,QList<LabelPair>> curPoints_LabelPair_Pair ; // 当前图片下所有的标签轮廓 + 种类链表
namespace Ui {
class curPicForLabeling_MainWindow;
}

class curPicForLabeling_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit curPicForLabeling_MainWindow(QWidget *parent = nullptr);

    ~curPicForLabeling_MainWindow();

    /* 初始化图片链接标签 */
    void                                initPicturesListWithPicsPath(QList<QString> picPathList);
    /* 初始化画笔 */
    void                                initCurUsrPenFromManuallyLabel(QPen pen);
    /* 从标记窗口初始化标签列 */
    void                                initLabelListFromManuallyLabelWindow(QList<LabelPair> labelsget);
    /* 初始化连接关系 */
    void                                initBasicConnection();
    void                                initCurMaxPointCount();
    /* 更改画笔颜色 */
    void                                changeUsrCurPenColor();
    /* 更改画笔宽度 */
    void                                changeUsrCurPenWidth();
    /* 更改辅助标记笔颜色 */
    void                                changeFollowLinePenColor();
    /* 更改辅助标记笔宽度 */
    void                                changeFollowLinePenWidth();
    /* 设置分割符 */
    void                                setSeperator(QString seperator){this->seperator = seperator;};
    /* 更改标注点数量 */
    /* 打开或者关闭辅助标记 */
    void                                openModeOfLabelHelper();
    void                                closeModeOfLabelHelper();
    void                                changeModeOfLabelHelperDirect();

    /*切换图片*/
    void                                moveToAfterPic();
    /*保存标签与图片*/
    /*只保存图片*/
    void                                saveForResultCurPicButPicOnly();
    /*只保存标签*/
    void                                saveForResultCurPicButLabelOnly();
    /*他妈的我全都要*/
    void                                saveForResultCurPicAll();
    /*设置固定标签保存路径*/
    void                                setAlwaysSaveOnFixedPathForLabels();
    /*设置固定图像保存路径*/
    void                                setAlwaysSaveOnFixedPathForPics();
    /*设置固定标注方法*/
    void                                setAlwaysLabelInFixedMethod();
    /*改写固定标签路径*/
    void                                shiftAlwaysSaveOnFixedPathForLabels();
    /*改写固定图像路径*/
    void                                shiftAlwaysSaveOnFixedPathForPics();
    /*改写固定标注方法*/
    void                                shiftAlwaysLabelInFixedMethod();
    /*取消固定标签路径*/
    void                                cancelTheAlwaysSaveOnFixedPathForLabels(){isAlwaysSaveConstPlaceForLabels = false;}
    /*取消固定图片路径*/
    void                                cancelTheAlwaysSaveOnFixedPathForPics(){isAlwaysSaveConstPlaceForPics = false;}
    /*取消固定标注方法*/
    void                                cancelAlwaysLabelInFixedMethod(){isAlwaysSuchMethodOfLabeling = false;}
    /*书写标签文件方法*/
    QString                             writingMethod();

    /*public getter*/
    curPoints_LabelPair_Pair            returnLabelResToManuallyLabel(){return finalSigCurPicInfo;}

    QList<LabelPair>                    returnThelabelsToManuallyLabel(){return labels;};
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
    /* 重写滚轮事件 */
    void                                wheelEvent(QWheelEvent* env);
signals:
    /*信号1：完成编辑点*/
    void                                finishEditingPoints();
    /*向手动编辑的主窗口返回标签*/
    void                                finishEveryThingAndReturnsTheNewLyLabelPair();
    /* 刷新标签 */
    void                                refreshLabelMethod();
private:
    Ui::curPicForLabeling_MainWindow    *ui;
    /* 总是设置固定的保存数据路径 */
    QString                             AlwaysLabelSavePath;
    /* 总是设置固定的保存图像路径 */
    QString                             AlwaysPictureSavePath;
    /* 图像本像 */
    QPixmap                             pixmap;
    /* 每当用户完成单次编辑就刷新它 */
    QPixmap                             AfterEditedPixMap;

    QList<QString>                      WholeGroupPicsPathList;
    /* 轮廓线笔 */
    QPen                                usrCurPen;
    /* 辅助线笔 */
    QPen                                followLinePen;
    labelQuerydialog                    *dialog;
    setPenWidthWindows                  *setPenWidwindow;
    setOrShiftCurMaxPointCountsWindows  *setCurMaxPointCountWindows;
    QString                             seperator;
    QPoint                              mousePosRecorder; /*for focusing on*/
    float width_ratio =                 1.0f;
    float height_ratio =                1.0f;
    unsigned int                        ticks;
    int                                 curViewIndex;
    /* 保存了嘛？劳保 */
    bool                                isSave;
    /* 设置固定保存路径了嘛-图片 */
    bool                                isAlwaysSaveConstPlaceForPics;
    /* 设置固定保存路径了嘛-标签 */
    bool                                isAlwaysSaveConstPlaceForLabels;
    /* 设置是不是总是一个固定方法进行标注 */
    bool                                isAlwaysSuchMethodOfLabeling;
    /* 有没有设置标注方法 */
    bool                                isSaveShape;
    /* 开没开标注线 */
    bool                                isLabelHelperOpen;
    /* 开没开自动保存 */
    bool                                isAlreadyAutoDefSave;
private slots:
    /* 将标签重新加回到 */
    void                                reLoadLabelPairList();
    /* 添加结果 */
    void                                pushBackToFinalSigCurPicInfo();
    /* 显示设置笔宽的窗口 */
    void                                showSetPenEidthWindow();
    /* 撤销上一个轮廓 */
    void                                removeTheLastPolyAndLabel();
    /* 撤销上一个点 */
    void                                removeTheLastSinglePoints();
};

#endif // CURPICFORLABELING_MAINWINDOW_H
=======
#ifndef CURPICFORLABELING_MAINWINDOW_H
#define CURPICFORLABELING_MAINWINDOW_H
/* Import the essential Qt Headers*/
/*导入Qt的基本库*/
#include <QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QPainter>
#include <QPoint>
#include <QColor>
#include <QFileDialog>
#include <QColorDialog>
#include <QTextStream>

/* 导入自己书写的窗口从而方便标注 */
#include <labelquerydialog.h>
#include <setpenwidthwindows.h>
#include <setorshiftcurmaxpointcountswindows.h>
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
#define USR_DEF_FOLLOWLINE_COLOR            QColor(255,0,0)
#define USR_DEF_FOLLOWLINE_WIDTH            5

// 数字标签的偏移大小
#define LABEL_INDEX_TEXT_SHOW_OFFSET_X      -10
#define LABEL_INDEX_TEXT_SHOW_OFFSET_Y      -10

// 设置默认是否打开辅助标记
#define USR_DEF_LABEL_HELPER true;

// 辅助线笔宽极限
#define FOLLOWLINEPEN_WIDTH_MIN 1
#define FOLLOWLINEPEN_WIDTH_MAX 15

typedef QList<QPoint>                       CurPolyPoints;  // 当前轮廓的点
typedef unsigned int                        LabelIndex;     // 标签下表
typedef QString                             LabelName;      // 标签名称
typedef QPair<LabelIndex,LabelName>         LabelPair;      // 标签对
typedef QPair<QList<CurPolyPoints>,QList<LabelPair>> curPoints_LabelPair_Pair ; // 当前图片下所有的标签轮廓 + 种类链表
namespace Ui {
class curPicForLabeling_MainWindow;
}

class curPicForLabeling_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit curPicForLabeling_MainWindow(QWidget *parent = nullptr);

    ~curPicForLabeling_MainWindow();

    /* 初始化图片链接标签 */
    void                                initPicturesListWithPicsPath(QList<QString> picPathList);
    /* 初始化画笔 */
    void                                initCurUsrPenFromManuallyLabel(QPen pen);
    /* 从标记窗口初始化标签列 */
    void                                initLabelListFromManuallyLabelWindow(QList<LabelPair> labelsget);
    /* 初始化连接关系 */
    void                                initBasicConnection();
    void                                initCurMaxPointCount();
    /* 更改画笔颜色 */
    void                                changeUsrCurPenColor();
    /* 更改画笔宽度 */
    void                                changeUsrCurPenWidth();
    /* 更改辅助标记笔颜色 */
    void                                changeFollowLinePenColor();
    /* 更改辅助标记笔宽度 */
    void                                changeFollowLinePenWidth();
    /* 设置分割符 */
    void                                setSeperator(QString seperator){this->seperator = seperator;};
    /* 更改标注点数量 */
    /* 打开或者关闭辅助标记 */
    void                                openModeOfLabelHelper();
    void                                closeModeOfLabelHelper();
    void                                changeModeOfLabelHelperDirect();

    /*切换图片*/
    void                                moveToAfterPic();
    /*保存标签与图片*/
    /*只保存图片*/
    void                                saveForResultCurPicButPicOnly();
    /*只保存标签*/
    void                                saveForResultCurPicButLabelOnly();
    /*他妈的我全都要*/
    void                                saveForResultCurPicAll();
    /*设置固定标签保存路径*/
    void                                setAlwaysSaveOnFixedPathForLabels();
    /*设置固定图像保存路径*/
    void                                setAlwaysSaveOnFixedPathForPics();
    /*设置固定标注方法*/
    void                                setAlwaysLabelInFixedMethod();
    /*改写固定标签路径*/
    void                                shiftAlwaysSaveOnFixedPathForLabels();
    /*改写固定图像路径*/
    void                                shiftAlwaysSaveOnFixedPathForPics();
    /*改写固定标注方法*/
    void                                shiftAlwaysLabelInFixedMethod();
    /*取消固定标签路径*/
    void                                cancelTheAlwaysSaveOnFixedPathForLabels(){isAlwaysSaveConstPlaceForLabels = false;}
    /*取消固定图片路径*/
    void                                cancelTheAlwaysSaveOnFixedPathForPics(){isAlwaysSaveConstPlaceForPics = false;}
    /*取消固定标注方法*/
    void                                cancelAlwaysLabelInFixedMethod(){isAlwaysSuchMethodOfLabeling = false;}
    /*书写标签文件方法*/
    QString                             writingMethod();

    /*public getter*/
    curPoints_LabelPair_Pair            returnLabelResToManuallyLabel(){return finalSigCurPicInfo;}

    QList<LabelPair>                    returnThelabelsToManuallyLabel(){return labels;};
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
    /* 重写滚轮事件 */
    void                                wheelEvent(QWheelEvent* env);
signals:
    /*信号1：完成编辑点*/
    void                                finishEditingPoints();
    /*向手动编辑的主窗口返回标签*/
    void                                finishEveryThingAndReturnsTheNewLyLabelPair();
    /* 刷新标签 */
    void                                refreshLabelMethod();
private:
    Ui::curPicForLabeling_MainWindow    *ui;
    /* 总是设置固定的保存数据路径 */
    QString                             AlwaysLabelSavePath;
    /* 总是设置固定的保存图像路径 */
    QString                             AlwaysPictureSavePath;
    /* 图像本像 */
    QPixmap                             pixmap;
    /* 每当用户完成单次编辑就刷新它 */
    QPixmap                             AfterEditedPixMap;

    QList<QString>                      WholeGroupPicsPathList;
    /* 轮廓线笔 */
    QPen                                usrCurPen;
    /* 辅助线笔 */
    QPen                                followLinePen;
    labelQuerydialog                    *dialog;
    setPenWidthWindows                  *setPenWidwindow;
    setOrShiftCurMaxPointCountsWindows  *setCurMaxPointCountWindows;
    QString                             seperator;
    QPoint                              mousePosRecorder; /*for focusing on*/
    float width_ratio =                 1.0f;
    float height_ratio =                1.0f;
    unsigned int                        ticks;
    int                                 curViewIndex;
    /* 保存了嘛？劳保 */
    bool                                isSave;
    /* 设置固定保存路径了嘛-图片 */
    bool                                isAlwaysSaveConstPlaceForPics;
    /* 设置固定保存路径了嘛-标签 */
    bool                                isAlwaysSaveConstPlaceForLabels;
    /* 设置是不是总是一个固定方法进行标注 */
    bool                                isAlwaysSuchMethodOfLabeling;
    /* 有没有设置标注方法 */
    bool                                isSaveShape;
    /* 开没开标注线 */
    bool                                isLabelHelperOpen;
    /* 开没开自动保存 */
    bool                                isAlreadyAutoDefSave;
private slots:
    /* 将标签重新加回到 */
    void                                reLoadLabelPairList();
    /* 添加结果 */
    void                                pushBackToFinalSigCurPicInfo();
    /* 显示设置笔宽的窗口 */
    void                                showSetPenEidthWindow();
    /* 撤销上一个轮廓 */
    void                                removeTheLastPolyAndLabel();
    /* 撤销上一个点 */
    void                                removeTheLastSinglePoints();
};

#endif // CURPICFORLABELING_MAINWINDOW_H
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
