#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include<QDir>
#include <QMainWindow>
#include<QMessageBox>
#include<QDebug>
#include<QList>
#include<opencv2/opencv.hpp>

#include <labelclass.h>
#include <manuallylabel.h>
#include <labelquerydialog.h>
#include "helpandcheck.h"
#include <setseperatormainwindow.h>
QT_BEGIN_NAMESPACE

using namespace cv;
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define USR_CANCEL_DFT_REACT return
#define USR_INVALID_DFT_REACT return
#define DEBUG_PIC_PATH "."
#define ALLOWING_PICDIR_TYPE QString("*.jpg;*.png;*.bmp").split(";")
#define ALLOWING_PICSIG_TYPE "PNG 图片(*.png);;JPG 图片(*.jpg);;BMP图片(*.bmp)"
#define EMPTY_SHOWN_PNG "./def_png.png"

/*type reDefine the current type and get the type LabelPair*/
typedef unsigned int LabelIndex;
typedef QString      LabelName;
typedef QPair<LabelIndex,LabelName> LabelPair;
typedef QList<QPoint> ShapePointsList;
typedef QPair<QList<ShapePointsList>,QList<LabelPair>> Pair_Label_Shape;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*加载窗口*/
    void initMainWindow();
    /*加载默认图片*/
    void initDefaultPictures();
    /*加载快捷件*/
    void initBasicQuickShot();
    /*显示图片*/
    void imgShow(unsigned int visitIndex);

    /*MenuBar Sections*/
    /*Import the picture*/
    /*导入单张图片*/
    void getPictureFromUsr();

    /*Import the Directory Functions*/
    /*通过文件夹的方式导入图片*/
    void getDirectoryFromUsr();

    bool dealFailedInput();

    /*ProcessBar Check and set*/
    /*进度条的刷新*/
    void refreshProcessBar(int curViewIndex);
    /*删除所有的图片并且置空*/
    void removeAllPictures();
    /*替换文件夹*/
    void switchPicDir();
    /*从手动编辑界面种获取当前编辑图像的信息*/
    void fetchFromManuallyLabel();
    /*凑够手动编辑处刷新labelList供下一次使用*/
    void fetchLabelListFromManuallyLabel();

    /*更新标签链表*/
    void updateLabelListForMainWindow();

    /*更新标签文本控件*/
    void updateCurrentLabelCheckText();
    /*看看是谁做了这个工具*/
    void viewWhoMakeIt();
    /*我去，危*/
    void findShitsAndTellAuthors();
private slots:


    /*移动到前一个的控件*/
    void on_gotoAfterOne_clicked();

    /*移动到后一个的控件*/
    void on_gotoPrevious_clicked();

    /*切换到编辑模式的控件*/
    void on_changeToManuallyLable_clicked();

    /*删除单张当前图片 - 按钮*/
    void on_removeCurPictureBtn_clicked();

    void resizeEvent(QResizeEvent*);

    /*RNM，退图片！-按钮*/
    void on_changeCurPicBtn_clicked();

    /*添加新标签的窗口*/
    void on_manageLabelButton_clicked();

    void importLabelsFromUsr();

    void showSetSeperatorMainWindow();

    void getSetSeperatorFromSSMW();
private:
    Ui::MainWindow                                  *ui;
    QImage                                          curViewPic;
    QList<QString>                                  pathPics;
    unsigned int                                    curViewPicIndex;
    QImage                                          def_png;
    QList<LabelPair>                                labelList;
    QList<Pair_Label_Shape>                         wholeCoreData;/*have Existed Data*/
    labelQuerydialog*                               getNewLabelDialog;
    manuallyLabel*                                  editPicWindow;
    helpAndCheck*                                   helpWindows;
    SetSeperatorMainWindow*                         setSeperatorWindows;
    bool                                            isIgnoreFailed;
    QString                                         defLabelsSeperator;
    QString                                         curLabelsSeperator;
    QStringList                                     writingMethod;
};
#endif // MAINWINDOW_H

