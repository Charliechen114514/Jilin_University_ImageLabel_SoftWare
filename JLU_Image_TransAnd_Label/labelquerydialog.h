#ifndef LABELQUERYDIALOG_H
#define LABELQUERYDIALOG_H

#include <QWidget>
#include <QList>
#include <QMessageBox>
#include <QCheckBox>
#include <QButtonGroup>
#define CHECKBOXSTARTSHOW_X     10
#define CHECKBOXSTARTSHOW_Y     15
#define CHECKBOXSHOW_WIDTH      100
#define CHECKBOXSHOW_HEIGHT     50
#define CHECKBOXSHOW_INTERNAL_X 10
#define CHECKBOXSHOW_INTERNAL_Y 10

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
    ~labelQuerydialog();

private slots:


    void on_acceptAndAddBtn_clicked();

private:
    Ui::labelQuerydialog *ui;
    QList<LabelPair> labelList;
    QList<QCheckBox*> checkedBoxLists;
    QButtonGroup* checkBoxLists;
};

#endif // LABELQUERYDIALOG_H
