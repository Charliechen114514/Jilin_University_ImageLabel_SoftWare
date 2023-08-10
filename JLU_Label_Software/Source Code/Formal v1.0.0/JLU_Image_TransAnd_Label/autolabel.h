#ifndef AUTOLABEL_H
#define AUTOLABEL_H

#include <QMainWindow>
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
class autolabel;
}

class autolabel : public QMainWindow
{
    Q_OBJECT

public:
    explicit autolabel(QWidget *parent = nullptr);
    ~autolabel();
    // 传递标签方法
    void setSeperator(QString seperator);
    QList<LabelPair> returnUsableLabelPairListToMainWindow();
signals:
    void refreshMainWindowLabelList();
private:
    Ui::autolabel                   *ui;
    QString                         seperator;
    QList<LabelPair>                usableLabels;
};

#endif // AUTOLABEL_H
