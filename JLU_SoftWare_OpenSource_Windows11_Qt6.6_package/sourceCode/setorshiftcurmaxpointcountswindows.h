#ifndef SETORSHIFTCURMAXPOINTCOUNTSWINDOWS_H
#define SETORSHIFTCURMAXPOINTCOUNTSWINDOWS_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QCheckBox>
#include <QList>
#include <QMessageBox>
#define startShowPoint 200,200
#define ShowPoint_OFFSET_X 20
#define ShowPoint_OFFSET_Y 20
#define Show_WIDTH  150
#define Show_Height 100

namespace Ui {
class setOrShiftCurMaxPointCountsWindows;
}

class setOrShiftCurMaxPointCountsWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit setOrShiftCurMaxPointCountsWindows(QWidget *parent = nullptr);
    void initBasicSelectionCheckBox();
    void showSelections();
    ~setOrShiftCurMaxPointCountsWindows();
    unsigned int returnFinalSeletionInCurMaxPointCount(){return selectedFinalCurMaxPointCount;}
signals:
    void finishSelectAndReadyReturn();

private slots:
    void on_ensureSelectAndCheckIfLegal_clicked();

private:
    Ui::setOrShiftCurMaxPointCountsWindows *ui;
    QButtonGroup                                selections;
    QList<QCheckBox*>                           checkBoxList;
    QList<QString>                              checkBoxNameList;
    unsigned int                                selectedFinalCurMaxPointCount;
};

#endif // SETORSHIFTCURMAXPOINTCOUNTSWINDOWS_H
