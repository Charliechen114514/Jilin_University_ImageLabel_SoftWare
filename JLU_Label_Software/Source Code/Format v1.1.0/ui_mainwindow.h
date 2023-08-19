/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
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
    QAction *actiondeleteOldLabel;
    QAction *checkQuickKeySequence;
    QAction *actioncheckAuthor;
    QAction *actionfindShitBugAndsakForMail;
    QAction *actionSetLabelSeperator;
    QAction *actionrewriteLebelShowMethod;
    QAction *action_setAutoLabelPath;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QPushButton *manageLabelButton;
    QToolBox *toolPage;
    QWidget *page;
    QPushButton *changeToManuallyLable;
    QWidget *page_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *btn_autoLabel;
    QPushButton *btn_autoLabelVideo;
    QWidget *page_3;
    QTextBrowser *currentLabelCheck;
    QPushButton *gotoPrevious;
    QLabel *viewLabel;
    QTextBrowser *processTextLine;
    QPushButton *changeCurPicBtn;
    QPushButton *removeCurPictureBtn;
    QPushButton *gotoAfterOne;
    QProgressBar *curPlaceProcessBar;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_4;
    QMenu *menu_5;
    QMenu *menu_3;
    QMenu *menu_6;
    QMenu *menu_7;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1043, 767);
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
        actiondeleteOldLabel = new QAction(MainWindow);
        actiondeleteOldLabel->setObjectName("actiondeleteOldLabel");
        checkQuickKeySequence = new QAction(MainWindow);
        checkQuickKeySequence->setObjectName("checkQuickKeySequence");
        actioncheckAuthor = new QAction(MainWindow);
        actioncheckAuthor->setObjectName("actioncheckAuthor");
        actionfindShitBugAndsakForMail = new QAction(MainWindow);
        actionfindShitBugAndsakForMail->setObjectName("actionfindShitBugAndsakForMail");
        actionSetLabelSeperator = new QAction(MainWindow);
        actionSetLabelSeperator->setObjectName("actionSetLabelSeperator");
        actionrewriteLebelShowMethod = new QAction(MainWindow);
        actionrewriteLebelShowMethod->setObjectName("actionrewriteLebelShowMethod");
        action_setAutoLabelPath = new QAction(MainWindow);
        action_setAutoLabelPath->setObjectName("action_setAutoLabelSavePath");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        manageLabelButton = new QPushButton(centralwidget);
        manageLabelButton->setObjectName("manageLabelButton");
        manageLabelButton->setMinimumSize(QSize(0, 100));

        gridLayout_2->addWidget(manageLabelButton, 1, 3, 3, 1);

        toolPage = new QToolBox(centralwidget);
        toolPage->setObjectName("toolPage");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(toolPage->sizePolicy().hasHeightForWidth());
        toolPage->setSizePolicy(sizePolicy);
        toolPage->setMinimumSize(QSize(200, 600));
        toolPage->setMaximumSize(QSize(200, 16777215));
        toolPage->setFrameShape(QFrame::StyledPanel);
        toolPage->setFrameShadow(QFrame::Sunken);
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 198, 526));
        changeToManuallyLable = new QPushButton(page);
        changeToManuallyLable->setObjectName("changeToManuallyLable");
        changeToManuallyLable->setGeometry(QRect(10, 10, 111, 41));
        toolPage->addItem(page, QString::fromUtf8("\346\211\213\345\212\250\346\240\207\346\263\250"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 198, 526));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(40, 70, 141, 51));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 130, 141, 51));
        btn_autoLabel = new QPushButton(page_2);
        btn_autoLabel->setObjectName("btn_autoLabel");
        btn_autoLabel->setGeometry(QRect(40, 10, 141, 51));
        btn_autoLabelVideo = new QPushButton(page_2);
        btn_autoLabelVideo->setObjectName("btn_autoLabelVideo");
        btn_autoLabelVideo->setGeometry(QRect(40,180,141,51));
        toolPage->addItem(page_2, QString::fromUtf8("\350\207\252\345\212\250\346\240\207\346\263\250"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setGeometry(QRect(0, 0, 198, 526));
        currentLabelCheck = new QTextBrowser(page_3);
        currentLabelCheck->setObjectName("currentLabelCheck");
        currentLabelCheck->setGeometry(QRect(10, 0, 151, 311));
        toolPage->addItem(page_3, QString::fromUtf8("\345\267\262\346\234\211\346\240\207\347\255\276"));

        gridLayout_2->addWidget(toolPage, 0, 3, 1, 1);

        gotoPrevious = new QPushButton(centralwidget);
        gotoPrevious->setObjectName("gotoPrevious");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gotoPrevious->sizePolicy().hasHeightForWidth());
        gotoPrevious->setSizePolicy(sizePolicy1);
        gotoPrevious->setMinimumSize(QSize(200, 50));

        gridLayout_2->addWidget(gotoPrevious, 1, 0, 1, 1);

        viewLabel = new QLabel(centralwidget);
        viewLabel->setObjectName("viewLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(viewLabel->sizePolicy().hasHeightForWidth());
        viewLabel->setSizePolicy(sizePolicy2);
        viewLabel->setMinimumSize(QSize(800, 600));
        viewLabel->setFrameShape(QFrame::Box);
        viewLabel->setFrameShadow(QFrame::Sunken);
        viewLabel->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(viewLabel, 0, 0, 1, 3);

        processTextLine = new QTextBrowser(centralwidget);
        processTextLine->setObjectName("processTextLine");
        sizePolicy2.setHeightForWidth(processTextLine->sizePolicy().hasHeightForWidth());
        processTextLine->setSizePolicy(sizePolicy2);
        processTextLine->setMinimumSize(QSize(400, 20));
        processTextLine->setMaximumSize(QSize(800, 40));

        gridLayout_2->addWidget(processTextLine, 3, 0, 1, 2);

        changeCurPicBtn = new QPushButton(centralwidget);
        changeCurPicBtn->setObjectName("changeCurPicBtn");
        changeCurPicBtn->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(changeCurPicBtn, 2, 2, 2, 1);

        removeCurPictureBtn = new QPushButton(centralwidget);
        removeCurPictureBtn->setObjectName("removeCurPictureBtn");
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(removeCurPictureBtn->sizePolicy().hasHeightForWidth());
        removeCurPictureBtn->setSizePolicy(sizePolicy3);
        removeCurPictureBtn->setMinimumSize(QSize(200, 50));

        gridLayout_2->addWidget(removeCurPictureBtn, 1, 2, 1, 1);

        gotoAfterOne = new QPushButton(centralwidget);
        gotoAfterOne->setObjectName("gotoAfterOne");
        sizePolicy1.setHeightForWidth(gotoAfterOne->sizePolicy().hasHeightForWidth());
        gotoAfterOne->setSizePolicy(sizePolicy1);
        gotoAfterOne->setMinimumSize(QSize(200, 50));

        gridLayout_2->addWidget(gotoAfterOne, 1, 1, 1, 1);

        curPlaceProcessBar = new QProgressBar(centralwidget);
        curPlaceProcessBar->setObjectName("curPlaceProcessBar");
        curPlaceProcessBar->setMinimumSize(QSize(400, 20));
        curPlaceProcessBar->setValue(0);

        gridLayout_2->addWidget(curPlaceProcessBar, 2, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1043, 17));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        menu_5 = new QMenu(menubar);
        menu_5->setObjectName("menu_5");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_6 = new QMenu(menubar);
        menu_6->setObjectName("menu_6");
        menu_7 = new QMenu(menubar);
        menu_7->setObjectName("menu_7");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_5->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_6->menuAction());
        menubar->addAction(menu_7->menuAction());
        menu->addSeparator();
        menu->addAction(action_newPicture);
        menu->addAction(action_newDirectory);
        menu->addAction(actionswitchCurPicture);
        menu->addAction(actionswitchCurDir);
        menu_4->addAction(actionremoveSinglePicture);
        menu_4->addAction(actionremoveAllPictures);
        menu_5->addAction(actionimportlabelIndex);
        menu_5->addAction(actionaddNewLabel);
        menu_5->addAction(actiondeleteOldLabel);
        menu_3->addAction(checkQuickKeySequence);
        menu_3->addAction(actionfindShitBugAndsakForMail);
        menu_6->addAction(actioncheckAuthor);
        menu_7->addAction(actionSetLabelSeperator);
        menu_7->addAction(action_setAutoLabelPath);
        retranslateUi(MainWindow);

        toolPage->setCurrentIndex(1);


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
        actiondeleteOldLabel->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\227\247\346\240\207\347\255\276", nullptr));
        checkQuickKeySequence->setText(QCoreApplication::translate("MainWindow", "\346\237\245\351\230\205\345\277\253\346\215\267\351\224\256", nullptr));
        actioncheckAuthor->setText(QCoreApplication::translate("MainWindow", "\347\234\213\347\234\213\350\277\231\347\216\251\346\204\217\350\260\201\345\201\232\347\232\204", nullptr));
        actionfindShitBugAndsakForMail->setText(QCoreApplication::translate("MainWindow", "\345\217\221\347\216\260\344\272\206bug\347\204\266\345\220\216\351\227\256\345\200\231\344\275\234\350\200\205", nullptr));
        actionSetLabelSeperator->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\240\207\347\255\276\345\257\274\345\205\245\350\257\206\345\210\253\345\210\206\345\211\262\347\254\246", nullptr));
        actionrewriteLebelShowMethod->setText(QCoreApplication::translate("MainWindow", "\351\207\215\345\206\231\347\202\271\346\240\207\346\263\250\346\226\207\344\273\266\346\240\274\345\274\217", nullptr));
        action_setAutoLabelPath->setText("设置自动保存路径");
        manageLabelButton->setText(QCoreApplication::translate("MainWindow", "\350\260\203\346\225\231\344\275\240\347\232\204\346\240\207\347\255\276", nullptr));
        changeToManuallyLable->setText(QCoreApplication::translate("MainWindow", "\345\210\207\346\215\242\350\207\263\346\240\207\346\263\250\346\250\241\345\274\217", nullptr));
        toolPage->setItemText(toolPage->indexOf(page), QCoreApplication::translate("MainWindow", "\346\211\213\345\212\250\346\240\207\346\263\250", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\345\257\274\345\205\245\346\250\241\345\236\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\215\242\346\250\241\345\236\213", nullptr));
        btn_autoLabel->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\240\207\346\263\250\357\274\210\345\215\225\345\207\273\346\210\221\346\240\207\346\263\250\357\274\211", nullptr));
        btn_autoLabelVideo->setText("自动标注视频（单击我标注）");
        toolPage->setItemText(toolPage->indexOf(page_2), QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\346\240\207\346\263\250", nullptr));
        toolPage->setItemText(toolPage->indexOf(page_3), QCoreApplication::translate("MainWindow", "\345\267\262\346\234\211\346\240\207\347\255\276", nullptr));
        gotoPrevious->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252", nullptr));
        viewLabel->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\344\275\240\347\232\204\345\233\276\347\211\207\357\274\201", nullptr));
        processTextLine->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\345\275\223\345\211\215\344\275\240\345\234\250 / </p></body></html>", nullptr));
        changeCurPicBtn->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\215\242\345\275\223\345\211\215\345\233\276\347\211\207", nullptr));
        removeCurPictureBtn->setText(QCoreApplication::translate("MainWindow", "\347\247\273\351\231\244\345\275\223\345\211\215\347\232\204\345\233\276\347\211\207", nullptr));
        gotoAfterOne->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\233\276\347\211\207...", nullptr));
        menu_5->setTitle(QCoreApplication::translate("MainWindow", "\347\256\241\347\220\206\346\240\207\347\255\276", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        menu_6->setTitle(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216...", nullptr));
        menu_7->setTitle(QCoreApplication::translate("MainWindow", "\351\253\230\347\272\247\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
