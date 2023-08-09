/********************************************************************************
** Form generated from reading UI file 'setseperatormainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSEPERATORMAINWINDOW_H
#define UI_SETSEPERATORMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetSeperatorMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextBrowser *notes;
    QTextBrowser *showCurSeperator;
    QLineEdit *lineEdit;
    QPushButton *setSemiBtn;
    QPushButton *ensureAndReturnBtn;
    QPushButton *setEnterBtn;
    QPushButton *rejectAndReturnBtn;
    QPushButton *ensureTheEditAndWaitedForFinalEnsure;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SetSeperatorMainWindow)
    {
        if (SetSeperatorMainWindow->objectName().isEmpty())
            SetSeperatorMainWindow->setObjectName("SetSeperatorMainWindow");
        SetSeperatorMainWindow->resize(498, 418);
        centralwidget = new QWidget(SetSeperatorMainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        notes = new QTextBrowser(centralwidget);
        notes->setObjectName("notes");
        notes->setMinimumSize(QSize(0, 200));

        gridLayout->addWidget(notes, 0, 0, 1, 3);

        showCurSeperator = new QTextBrowser(centralwidget);
        showCurSeperator->setObjectName("showCurSeperator");

        gridLayout->addWidget(showCurSeperator, 0, 3, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 1, 0, 1, 4);

        setSemiBtn = new QPushButton(centralwidget);
        setSemiBtn->setObjectName("setSemiBtn");
        setSemiBtn->setMinimumSize(QSize(0, 75));
        QFont font;
        font.setPointSize(20);
        setSemiBtn->setFont(font);

        gridLayout->addWidget(setSemiBtn, 2, 0, 1, 1);

        ensureAndReturnBtn = new QPushButton(centralwidget);
        ensureAndReturnBtn->setObjectName("ensureAndReturnBtn");
        ensureAndReturnBtn->setMinimumSize(QSize(0, 75));
        ensureAndReturnBtn->setFont(font);

        gridLayout->addWidget(ensureAndReturnBtn, 2, 2, 1, 2);

        setEnterBtn = new QPushButton(centralwidget);
        setEnterBtn->setObjectName("setEnterBtn");
        setEnterBtn->setMinimumSize(QSize(0, 75));
        setEnterBtn->setFont(font);

        gridLayout->addWidget(setEnterBtn, 3, 0, 1, 1);

        rejectAndReturnBtn = new QPushButton(centralwidget);
        rejectAndReturnBtn->setObjectName("rejectAndReturnBtn");
        rejectAndReturnBtn->setMinimumSize(QSize(0, 75));
        rejectAndReturnBtn->setFont(font);

        gridLayout->addWidget(rejectAndReturnBtn, 3, 2, 1, 2);

        ensureTheEditAndWaitedForFinalEnsure = new QPushButton(centralwidget);
        ensureTheEditAndWaitedForFinalEnsure->setObjectName("ensureTheEditAndWaitedForFinalEnsure");
        ensureTheEditAndWaitedForFinalEnsure->setMinimumSize(QSize(100, 150));
        ensureTheEditAndWaitedForFinalEnsure->setFont(font);

        gridLayout->addWidget(ensureTheEditAndWaitedForFinalEnsure, 2, 1, 2, 1);

        SetSeperatorMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SetSeperatorMainWindow);
        statusbar->setObjectName("statusbar");
        SetSeperatorMainWindow->setStatusBar(statusbar);

        retranslateUi(SetSeperatorMainWindow);

        QMetaObject::connectSlotsByName(SetSeperatorMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SetSeperatorMainWindow)
    {
        SetSeperatorMainWindow->setWindowTitle(QCoreApplication::translate("SetSeperatorMainWindow", "MainWindow", nullptr));
        notes->setHtml(QCoreApplication::translate("SetSeperatorMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">\345\234\250\350\277\231\351\207\214\350\256\276\347\275\256\345\255\227\347\254\246\350\257\206\345\210\253\345\210\206\345\211\262\347\254\246\357\274\214\346\263\250\346\204\217\345\210\260\346\210\221\344\273\254\351\273\230\350\256\244\347\232\204\346\230\257\350\213\261\346\226\207\346\250\241\345\274\217\344\270\213\347\232\204 ; \344\275\234\344\270\272"
                        "\345\210\206\345\211\262\347\232\204\357\274\201\345\217\257\344\273\245\350\207\252\350\241\214\351\200\211\346\213\251\357\274\214\344\271\237\345\217\257\344\273\245\351\207\215\345\206\231\346\267\273\345\212\240</span></p></body></html>", nullptr));
        showCurSeperator->setHtml(QCoreApplication::translate("SetSeperatorMainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:24pt;\">\345\275\223\345\211\215\344\275\240\347\232\204\345\210\206\345\211\262\347\254\246\346\230\257:</span></p></body></html>", nullptr));
        setSemiBtn->setText(QCoreApplication::translate("SetSeperatorMainWindow", "\357\274\233\357\274\210in English\357\274\211", nullptr));
        ensureAndReturnBtn->setText(QCoreApplication::translate("SetSeperatorMainWindow", "\345\260\261\346\230\257\344\275\240\344\272\206\357\274\232", nullptr));
        setEnterBtn->setText(QCoreApplication::translate("SetSeperatorMainWindow", "Enter\351\224\256", nullptr));
        rejectAndReturnBtn->setText(QCoreApplication::translate("SetSeperatorMainWindow", "\346\210\221\347\210\254", nullptr));
        ensureTheEditAndWaitedForFinalEnsure->setText(QCoreApplication::translate("SetSeperatorMainWindow", "\347\241\256\350\256\244\345\241\253\345\206\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetSeperatorMainWindow: public Ui_SetSeperatorMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSEPERATORMAINWINDOW_H
