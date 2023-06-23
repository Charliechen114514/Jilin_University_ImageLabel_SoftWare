/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_newPicture;
    QAction *action_newDirectory;
    QAction *actionchangeLightness;
    QAction *actionchangeContrary;
    QAction *actionsaveAsPng;
    QAction *actionsaveAsJpg;
    QAction *actiongetLablePositionAsTxt;
    QAction *actiongetLablePositionAsYaml;
    QAction *actionremoveSinglePicture;
    QAction *actionremoveAllPictures;
    QAction *actionswitchCurPicture;
    QAction *actionswitchCurDir;
    QAction *actionimportlabelIndex;
    QAction *actionaddNewLabel;
    QWidget *centralwidget;
    QLabel *viewLabel;
    QToolBox *toolPage;
    QWidget *page;
    QPushButton *changeToManuallyLable;
    QWidget *page_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QWidget *page_3;
    QTextBrowser *currentLabelCheck;
    QProgressBar *curPlaceProcessBar;
    QTextBrowser *processTextLine;
    QPushButton *gotoAfterOne;
    QPushButton *gotoPrevious;
    QPushButton *removeCurPictureBtn;
    QPushButton *changeCurPicBtn;
    QPushButton *addNewLebelButton;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QMenu *menu_5;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1063, 767);
        action_newPicture = new QAction(MainWindow);
        action_newPicture->setObjectName("action_newPicture");
        action_newDirectory = new QAction(MainWindow);
        action_newDirectory->setObjectName("action_newDirectory");
        actionchangeLightness = new QAction(MainWindow);
        actionchangeLightness->setObjectName("actionchangeLightness");
        actionchangeContrary = new QAction(MainWindow);
        actionchangeContrary->setObjectName("actionchangeContrary");
        actionsaveAsPng = new QAction(MainWindow);
        actionsaveAsPng->setObjectName("actionsaveAsPng");
        actionsaveAsJpg = new QAction(MainWindow);
        actionsaveAsJpg->setObjectName("actionsaveAsJpg");
        actiongetLablePositionAsTxt = new QAction(MainWindow);
        actiongetLablePositionAsTxt->setObjectName("actiongetLablePositionAsTxt");
        actiongetLablePositionAsYaml = new QAction(MainWindow);
        actiongetLablePositionAsYaml->setObjectName("actiongetLablePositionAsYaml");
        actionremoveSinglePicture = new QAction(MainWindow);
        actionremoveSinglePicture->setObjectName("actionremoveSinglePicture");
        actionremoveAllPictures = new QAction(MainWindow);
        actionremoveAllPictures->setObjectName("actionremoveAllPictures");
        actionswitchCurPicture = new QAction(MainWindow);
        actionswitchCurPicture->setObjectName("actionswitchCurPicture");
        actionswitchCurDir = new QAction(MainWindow);
        actionswitchCurDir->setObjectName("actionswitchCurDir");
        actionimportlabelIndex = new QAction(MainWindow);
        actionimportlabelIndex->setObjectName("actionimportlabelIndex");
        actionaddNewLabel = new QAction(MainWindow);
        actionaddNewLabel->setObjectName("actionaddNewLabel");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        viewLabel = new QLabel(centralwidget);
        viewLabel->setObjectName("viewLabel");
        viewLabel->setGeometry(QRect(10, 0, 851, 561));
        viewLabel->setFrameShape(QFrame::Box);
        viewLabel->setFrameShadow(QFrame::Sunken);
        viewLabel->setAlignment(Qt::AlignCenter);
        toolPage = new QToolBox(centralwidget);
        toolPage->setObjectName("toolPage");
        toolPage->setGeometry(QRect(880, 10, 171, 531));
        toolPage->setFrameShape(QFrame::StyledPanel);
        toolPage->setFrameShadow(QFrame::Sunken);
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 169, 457));
        changeToManuallyLable = new QPushButton(page);
        changeToManuallyLable->setObjectName("changeToManuallyLable");
        changeToManuallyLable->setGeometry(QRect(10, 10, 111, 41));
        toolPage->addItem(page, QString::fromUtf8("\346\211\213\345\212\250\346\240\207\346\263\250"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 169, 457));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 70, 111, 51));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 130, 111, 61));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 10, 111, 51));
        toolPage->addItem(page_2, QString::fromUtf8("\350\207\252\345\212\250\346\240\207\346\263\250"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        currentLabelCheck = new QTextBrowser(page_3);
        currentLabelCheck->setObjectName("currentLabelCheck");
        currentLabelCheck->setGeometry(QRect(10, 0, 151, 311));
        toolPage->addItem(page_3, QString::fromUtf8("\345\267\262\346\234\211\346\240\207\347\255\276"));
        curPlaceProcessBar = new QProgressBar(centralwidget);
        curPlaceProcessBar->setObjectName("curPlaceProcessBar");
        curPlaceProcessBar->setGeometry(QRect(110, 640, 411, 23));
        curPlaceProcessBar->setValue(0);
        processTextLine = new QTextBrowser(centralwidget);
        processTextLine->setObjectName("processTextLine");
        processTextLine->setGeometry(QRect(110, 680, 411, 21));
        gotoAfterOne = new QPushButton(centralwidget);
        gotoAfterOne->setObjectName("gotoAfterOne");
        gotoAfterOne->setGeometry(QRect(440, 570, 191, 51));
        gotoPrevious = new QPushButton(centralwidget);
        gotoPrevious->setObjectName("gotoPrevious");
        gotoPrevious->setGeometry(QRect(50, 570, 221, 51));
        removeCurPictureBtn = new QPushButton(centralwidget);
        removeCurPictureBtn->setObjectName("removeCurPictureBtn");
        removeCurPictureBtn->setGeometry(QRect(720, 570, 141, 51));
        changeCurPicBtn = new QPushButton(centralwidget);
        changeCurPicBtn->setObjectName("changeCurPicBtn");
        changeCurPicBtn->setGeometry(QRect(720, 640, 141, 61));
        addNewLebelButton = new QPushButton(centralwidget);
        addNewLebelButton->setObjectName("addNewLebelButton");
        addNewLebelButton->setGeometry(QRect(890, 570, 141, 51));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(890, 640, 141, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1063, 17));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName("menu_5");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menu->addSeparator();
        menu->addAction(action_newPicture);
        menu->addAction(action_newDirectory);
        menu->addAction(actionswitchCurPicture);
        menu->addAction(actionswitchCurDir);
        menu_2->addAction(actionchangeLightness);
        menu_2->addAction(actionchangeContrary);
        menu_3->addAction(actionsaveAsPng);
        menu_3->addAction(actionsaveAsJpg);
        menu_3->addAction(actiongetLablePositionAsTxt);
        menu_3->addAction(actiongetLablePositionAsYaml);
        menu_4->addAction(actionremoveSinglePicture);
        menu_4->addAction(actionremoveAllPictures);
        menu_5->addAction(actionimportlabelIndex);
        menu_5->addAction(actionaddNewLabel);

        retranslateUi(MainWindow);

        toolPage->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_newPicture->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\345\233\276\347\211\207", nullptr));
        action_newDirectory->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        actionchangeLightness->setText(QCoreApplication::translate("MainWindow", "\344\272\256\345\272\246\350\260\203\346\225\264", nullptr));
        actionchangeContrary->setText(QCoreApplication::translate("MainWindow", "\350\260\203\346\225\264\345\257\271\346\257\224\345\272\246", nullptr));
        actionsaveAsPng->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\344\270\272png", nullptr));
        actionsaveAsJpg->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\207\272\344\270\272jpg", nullptr));
        actiongetLablePositionAsTxt->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220txt\346\240\207\346\263\250\346\225\260\346\215\256", nullptr));
        actiongetLablePositionAsYaml->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220yaml\346\240\274\345\274\217\347\232\204\346\225\260\346\215\256", nullptr));
        actionremoveSinglePicture->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244\345\275\223\345\211\215\345\233\276\347\211\207", nullptr));
        actionremoveAllPictures->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244\346\211\200\346\234\211\345\233\276\347\211\207", nullptr));
        actionswitchCurPicture->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\345\233\276\347\211\207", nullptr));
        actionswitchCurDir->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\346\226\207\344\273\266\347\233\256\345\275\225", nullptr));
        actionimportlabelIndex->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\345\267\262\346\234\211\346\240\207\347\255\276", nullptr));
        actionaddNewLabel->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\260\346\240\207\347\255\276", nullptr));
        viewLabel->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\275\240\347\232\204\345\233\276\347\211\207\357\274\201", nullptr));
        changeToManuallyLable->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\350\207\263\346\240\207\346\263\250\346\250\241\345\274\217", nullptr));
        toolPage->setItemText(toolPage->indexOf(page), QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\346\240\207\346\263\250", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\346\250\241\345\236\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\215\242\346\250\241\345\236\213", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\240\207\346\263\250\357\274\210\345\215\225\345\207\273\346\210\221\346\240\207\346\263\250\357\274\211", nullptr));
        toolPage->setItemText(toolPage->indexOf(page_2), QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\240\207\346\263\250", nullptr));
        toolPage->setItemText(toolPage->indexOf(page_3), QCoreApplication::translate("MainWindow", "\345\267\262\346\234\211\346\240\207\347\255\276", nullptr));
        processTextLine->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\275\223\345\211\215\344\275\240\345\234\250 / </p></body></html>", nullptr));
        gotoAfterOne->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
        gotoPrevious->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252", nullptr));
        removeCurPictureBtn->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244\345\275\223\345\211\215\347\232\204\345\233\276\347\211\207", nullptr));
        changeCurPicBtn->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\215\242\345\275\223\345\211\215\345\233\276\347\211\207", nullptr));
        addNewLebelButton->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\350\210\271\346\226\260\346\240\207\347\255\276", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\350\256\251\344\270\200\344\270\252\346\240\207\347\255\276\346\273\232\350\233\213", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\345\233\276\347\211\207...", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\344\270\216\345\257\274\345\207\272", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\233\276\347\211\207...", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\346\240\207\347\255\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
