/********************************************************************************
** Form generated from reading UI file 'helpandcheck.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPANDCHECK_H
#define UI_HELPANDCHECK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_helpAndCheck
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *helpAndCheck)
    {
        if (helpAndCheck->objectName().isEmpty())
            helpAndCheck->setObjectName("helpAndCheck");
        helpAndCheck->resize(800, 600);
        centralwidget = new QWidget(helpAndCheck);
        centralwidget->setObjectName("centralwidget");
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(20, 10, 761, 551));
        helpAndCheck->setCentralWidget(centralwidget);
        menubar = new QMenuBar(helpAndCheck);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        helpAndCheck->setMenuBar(menubar);
        statusbar = new QStatusBar(helpAndCheck);
        statusbar->setObjectName("statusbar");
        helpAndCheck->setStatusBar(statusbar);

        retranslateUi(helpAndCheck);

        QMetaObject::connectSlotsByName(helpAndCheck);
    } // setupUi

    void retranslateUi(QMainWindow *helpAndCheck)
    {
        helpAndCheck->setWindowTitle(QCoreApplication::translate("helpAndCheck", "MainWindow", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("helpAndCheck", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">\345\275\223\345\211\215\346\224\257\346\214\201\347\232\204\345\277\253\346\215\267\351\224\256\357\274\232</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">\344\270\273\347\252\227\345\217\243\357\274\232</span></p>\n"
"<p style=\"-qt-para"
                        "graph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:22pt;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">1.  \346\211\223\345\274\200\357\274\210\345\257\274\345\205\245\357\274\211\345\233\276\347\211\207     Ctrl + O</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">2.  \346\211\223\345\274\200\357\274\210\345\257\274\345\205\245\357\274\211\346\226\207\344\273\266\345\244\271  Ctrl + Shift + D</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">3.  \345\210\207\346\215\242\345\210\260\344\270\213\344\270\200\345\274\240: 	-&gt; \346\210\226\350\200\205\346\230\257 D</span>"
                        "</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">4.  \345\210\207\346\215\242\345\210\260\344\270\212\344\270\200\345\274\240	&lt;- \346\210\226\350\200\205\346\230\257 A</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">5.  \345\210\207\346\215\242\345\233\276\347\211\207		Ctrl + Alt + P</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">6.  \345\210\207\346\215\242\346\226\207\344\273\266\345\244\271		Ctrl + Alt + D</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">7.  \345\210\240\351\231\244\345\275\223\345\211\215\345\233\276\347\211\207	Ctrl +"
                        " D</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">8.  \347\256\241\347\220\206\346\240\207\347\255\276		Ctrl + L		</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">\346\240\207\346\263\250\346\250\241\345\274\217</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">1.  \345\210\207\346\215\242\345\210\260\344\270\213\344\270\200\345\274\240: 	-&gt; \346\210\226\350\200\205\346\230\257 D</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">2.  \345\210\207\346\215\242\345\210\260\344\270\212\344\270\200\345\274\240	&lt;- \346\210\226\350\200\205\346"
                        "\230\257 A</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">\357\274\210\346\263\250\346\204\217\350\277\231\351\207\214\345\260\261\344\270\215\345\205\201\350\256\270\346\233\264\346\215\242\345\233\276\347\211\207\344\272\206\357\274\211</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">\345\256\236\351\231\205\346\240\207\346\263\250\347\225\214\351\235\242</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">1. \344\270\213\344\270\200\345\274\240\357\274\210\350\213\245\351\200\211\346\213\251\344\272\206\351\273\230\350\256\244\350\267\257\345\276\204\345\260\261\347\233\264\346\216\245\346\214\211\347\205\247\351\273\230\350\256\244\347\232\204\344\277\235"
                        "\345\255\230\346\226\271\345\274\217\344\277\235\345\255\230\345\210\260\350\207\252\345\267\261\351\200\211\346\213\251\347\232\204\351\273\230\350\256\244\347\232\204\346\226\207\344\273\266\345\244\271\357\274\211			-&gt; </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">2. \344\277\235\345\255\230\345\233\276\347\211\207\345\222\214\346\240\207\347\255\276	Ctrl + S</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt;\">3. \346\222\244\351\224\200\344\270\212\344\270\200\346\254\241\346\240\207\346\263\250	Ctrl + Z</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:22pt;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; mar"
                        "gin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class helpAndCheck: public Ui_helpAndCheck {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPANDCHECK_H
