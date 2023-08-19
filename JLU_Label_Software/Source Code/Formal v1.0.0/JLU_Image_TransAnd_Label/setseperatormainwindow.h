<<<<<<< HEAD
#ifndef SETSEPERATORMAINWINDOW_H
#define SETSEPERATORMAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
namespace Ui {
class SetSeperatorMainWindow;
}

class SetSeperatorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetSeperatorMainWindow(QWidget *parent = nullptr);
    void    getSeperatorFromMainWindow(QString seperator);
    void    getSeperatorFromUsrEditLine();
    void    refreshTextBrowser();
    QString returnOutFinalSeperator(){return finalEditResult;};
    bool    isSeperatorValid();
    ~SetSeperatorMainWindow();

signals:
    void finishEditAndReadyReturn();

private slots:
    void on_ensureTheEditAndWaitedForFinalEnsure_clicked();

    void on_setSemiBtn_clicked();

    void on_setEnterBtn_clicked();

    void on_ensureAndReturnBtn_clicked();

    void on_rejectAndReturnBtn_clicked();

private:
    Ui::SetSeperatorMainWindow              *ui;
    QString                                 fromMainWindowSeperator;
    QString                                 finalEditResult;
    bool                                    isSave;
};

#endif // SETSEPERATORMAINWINDOW_H
=======
#ifndef SETSEPERATORMAINWINDOW_H
#define SETSEPERATORMAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
namespace Ui {
class SetSeperatorMainWindow;
}

class SetSeperatorMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SetSeperatorMainWindow(QWidget *parent = nullptr);
    void    getSeperatorFromMainWindow(QString seperator);
    void    getSeperatorFromUsrEditLine();
    void    refreshTextBrowser();
    QString returnOutFinalSeperator(){return finalEditResult;};
    bool    isSeperatorValid();
    ~SetSeperatorMainWindow();

signals:
    void finishEditAndReadyReturn();

private slots:
    void on_ensureTheEditAndWaitedForFinalEnsure_clicked();

    void on_setSemiBtn_clicked();

    void on_setEnterBtn_clicked();

    void on_ensureAndReturnBtn_clicked();

    void on_rejectAndReturnBtn_clicked();

private:
    Ui::SetSeperatorMainWindow              *ui;
    QString                                 fromMainWindowSeperator;
    QString                                 finalEditResult;
    bool                                    isSave;
};

#endif // SETSEPERATORMAINWINDOW_H
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
