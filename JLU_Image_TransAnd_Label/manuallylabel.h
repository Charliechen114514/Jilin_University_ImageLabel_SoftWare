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
typedef unsigned int SAVESIG;
typedef unsigned int LabelIndex;
namespace Ui {
class manuallyLabel;
}

class manuallyLabel : public QMainWindow
{
    Q_OBJECT

public:
    explicit manuallyLabel(QString curViewPicPath,QWidget *parent = nullptr);

    void initUsrPen();

    void initTabTextBox();

    void getEditedChangedWidth();

    ~manuallyLabel();

private slots:
    void on_changeColorBtn_clicked();

    void on_changeWidthBtn_clicked();

    // void updateLabelListByLabelQueryDialog();
private:
    Ui::manuallyLabel *ui;
    QList<LabelIndex> labelList;
    QString curViewPicPath;
    SAVESIG isSave;
    QPixmap curPixPicMap;
    setPenWidthWindows* showWindow;
};

#endif // MANUALLYLABEL_H
