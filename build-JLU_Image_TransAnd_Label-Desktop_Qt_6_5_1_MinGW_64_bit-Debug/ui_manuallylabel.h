/********************************************************************************
** Form generated from reading UI file 'manuallylabel.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
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
    QWidget *centralwidget;
    editpiclabelClass *editPicLable;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTextBrowser *showCurColorTextBrowser;
    QPushButton *changeColorBtn;
    QPushButton *pushButton_4;
    QPushButton *changeWidthBtn;
    QWidget *tab_2;
    QTextBrowser *showCurShapeTypeTextBrowser;
    QPushButton *changeShapeAndMaxPointsCounts;
    QPushButton *pushButton_6;
    QTextBrowser *textBrowser_3;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *manuallyLabel)
    {
        if (manuallyLabel->objectName().isEmpty())
            manuallyLabel->setObjectName("manuallyLabel");
        manuallyLabel->resize(1149, 778);
        actionnewLabel = new QAction(manuallyLabel);
        actionnewLabel->setObjectName("actionnewLabel");
        actiondeleteLable = new QAction(manuallyLabel);
        actiondeleteLable->setObjectName("actiondeleteLable");
        centralwidget = new QWidget(manuallyLabel);
        centralwidget->setObjectName("centralwidget");
        editPicLable = new editpiclabelClass(centralwidget);
        editPicLable->setObjectName("editPicLable");
        editPicLable->setGeometry(QRect(20, 30, 901, 711));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(980, 650, 121, 61));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(980, 570, 121, 61));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(960, 20, 161, 261));
        tab = new QWidget();
        tab->setObjectName("tab");
        showCurColorTextBrowser = new QTextBrowser(tab);
        showCurColorTextBrowser->setObjectName("showCurColorTextBrowser");
        showCurColorTextBrowser->setGeometry(QRect(0, 10, 151, 61));
        changeColorBtn = new QPushButton(tab);
        changeColorBtn->setObjectName("changeColorBtn");
        changeColorBtn->setGeometry(QRect(10, 90, 131, 41));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 190, 131, 41));
        changeWidthBtn = new QPushButton(tab);
        changeWidthBtn->setObjectName("changeWidthBtn");
        changeWidthBtn->setGeometry(QRect(10, 140, 131, 41));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        showCurShapeTypeTextBrowser = new QTextBrowser(tab_2);
        showCurShapeTypeTextBrowser->setObjectName("showCurShapeTypeTextBrowser");
        showCurShapeTypeTextBrowser->setGeometry(QRect(0, 10, 151, 51));
        changeShapeAndMaxPointsCounts = new QPushButton(tab_2);
        changeShapeAndMaxPointsCounts->setObjectName("changeShapeAndMaxPointsCounts");
        changeShapeAndMaxPointsCounts->setGeometry(QRect(10, 70, 141, 51));
        pushButton_6 = new QPushButton(tab_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(10, 140, 141, 51));
        tabWidget->addTab(tab_2, QString());
        textBrowser_3 = new QTextBrowser(centralwidget);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setGeometry(QRect(955, 290, 171, 271));
        manuallyLabel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(manuallyLabel);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1149, 17));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        manuallyLabel->setMenuBar(menubar);
        statusbar = new QStatusBar(manuallyLabel);
        statusbar->setObjectName("statusbar");
        manuallyLabel->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu_2->addAction(actionnewLabel);
        menu_3->addAction(actiondeleteLable);

        retranslateUi(manuallyLabel);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(manuallyLabel);
    } // setupUi

    void retranslateUi(QMainWindow *manuallyLabel)
    {
        manuallyLabel->setWindowTitle(QCoreApplication::translate("manuallyLabel", "MainWindow", nullptr));
        actionnewLabel->setText(QCoreApplication::translate("manuallyLabel", "\346\226\260\347\232\204\346\240\207\347\255\276", nullptr));
        actiondeleteLable->setText(QCoreApplication::translate("manuallyLabel", "\345\210\240\351\231\244\346\227\247\347\232\204\346\240\207\347\255\276", nullptr));
        editPicLable->setText(QCoreApplication::translate("manuallyLabel", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("manuallyLabel", "\345\256\214\346\210\220\357\274\214\344\277\235\345\255\230\345\271\266\351\200\200\345\207\272", nullptr));
        pushButton_3->setText(QCoreApplication::translate("manuallyLabel", "\345\217\226\346\266\210\344\270\200\345\210\207\345\271\266\344\270\224\350\277\224\345\233\236", nullptr));
        showCurColorTextBrowser->setHtml(QCoreApplication::translate("manuallyLabel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">\345\275\223\345\211\215\347\232\204\351\242\234\350\211\262\346\230\257:</span></p></body></html>", nullptr));
        changeColorBtn->setText(QCoreApplication::translate("manuallyLabel", "\346\233\264\346\215\242\351\242\234\350\211\262", nullptr));
        pushButton_4->setText(QCoreApplication::translate("manuallyLabel", "\346\201\242\345\244\215\350\207\263\351\273\230\350\256\244\351\242\234\350\211\262", nullptr));
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
        changeShapeAndMaxPointsCounts->setText(QCoreApplication::translate("manuallyLabel", "\346\233\264\346\215\242\345\275\242\347\212\266\344\270\216\346\240\267\345\274\217", nullptr));
        pushButton_6->setText(QCoreApplication::translate("manuallyLabel", "\346\201\242\345\244\215\350\207\263\351\273\230\350\256\244\347\232\204\345\275\242\347\212\266\344\270\216\346\240\267\345\274\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("manuallyLabel", "\346\240\207\346\263\250\345\275\242\347\212\266", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("manuallyLabel", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">\345\275\223\345\211\215\346\234\211\346\240\207\347\255\276 0 \347\247\215</span></p></body></html>", nullptr));
        menu->setTitle(QCoreApplication::translate("manuallyLabel", "\346\254\276\345\274\217\351\200\211\346\213\251", nullptr));
        menu_2->setTitle(QCoreApplication::translate("manuallyLabel", "\346\267\273\345\212\240...", nullptr));
        menu_3->setTitle(QCoreApplication::translate("manuallyLabel", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class manuallyLabel: public Ui_manuallyLabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANUALLYLABEL_H
