/********************************************************************************
** Form generated from reading UI file 'setpenwidthwindows.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPENWIDTHWINDOWS_H
#define UI_SETPENWIDTHWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include "smartlineeditclass.h"

QT_BEGIN_NAMESPACE

class Ui_setPenWidthWindows
{
public:
    QDialogButtonBox *qulifiedOrRefuse;
    QWidget *widget;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QTextBrowser *textBrowser;
    smartLineEditClass *widthSelfGetter;
    QTextBrowser *textBrowser_2;

    void setupUi(QWidget *setPenWidthWindows)
    {
        if (setPenWidthWindows->objectName().isEmpty())
            setPenWidthWindows->setObjectName("setPenWidthWindows");
        setPenWidthWindows->resize(669, 423);
        qulifiedOrRefuse = new QDialogButtonBox(setPenWidthWindows);
        qulifiedOrRefuse->setObjectName("qulifiedOrRefuse");
        qulifiedOrRefuse->setGeometry(QRect(370, 370, 281, 61));
        qulifiedOrRefuse->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(setPenWidthWindows);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(40, 120, 191, 201));
        checkBox = new QCheckBox(widget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(30, 40, 111, 31));
        checkBox->setAutoExclusive(true);
        checkBox_2 = new QCheckBox(widget);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(30, 80, 61, 18));
        checkBox_2->setAutoExclusive(true);
        checkBox_3 = new QCheckBox(widget);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(30, 120, 61, 18));
        checkBox_3->setAutoExclusive(true);
        checkBox_4 = new QCheckBox(widget);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(30, 160, 61, 18));
        checkBox_4->setAutoExclusive(true);
        textBrowser = new QTextBrowser(setPenWidthWindows);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(30, 80, 301, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Consolas")});
        textBrowser->setFont(font);
        widthSelfGetter = new smartLineEditClass(setPenWidthWindows);
        widthSelfGetter->setObjectName("widthSelfGetter");
        widthSelfGetter->setGeometry(QRect(440, 170, 211, 31));
        textBrowser_2 = new QTextBrowser(setPenWidthWindows);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setGeometry(QRect(440, 80, 221, 81));

        retranslateUi(setPenWidthWindows);

        QMetaObject::connectSlotsByName(setPenWidthWindows);
    } // setupUi

    void retranslateUi(QWidget *setPenWidthWindows)
    {
        setPenWidthWindows->setWindowTitle(QCoreApplication::translate("setPenWidthWindows", "Form", nullptr));
        checkBox->setText(QCoreApplication::translate("setPenWidthWindows", "3 pixels", nullptr));
        checkBox_2->setText(QCoreApplication::translate("setPenWidthWindows", "5 pixels", nullptr));
        checkBox_3->setText(QCoreApplication::translate("setPenWidthWindows", "7 pixels", nullptr));
        checkBox_4->setText(QCoreApplication::translate("setPenWidthWindows", "9 pixels", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("setPenWidthWindows", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Consolas'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Microsoft YaHei UI'; font-size:22pt;\">\344\270\200\344\272\233\345\273\272\350\256\256\347\232\204\345\256\275\345\272\246</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Microsoft YaHei UI'; font-size:22pt;\"><br /></p></body></html>", nullptr));
        widthSelfGetter->setText(QCoreApplication::translate("setPenWidthWindows", "\347\233\264\346\216\245\345\215\225\345\207\273\346\210\221\350\276\223\345\205\245\345\256\275\345\272\246(\345\215\225\344\275\215: \345\203\217\347\264\240)", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("setPenWidthWindows", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">\350\207\252\345\256\232\344\271\211\345\256\275\345\272\246\357\274\210\344\275\240\344\271\261\346\225\264\346\210\221\345\217\257\344\270\215\347\256\241\357\274\214\350\207\252\345\267\261\347\234\213\347\235\200\345\212\236\357\274\211</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setPenWidthWindows: public Ui_setPenWidthWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPENWIDTHWINDOWS_H
