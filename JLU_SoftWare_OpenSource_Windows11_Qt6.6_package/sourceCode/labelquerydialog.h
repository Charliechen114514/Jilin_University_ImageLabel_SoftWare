#ifndef LABELQUERYDIALOG_H
#define LABELQUERYDIALOG_H

#include <QWidget>
#include <QList>
#include <QMessageBox>
#include <QCheckBox>
#include <QButtonGroup>
#include <QEvent>
#include <QMessageBox>
#define CHECKBOXSTARTSHOW_X     10
#define CHECKBOXSTARTSHOW_Y     15
#define CHECKBOXSHOW_WIDTH      100
#define CHECKBOXSHOW_HEIGHT     50
#define CHECKBOXSHOW_INTERNAL_X 10
#define CHECKBOXSHOW_INTERNAL_Y 10


#define LABELEDIT_DEFSHOW "现在尚无标签，添加一个吧！awa"
#define LABELEDIT_DEF_LABLE "在这里输入你的标签，对了，记得是英文:("
typedef unsigned int LabelIndex;
typedef QString      LabelName;
typedef QPair<LabelIndex,LabelName> LabelPair;

namespace Ui {
class labelQuerydialog;
}

class labelQuerydialog : public QWidget
{
    Q_OBJECT

public:
    explicit labelQuerydialog(QWidget *parent = nullptr);
    void getTheCurrentLabelList(QList<LabelPair> labelListFrowOutward);
    void initTextLableShow();
    void showcheckedBoxListsSelections();
    LabelPair returnFinalLabelToOutward(){return finalLabel;}
    QList<LabelPair> reFreshMainWindowsLabelList(){return labelList;}
    ~labelQuerydialog();
    void removePossibleRepititionLabelsAndReEnum();
signals:
    void finishSelectingLabel();
    void newLabelEnlists();
    void refuseSaving();
private slots:


    void on_acceptAndAddBtn_clicked();

    void on_rejectAndTryAgainBtn_clicked();

    void on_ensureTheLabelRes_clicked();

    void on_removeLabelButton_clicked();

    void closeEvent(QCloseEvent* events);
private:
    Ui::labelQuerydialog *ui;
    QList<LabelPair> labelList;
    QList<QCheckBox*> checkedBoxLists;
    QButtonGroup* checkBoxLists;
    LabelPair finalLabel;
    bool isAdded;
    bool deleteProcessIn;
    bool isSave;
};

#endif // LABELQUERYDIALOG_H
