<<<<<<< HEAD
/********************************************************************************
** Form generated from reading UI file 'curpicforlabeling_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURPICFORLABELING_MAINWINDOW_H
#define UI_CURPICFORLABELING_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_curPicForLabeling_MainWindow
{
public:
    QAction *actionendLabeling;
    QAction *actionsavePicOnly;
    QAction *actionsaveLabelsOnly;
    QAction *actionsaveAll;
    QAction *actionchangeToAnyFourPoly;
    QAction *actionchangeToRectMode;
    QAction *actionchangeToFivePoly;
    QAction *actionchangeAndActivateSelectMode;
    QAction *actionchangeColor;
    QAction *actionchangeWidth;
    QAction *actionremoveTheLast;
    QAction *actionopenTheLabelHelper;
    QAction *actioncloseTheLabelHelper;
    QAction *actionchangeHelperPenColor;
    QAction *actionchangeHelperPenWidth;
    QAction *actiontoPreviousPic;
    QAction *actiontoAfterPic;
    QAction *actionremoveTheLastPoint;
    QAction *actionresetNewMethod;
    QAction *action_removeLastPoint;
    QAction *action_removeLastPoly;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *saveImediately;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *curPicForLabeling_MainWindow)
    {
        if (curPicForLabeling_MainWindow->objectName().isEmpty())
            curPicForLabeling_MainWindow->setObjectName("curPicForLabeling_MainWindow");
        curPicForLabeling_MainWindow->resize(800, 600);
        curPicForLabeling_MainWindow->setMouseTracking(true);
        actionendLabeling = new QAction(curPicForLabeling_MainWindow);
        actionendLabeling->setObjectName("actionendLabeling");
        actionsavePicOnly = new QAction(curPicForLabeling_MainWindow);
        actionsavePicOnly->setObjectName("actionsavePicOnly");
        actionsaveLabelsOnly = new QAction(curPicForLabeling_MainWindow);
        actionsaveLabelsOnly->setObjectName("actionsaveLabelsOnly");
        actionsaveAll = new QAction(curPicForLabeling_MainWindow);
        actionsaveAll->setObjectName("actionsaveAll");
        actionchangeToAnyFourPoly = new QAction(curPicForLabeling_MainWindow);
        actionchangeToAnyFourPoly->setObjectName("actionchangeToAnyFourPoly");
        actionchangeToRectMode = new QAction(curPicForLabeling_MainWindow);
        actionchangeToRectMode->setObjectName("actionchangeToRectMode");
        actionchangeToFivePoly = new QAction(curPicForLabeling_MainWindow);
        actionchangeToFivePoly->setObjectName("actionchangeToFivePoly");
        actionchangeAndActivateSelectMode = new QAction(curPicForLabeling_MainWindow);
        actionchangeAndActivateSelectMode->setObjectName("actionchangeAndActivateSelectMode");
        actionchangeColor = new QAction(curPicForLabeling_MainWindow);
        actionchangeColor->setObjectName("actionchangeColor");
        actionchangeWidth = new QAction(curPicForLabeling_MainWindow);
        actionchangeWidth->setObjectName("actionchangeWidth");
        actionremoveTheLast = new QAction(curPicForLabeling_MainWindow);
        actionremoveTheLast->setObjectName("actionremoveTheLast");
        actionopenTheLabelHelper = new QAction(curPicForLabeling_MainWindow);
        actionopenTheLabelHelper->setObjectName("actionopenTheLabelHelper");
        actioncloseTheLabelHelper = new QAction(curPicForLabeling_MainWindow);
        actioncloseTheLabelHelper->setObjectName("actioncloseTheLabelHelper");
        actionchangeHelperPenColor = new QAction(curPicForLabeling_MainWindow);
        actionchangeHelperPenColor->setObjectName("actionchangeHelperPenColor");
        actionchangeHelperPenWidth = new QAction(curPicForLabeling_MainWindow);
        actionchangeHelperPenWidth->setObjectName("actionchangeHelperPenWidth");
        actiontoPreviousPic = new QAction(curPicForLabeling_MainWindow);
        actiontoPreviousPic->setObjectName("actiontoPreviousPic");
        actiontoAfterPic = new QAction(curPicForLabeling_MainWindow);
        actiontoAfterPic->setObjectName("actiontoAfterPic");
        actionremoveTheLastPoint = new QAction(curPicForLabeling_MainWindow);
        actionremoveTheLastPoint->setObjectName("actionremoveTheLastPoint");
        actionresetNewMethod = new QAction(curPicForLabeling_MainWindow);
        actionresetNewMethod->setObjectName("actionresetNewMethod");
        action_removeLastPoint = new QAction(curPicForLabeling_MainWindow);
        action_removeLastPoint->setObjectName("action_removeLastPoint");
        action_removeLastPoly = new QAction(curPicForLabeling_MainWindow);
        action_removeLastPoly->setObjectName("action_removeLastPoly");
        centralwidget = new QWidget(curPicForLabeling_MainWindow);
        centralwidget->setObjectName("centralwidget");
        curPicForLabeling_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(curPicForLabeling_MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        saveImediately = new QMenu(menubar);
        saveImediately->setObjectName("saveImediately");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        QFont font;
        font.setBold(false);
        menu_2->setFont(font);
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName("menu_5");
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName("menu_6");
        curPicForLabeling_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(curPicForLabeling_MainWindow);
        statusbar->setObjectName("statusbar");
        curPicForLabeling_MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_6->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(saveImediately->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actionendLabeling);
        saveImediately->addAction(actionsavePicOnly);
        saveImediately->addAction(actionsaveLabelsOnly);
        saveImediately->addAction(actionsaveAll);
        menu_2->addAction(actionchangeAndActivateSelectMode);
        menu_3->addAction(actionchangeColor);
        menu_3->addAction(actionchangeWidth);
        menu_4->addAction(actionopenTheLabelHelper);
        menu_4->addAction(actioncloseTheLabelHelper);
        menu_4->addAction(actionchangeHelperPenColor);
        menu_4->addAction(actionchangeHelperPenWidth);
        menu_5->addAction(actiontoAfterPic);
        menu_6->addAction(action_removeLastPoint);
        menu_6->addAction(action_removeLastPoly);

        retranslateUi(curPicForLabeling_MainWindow);

        QMetaObject::connectSlotsByName(curPicForLabeling_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *curPicForLabeling_MainWindow)
    {
        curPicForLabeling_MainWindow->setWindowTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "MainWindow", nullptr));
        actionendLabeling->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\347\273\223\346\235\237\346\240\207\350\256\260\357\274\210\344\277\235\345\255\230\346\211\200\346\234\211\357\274\211", nullptr));
        actionsavePicOnly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\217\252\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        actionsaveLabelsOnly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\217\252\344\277\235\345\255\230\346\240\207\347\255\276", nullptr));
        actionsaveLabelsOnly->setIconText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\217\252\344\277\235\345\255\230\346\240\207\347\255\276", nullptr));
        actionsaveAll->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\344\277\235\345\255\230\346\211\200\346\234\211", nullptr));
        actionchangeToAnyFourPoly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\344\273\273\346\204\217\345\233\233\350\276\271\345\275\242\346\240\207\346\263\250", nullptr));
        actionchangeToRectMode->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\346\240\207\345\207\206\347\237\251\345\275\242\346\240\207\346\263\250", nullptr));
        actionchangeToFivePoly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\344\273\273\346\204\217\344\272\224\350\276\271\345\275\242", nullptr));
        actionchangeAndActivateSelectMode->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\215\242\345\275\242\347\212\266", nullptr));
        actionchangeColor->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\215\242\351\242\234\350\211\262", nullptr));
        actionchangeWidth->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\215\242\347\262\227\345\272\246", nullptr));
        actionremoveTheLast->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\222\244\351\224\200\344\270\212\344\270\200\344\270\252\350\275\256\345\273\223", nullptr));
        actionopenTheLabelHelper->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\211\223\345\274\200\350\276\205\345\212\251\346\240\207\350\256\260", nullptr));
        actioncloseTheLabelHelper->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\205\263\351\227\255\350\276\205\345\212\251\346\240\207\350\256\260", nullptr));
        actionchangeHelperPenColor->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\224\271\350\276\205\345\212\251\347\224\273\347\254\224\347\224\273\347\254\224\351\242\234\350\211\262", nullptr));
        actionchangeHelperPenWidth->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\224\271\345\217\230\350\276\205\345\212\251\347\224\273\347\254\224\346\240\207\350\256\260\347\254\224\345\256\275", nullptr));
        actiontoPreviousPic->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\344\270\212\344\270\200\345\274\240", nullptr));
        actiontoAfterPic->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\344\270\213\344\270\200\345\274\240", nullptr));
        actionremoveTheLastPoint->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\222\244\351\224\200\344\270\212\344\270\200\344\270\252\346\240\207\346\263\250\347\202\271", nullptr));
        actionresetNewMethod->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\351\207\215\345\206\231\346\240\207\346\263\250\346\226\207\344\273\266", nullptr));
        action_removeLastPoint->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\347\247\273\351\231\244\344\270\212\344\270\200\344\270\252\347\202\271", nullptr));
        action_removeLastPoly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\347\247\273\351\231\244\344\270\212\344\270\200\344\270\252\350\275\256\345\273\223", nullptr));
        menu->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\344\277\235\345\255\230", nullptr));
        saveImediately->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\351\251\254\344\270\212\344\277\235\345\255\230", nullptr));
        menu_2->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\224\271\345\275\242\347\212\266", nullptr));
        menu_3->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\224\271\347\224\273\347\254\224", nullptr));
        menu_4->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\347\256\241\347\220\206\350\276\205\345\212\251\346\240\207\350\256\260", nullptr));
        menu_5->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\233\276\347\211\207", nullptr));
        menu_6->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\222\244\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class curPicForLabeling_MainWindow: public Ui_curPicForLabeling_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURPICFORLABELING_MAINWINDOW_H
=======
/********************************************************************************
** Form generated from reading UI file 'curpicforlabeling_mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURPICFORLABELING_MAINWINDOW_H
#define UI_CURPICFORLABELING_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_curPicForLabeling_MainWindow
{
public:
    QAction *actionendLabeling;
    QAction *actionsavePicOnly;
    QAction *actionsaveLabelsOnly;
    QAction *actionsaveAll;
    QAction *actionchangeToAnyFourPoly;
    QAction *actionchangeToRectMode;
    QAction *actionchangeToFivePoly;
    QAction *actionchangeAndActivateSelectMode;
    QAction *actionchangeColor;
    QAction *actionchangeWidth;
    QAction *actionremoveTheLast;
    QAction *actionopenTheLabelHelper;
    QAction *actioncloseTheLabelHelper;
    QAction *actionchangeHelperPenColor;
    QAction *actionchangeHelperPenWidth;
    QAction *actiontoPreviousPic;
    QAction *actiontoAfterPic;
    QAction *actionremoveTheLastPoint;
    QAction *actionresetNewMethod;
    QAction *action_removeLastPoint;
    QAction *action_removeLastPoly;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *saveImediately;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *curPicForLabeling_MainWindow)
    {
        if (curPicForLabeling_MainWindow->objectName().isEmpty())
            curPicForLabeling_MainWindow->setObjectName("curPicForLabeling_MainWindow");
        curPicForLabeling_MainWindow->resize(800, 600);
        curPicForLabeling_MainWindow->setMouseTracking(true);
        actionendLabeling = new QAction(curPicForLabeling_MainWindow);
        actionendLabeling->setObjectName("actionendLabeling");
        actionsavePicOnly = new QAction(curPicForLabeling_MainWindow);
        actionsavePicOnly->setObjectName("actionsavePicOnly");
        actionsaveLabelsOnly = new QAction(curPicForLabeling_MainWindow);
        actionsaveLabelsOnly->setObjectName("actionsaveLabelsOnly");
        actionsaveAll = new QAction(curPicForLabeling_MainWindow);
        actionsaveAll->setObjectName("actionsaveAll");
        actionchangeToAnyFourPoly = new QAction(curPicForLabeling_MainWindow);
        actionchangeToAnyFourPoly->setObjectName("actionchangeToAnyFourPoly");
        actionchangeToRectMode = new QAction(curPicForLabeling_MainWindow);
        actionchangeToRectMode->setObjectName("actionchangeToRectMode");
        actionchangeToFivePoly = new QAction(curPicForLabeling_MainWindow);
        actionchangeToFivePoly->setObjectName("actionchangeToFivePoly");
        actionchangeAndActivateSelectMode = new QAction(curPicForLabeling_MainWindow);
        actionchangeAndActivateSelectMode->setObjectName("actionchangeAndActivateSelectMode");
        actionchangeColor = new QAction(curPicForLabeling_MainWindow);
        actionchangeColor->setObjectName("actionchangeColor");
        actionchangeWidth = new QAction(curPicForLabeling_MainWindow);
        actionchangeWidth->setObjectName("actionchangeWidth");
        actionremoveTheLast = new QAction(curPicForLabeling_MainWindow);
        actionremoveTheLast->setObjectName("actionremoveTheLast");
        actionopenTheLabelHelper = new QAction(curPicForLabeling_MainWindow);
        actionopenTheLabelHelper->setObjectName("actionopenTheLabelHelper");
        actioncloseTheLabelHelper = new QAction(curPicForLabeling_MainWindow);
        actioncloseTheLabelHelper->setObjectName("actioncloseTheLabelHelper");
        actionchangeHelperPenColor = new QAction(curPicForLabeling_MainWindow);
        actionchangeHelperPenColor->setObjectName("actionchangeHelperPenColor");
        actionchangeHelperPenWidth = new QAction(curPicForLabeling_MainWindow);
        actionchangeHelperPenWidth->setObjectName("actionchangeHelperPenWidth");
        actiontoPreviousPic = new QAction(curPicForLabeling_MainWindow);
        actiontoPreviousPic->setObjectName("actiontoPreviousPic");
        actiontoAfterPic = new QAction(curPicForLabeling_MainWindow);
        actiontoAfterPic->setObjectName("actiontoAfterPic");
        actionremoveTheLastPoint = new QAction(curPicForLabeling_MainWindow);
        actionremoveTheLastPoint->setObjectName("actionremoveTheLastPoint");
        actionresetNewMethod = new QAction(curPicForLabeling_MainWindow);
        actionresetNewMethod->setObjectName("actionresetNewMethod");
        action_removeLastPoint = new QAction(curPicForLabeling_MainWindow);
        action_removeLastPoint->setObjectName("action_removeLastPoint");
        action_removeLastPoly = new QAction(curPicForLabeling_MainWindow);
        action_removeLastPoly->setObjectName("action_removeLastPoly");
        centralwidget = new QWidget(curPicForLabeling_MainWindow);
        centralwidget->setObjectName("centralwidget");
        curPicForLabeling_MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(curPicForLabeling_MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        saveImediately = new QMenu(menubar);
        saveImediately->setObjectName("saveImediately");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        QFont font;
        font.setBold(false);
        menu_2->setFont(font);
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName("menu_5");
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName("menu_6");
        curPicForLabeling_MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(curPicForLabeling_MainWindow);
        statusbar->setObjectName("statusbar");
        curPicForLabeling_MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_6->menuAction());
        menubar->addAction(menu->menuAction());
        menubar->addAction(saveImediately->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actionendLabeling);
        saveImediately->addAction(actionsavePicOnly);
        saveImediately->addAction(actionsaveLabelsOnly);
        saveImediately->addAction(actionsaveAll);
        menu_2->addAction(actionchangeAndActivateSelectMode);
        menu_3->addAction(actionchangeColor);
        menu_3->addAction(actionchangeWidth);
        menu_4->addAction(actionopenTheLabelHelper);
        menu_4->addAction(actioncloseTheLabelHelper);
        menu_4->addAction(actionchangeHelperPenColor);
        menu_4->addAction(actionchangeHelperPenWidth);
        menu_5->addAction(actiontoAfterPic);
        menu_6->addAction(action_removeLastPoint);
        menu_6->addAction(action_removeLastPoly);

        retranslateUi(curPicForLabeling_MainWindow);

        QMetaObject::connectSlotsByName(curPicForLabeling_MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *curPicForLabeling_MainWindow)
    {
        curPicForLabeling_MainWindow->setWindowTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "MainWindow", nullptr));
        actionendLabeling->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\347\273\223\346\235\237\346\240\207\350\256\260\357\274\210\344\277\235\345\255\230\346\211\200\346\234\211\357\274\211", nullptr));
        actionsavePicOnly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\217\252\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        actionsaveLabelsOnly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\217\252\344\277\235\345\255\230\346\240\207\347\255\276", nullptr));
        actionsaveLabelsOnly->setIconText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\217\252\344\277\235\345\255\230\346\240\207\347\255\276", nullptr));
        actionsaveAll->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\344\277\235\345\255\230\346\211\200\346\234\211", nullptr));
        actionchangeToAnyFourPoly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\344\273\273\346\204\217\345\233\233\350\276\271\345\275\242\346\240\207\346\263\250", nullptr));
        actionchangeToRectMode->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\346\240\207\345\207\206\347\237\251\345\275\242\346\240\207\346\263\250", nullptr));
        actionchangeToFivePoly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\344\273\273\346\204\217\344\272\224\350\276\271\345\275\242", nullptr));
        actionchangeAndActivateSelectMode->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\215\242\345\275\242\347\212\266", nullptr));
        actionchangeColor->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\215\242\351\242\234\350\211\262", nullptr));
        actionchangeWidth->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\215\242\347\262\227\345\272\246", nullptr));
        actionremoveTheLast->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\222\244\351\224\200\344\270\212\344\270\200\344\270\252\350\275\256\345\273\223", nullptr));
        actionopenTheLabelHelper->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\211\223\345\274\200\350\276\205\345\212\251\346\240\207\350\256\260", nullptr));
        actioncloseTheLabelHelper->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\205\263\351\227\255\350\276\205\345\212\251\346\240\207\350\256\260", nullptr));
        actionchangeHelperPenColor->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\224\271\350\276\205\345\212\251\347\224\273\347\254\224\347\224\273\347\254\224\351\242\234\350\211\262", nullptr));
        actionchangeHelperPenWidth->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\224\271\345\217\230\350\276\205\345\212\251\347\224\273\347\254\224\346\240\207\350\256\260\347\254\224\345\256\275", nullptr));
        actiontoPreviousPic->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\344\270\212\344\270\200\345\274\240", nullptr));
        actiontoAfterPic->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\210\260\344\270\213\344\270\200\345\274\240", nullptr));
        actionremoveTheLastPoint->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\222\244\351\224\200\344\270\212\344\270\200\344\270\252\346\240\207\346\263\250\347\202\271", nullptr));
        actionresetNewMethod->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\351\207\215\345\206\231\346\240\207\346\263\250\346\226\207\344\273\266", nullptr));
        action_removeLastPoint->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\347\247\273\351\231\244\344\270\212\344\270\200\344\270\252\347\202\271", nullptr));
        action_removeLastPoly->setText(QCoreApplication::translate("curPicForLabeling_MainWindow", "\347\247\273\351\231\244\344\270\212\344\270\200\344\270\252\350\275\256\345\273\223", nullptr));
        menu->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\344\277\235\345\255\230", nullptr));
        saveImediately->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\351\251\254\344\270\212\344\277\235\345\255\230", nullptr));
        menu_2->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\224\271\345\275\242\347\212\266", nullptr));
        menu_3->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\233\264\346\224\271\347\224\273\347\254\224", nullptr));
        menu_4->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\347\256\241\347\220\206\350\276\205\345\212\251\346\240\207\350\256\260", nullptr));
        menu_5->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\345\210\207\346\215\242\345\233\276\347\211\207", nullptr));
        menu_6->setTitle(QCoreApplication::translate("curPicForLabeling_MainWindow", "\346\222\244\351\224\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class curPicForLabeling_MainWindow: public Ui_curPicForLabeling_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURPICFORLABELING_MAINWINDOW_H
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
