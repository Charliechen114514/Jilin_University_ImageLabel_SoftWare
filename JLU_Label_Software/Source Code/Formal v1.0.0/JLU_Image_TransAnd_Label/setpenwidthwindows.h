<<<<<<< HEAD
#ifndef SETPENWIDTHWINDOWS_H
#define SETPENWIDTHWINDOWS_H

#include <QWidget>

namespace Ui {
class setPenWidthWindows;
}

class setPenWidthWindows : public QWidget
{
    Q_OBJECT

public:
    explicit setPenWidthWindows(QWidget *parent = nullptr);
    ~setPenWidthWindows();
    void setWidthByEditLine();
    void getFinalEditWidth();
    unsigned int getFinalSetPenWidth(){return finWidth;}

private slots:
    void on_qulifiedOrRefuse_rejected();

    void on_qulifiedOrRefuse_accepted();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();
signals:
    void finishedEdit();
private:
    Ui::setPenWidthWindows *ui;
    unsigned int finWidth;
};

#endif // SETPENWIDTHWINDOWS_H
=======
#ifndef SETPENWIDTHWINDOWS_H
#define SETPENWIDTHWINDOWS_H

#include <QWidget>

namespace Ui {
class setPenWidthWindows;
}

class setPenWidthWindows : public QWidget
{
    Q_OBJECT

public:
    explicit setPenWidthWindows(QWidget *parent = nullptr);
    ~setPenWidthWindows();
    void setWidthByEditLine();
    void getFinalEditWidth();
    unsigned int getFinalSetPenWidth(){return finWidth;}

private slots:
    void on_qulifiedOrRefuse_rejected();

    void on_qulifiedOrRefuse_accepted();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();
signals:
    void finishedEdit();
private:
    Ui::setPenWidthWindows *ui;
    unsigned int finWidth;
};

#endif // SETPENWIDTHWINDOWS_H
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
