/********************************************************************************
** Form generated from reading UI file 'manuallylabel.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANUALLYLABEL_H
#define UI_MANUALLYLABEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "editpiclabelclass.h"

QT_BEGIN_NAMESPACE

class Ui_manuallyLabel
{
public:
    QAction *actionnewLabel;
    QAction *actiondeleteLable;
    QAction *actionchangePenColor;
    QAction *actionchangePenWidth;
    QAction *actiondeleteOldLabel;
    QWidget *centralwidget;
    editpiclabelClass *editPicLable;
    QPushButton *saveAllAndExportTheImage;
    QPushButton *cancelAllAndBackToMainWindow;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextBrowser *showCurColorTextBrowser;
    QPushButton *changeColorBtn;
    QPushButton *backToDefPen;
    QPushButton *changeWidthBtn;
    QWidget *tab_2;
    QTextBrowser *showCurShapeTypeTextBrowser;
    QTextBrowser *showCurTextLabelCountTextBrowser;
    QPushButton *activeToLabel;
    QPushButton *manageLabelBtn;
    QPushButton *toPreviousPic;
    QPushButton *toAfterPic;
    QProgressBar *showProgressBar;
    QTextBrowser *showCurProcess;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *manuallyLabel)
    {
        if (manuallyLabel->objectName().isEmpty())
            manuallyLabel->setObjectName("manuallyLabel");
        manuallyLabel->resize(1149, 797);
        actionnewLabel = new QAction(manuallyLabel);
        actionnewLabel->setObjectName("actionnewLabel");
        actiondeleteLable = new QAction(manuallyLabel);
        actiondeleteLable->setObjectName("actiondeleteLable");
        actionchangePenColor = new QAction(manuallyLabel);
        actionchangePenColor->setObjectName("actionchangePenColor");
        actionchangePenWidth = new QAction(manuallyLabel);
        actionchangePenWidth->setObjectName("actionchangePenWidth");
        actiondeleteOldLabel = new QAction(manuallyLabel);
        actiondeleteOldLabel->setObjectName("actiondeleteOldLabel");
        centralwidget = new QWidget(manuallyLabel);
        centralwidget->setObjectName("centralwidget");
        editPicLable = new editpiclabelClass(centralwidget);
        editPicLable->setObjectName("editPicLable");
        editPicLable->setGeometry(QRect(0, -10, 841, 621));
        saveAllAndExportTheImage = new QPushButton(centralwidget);
        saveAllAndExportTheImage->setObjectName("saveAllAndExportTheImage");
        saveAllAndExportTheImage->setGeometry(QRect(980, 690, 121, 51));
        cancelAllAndBackToMainWindow = new QPushButton(centralwidget);
        cancelAllAndBackToMainWindow->setObjectName("cancelAllAndBackToMainWindow");
        cancelAllAndBackToMainWindow->setGeometry(QRect(980, 630, 121, 51));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(960, 20, 161, 271));
        tab = new QWidget();
        tab->setObjectName("tab");
        showCurColorTextBrowser = new QTextBrowser(tab);
        showCurColorTextBrowser->setObjectName("showCurColorTextBrowser");
        showCurColorTextBrowser->setGeometry(QRect(0, 10, 151, 61));
        changeColorBtn = new QPushButton(tab);
        changeColorBtn->setObjectName("changeColorBtn");
        changeColorBtn->setGeometry(QRect(10, 90, 131, 41));
        backToDefPen = new QPushButton(tab);
        backToDefPen->setObjectName("backToDefPen");
        backToDefPen->setGeometry(QRect(10, 190, 131, 41));
        changeWidthBtn = new QPushButton(tab);
        changeWidthBtn->setObjectName("changeWidthBtn");
        changeWidthBtn->setGeometry(QRect(10, 140, 131, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        showCurShapeTypeTextBrowser = new QTextBrowser(tab_2);
        showCurShapeTypeTextBrowser->setObjectName("showCurShapeTypeTextBrowser");
        showCurShapeTypeTextBrowser->setGeometry(QRect(0, 10, 151, 221));
        tabWidget->addTab(tab_2, QString());
        showCurTextLabelCountTextBrowser = new QTextBrowser(centralwidget);
        showCurTextLabelCountTextBrowser->setObjectName("showCurTextLabelCountTextBrowser");
        showCurTextLabelCountTextBrowser->setGeometry(QRect(955, 350, 181, 211));
        activeToLabel = new QPushButton(centralwidget);
        activeToLabel->setObjectName("activeToLabel");
        activeToLabel->setGeometry(QRect(960, 290, 171, 51));
        manageLabelBtn = new QPushButton(centralwidget);
        manageLabelBtn->setObjectName("manageLabelBtn");
        manageLabelBtn->setGeometry(QRect(980, 580, 121, 41));
        toPreviousPic = new QPushButton(centralwidget);
        toPreviousPic->setObjectName("toPreviousPic");
        toPreviousPic->setGeometry(QRect(60, 700, 201, 51));
        toAfterPic = new QPushButton(centralwidget);
        toAfterPic->setObjectName("toAfterPic");
        toAfterPic->setGeometry(QRect(600, 700, 211, 51));
        showProgressBar = new QProgressBar(centralwidget);
        showProgressBar->setObjectName("showProgressBar");
        showProgressBar->setGeometry(QRect(60, 650, 391, 31));
        showProgressBar->setValue(24);
        showCurProcess = new QTextBrowser(centralwidget);
        showCurProcess->setObjectName("showCurProcess");
        showCurProcess->setGeometry(QRect(470, 650, 361, 31));
        manuallyLabel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(manuallyLabel);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1149, 17));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        manuallyLabel->setMenuBar(menubar);
        statusbar = new QStatusBar(manuallyLabel);
        statusbar->setObjectName("statusbar");
        manuallyLabel->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionchangePenColor);
        menu->addAction(actionchangePenWidth);
        menu_2->addAction(actionnewLabel);
        menu_2->addAction(actiondeleteOldLabel);

        retranslateUi(manuallyLabel);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(manuallyLabel);
    } // setupUi

    void retranslateUi(QMainWindow *manuallyLabel)
    {
        manuallyLabel->setWindowTitle(QCoreApplication::translate("manuallyLabel", "MainWindow", nullptr));
        actionnewLabel->setText(QCoreApplication::translate("manuallyLabel", "\346\267\273\345\212\240\346\226\260\347\232\204\346\240\207\347\255\276", nullptr));
        actiondeleteLable->setText(QCoreApplication::translate("manuallyLabel", "\345\210\240\351\231\244\346\227\247\347\232\204\346\240\207\347\255\276", nullptr));
        actionchangePenColor->setText(QCoreApplication::translate("manuallyLabel", "\346\233\264\346\215\242\347\254\224\347\232\204\351\242\234\350\211\262", nullptr));
        actionchangePenWidth->setText(QCoreApplication::translate("manuallyLabel", "\346\233\264\346\215\242\347\254\224\347\232\204\347\262\227\347\273\206", nullptr));
        actiondeleteOldLabel->setText(QCoreApplication::translate("manuallyLabel", "\345\210\240\351\231\244\346\227\247\347\232\204\346\240\207\347\255\276", nullptr));
        editPicLable->setText(QCoreApplication::translate("manuallyLabel", "TextLabel", nullptr));
        saveAllAndExportTheImage->setText(QCoreApplication::translate("manuallyLabel", "\345\256\214\346\210\220\357\274\214\344\277\235\345\255\230\345\271\266\351\200\200\345\207\272", nullptr));
        cancelAllAndBackToMainWindow->setText(QCoreApplication::translate("manuallyLabel", "\345\217\226\346\266\210\344\270\200\345\210\207\345\271\266\344\270\224\350\277\224\345\233\236", nullptr));
        showCurColorTextBrowser->setHtml(QCoreApplication::translate("manuallyLabel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">\345\275\223\345\211\215\347\232\204\351\242\234\350\211\262\346\230\257:</span></p></body></html>", nullptr));
        changeColorBtn->setText(QCoreApplication::translate("manuallyLabel", "\346\233\264\346\215\242\351\242\234\350\211\262", nullptr));
        backToDefPen->setText(QCoreApplication::translate("manuallyLabel", "\346\201\242\345\244\215\350\207\263\351\273\230\350\256\244\351\242\234\350\211\262", nullptr));
        changeWidthBtn->setText(QCoreApplication::translate("manuallyLabel", "\346\233\264\346\215\242\347\262\227\347\273\206", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("manuallyLabel", "\351\242\234\350\211\262", nullptr));
        showCurShapeTypeTextBrowser->setHtml(QCoreApplication::translate("manuallyLabel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">\345\275\223\345\211\215\347\232\204\346\240\207\346\263\250\345\275\242\347\212\266\346\230\257:</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("manuallyLabel", "\346\240\207\346\263\250\345\275\242\347\212\266", nullptr));
        showCurTextLabelCountTextBrowser->setHtml(QCoreApplication::translate("manuallyLabel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\345\275\223\345\211\215\346\234\211\346\240\207\347\255\276 0 \347\247\215</span></p></body></html>", nullptr));
        activeToLabel->setText(QCoreApplication::translate("manuallyLabel", "\345\257\271\346\255\244\346\240\207\346\263\250", nullptr));
        manageLabelBtn->setText(QCoreApplication::translate("manuallyLabel", "\347\256\241\347\220\206\346\240\207\347\255\276", nullptr));
        toPreviousPic->setText(QCoreApplication::translate("manuallyLabel", "\344\270\212\344\270\200\345\274\240", nullptr));
        toAfterPic->setText(QCoreApplication::translate("manuallyLabel", "\344\270\213\344\270\200\345\274\240", nullptr));
        menu->setTitle(QCoreApplication::translate("manuallyLabel", "\346\254\276\345\274\217\351\200\211\346\213\251", nullptr));
        menu_2->setTitle(QCoreApplication::translate("manuallyLabel", "\347\256\241\347\220\206\346\240\207\347\255\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manuallyLabel: public Ui_manuallyLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALLYLABEL_H
