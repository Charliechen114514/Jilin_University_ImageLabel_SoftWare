/********************************************************************************
** Form generated from reading UI file 'labelquerydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELQUERYDIALOG_H
#define UI_LABELQUERYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <labelsquerytextclass.h>

QT_BEGIN_NAMESPACE

class Ui_labelQuerydialog
{
public:
    QTextBrowser *askPermissionOfUsrChoiceInAddLabel;
    labelsQueryTextClass *getTextedLineEdit;
    QTextBrowser *showText_addLabel;
    QPushButton *acceptAndAddBtn;
    QPushButton *rejectAndTryAgainBtn;
    QTextBrowser *showText_selectExsitedLabel;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *showbox;
    QTextBrowser *showLabelCountsTxtBrowser;

    void setupUi(QWidget *labelQuerydialog)
    {
        if (labelQuerydialog->objectName().isEmpty())
            labelQuerydialog->setObjectName("labelQuerydialog");
        labelQuerydialog->resize(673, 452);
        askPermissionOfUsrChoiceInAddLabel = new QTextBrowser(labelQuerydialog);
        askPermissionOfUsrChoiceInAddLabel->setObjectName("askPermissionOfUsrChoiceInAddLabel");
        askPermissionOfUsrChoiceInAddLabel->setGeometry(QRect(10, 40, 631, 61));
        getTextedLineEdit = new labelsQueryTextClass(labelQuerydialog);
        getTextedLineEdit->setObjectName("getTextedLineEdit");
        getTextedLineEdit->setGeometry(QRect(360, 180, 281, 31));
        showText_addLabel = new QTextBrowser(labelQuerydialog);
        showText_addLabel->setObjectName("showText_addLabel");
        showText_addLabel->setGeometry(QRect(360, 120, 281, 51));
        acceptAndAddBtn = new QPushButton(labelQuerydialog);
        acceptAndAddBtn->setObjectName("acceptAndAddBtn");
        acceptAndAddBtn->setGeometry(QRect(410, 390, 111, 41));
        rejectAndTryAgainBtn = new QPushButton(labelQuerydialog);
        rejectAndTryAgainBtn->setObjectName("rejectAndTryAgainBtn");
        rejectAndTryAgainBtn->setGeometry(QRect(550, 390, 101, 41));
        showText_selectExsitedLabel = new QTextBrowser(labelQuerydialog);
        showText_selectExsitedLabel->setObjectName("showText_selectExsitedLabel");
        showText_selectExsitedLabel->setGeometry(QRect(20, 120, 321, 51));
        verticalLayoutWidget = new QWidget(labelQuerydialog);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 200, 311, 221));
        showbox = new QVBoxLayout(verticalLayoutWidget);
        showbox->setObjectName("showbox");
        showbox->setSizeConstraint(QLayout::SetFixedSize);
        showbox->setContentsMargins(0, 0, 0, 0);
        showLabelCountsTxtBrowser = new QTextBrowser(verticalLayoutWidget);
        showLabelCountsTxtBrowser->setObjectName("showLabelCountsTxtBrowser");
        showLabelCountsTxtBrowser->setFrameShape(QFrame::Panel);

        showbox->addWidget(showLabelCountsTxtBrowser);


        retranslateUi(labelQuerydialog);

        QMetaObject::connectSlotsByName(labelQuerydialog);
    } // setupUi

    void retranslateUi(QWidget *labelQuerydialog)
    {
        labelQuerydialog->setWindowTitle(QCoreApplication::translate("labelQuerydialog", "Form", nullptr));
        askPermissionOfUsrChoiceInAddLabel->setHtml(QCoreApplication::translate("labelQuerydialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt;\">\347\241\256\345\256\232\346\267\273\345\212\240\346\210\226\350\200\205\351\200\211\346\213\251\345\267\262\346\234\211\347\232\204\346\240\207\347\255\276\345\230\233\357\274\237</span></p></body></html>", nullptr));
        getTextedLineEdit->setText(QCoreApplication::translate("labelQuerydialog", "\345\234\250\350\277\231\351\207\214\350\276\223\345\205\245\344\275\240\347\232\204\346\240\207\347\255\276\357\274\214\345\257\271\344\272\206\357\274\214\350\256\260\345\276\227\346\230\257\350\213\261\346\226\207:(", nullptr));
        showText_addLabel->setHtml(QCoreApplication::translate("labelQuerydialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\246\202\351\234\200\346\267\273\345\212\240\346\240\207\347\255\276\357\274\214\350\257\267\345\234\250\350\277\231\351\207\214\344\271\246\345\206\231\344\275\240\347\232\204\346\226\260\346\240\207\347\255\276\345\220\215\347\247\260</span></p></body></html>", nullptr));
        acceptAndAddBtn->setText(QCoreApplication::translate("labelQuerydialog", "\347\241\256\345\256\232\346\267\273\345\212\240", nullptr));
        rejectAndTryAgainBtn->setText(QCoreApplication::translate("labelQuerydialog", "\345\217\226\346\266\210\357\274\214\346\210\221\345\217\215\346\202\224\357\274\201", nullptr));
        showText_selectExsitedLabel->setHtml(QCoreApplication::translate("labelQuerydialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\350\257\267\345\234\250\350\277\231\351\207\214\351\200\211\346\213\251\345\267\262\346\234\211\347\232\204\346\240\207\347\255\276\357\274\214\346\210\226\350\200\205\357\274\214\345\210\260\346\227\201\350\276\271\346\267\273\345\212\240\346\226\260\347\232\204\346\240\207\347\255\276</span></p></body></html>", nullptr));
        showLabelCountsTxtBrowser->setHtml(QCoreApplication::translate("labelQuerydialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\216\260\345\234\250\345\260\232\346\227\240\346\240\207\347\255\276\357\274\214\346\267\273\345\212\240\344\270\200\344\270\252\345\220\247\357\274\201awa</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class labelQuerydialog: public Ui_labelQuerydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELQUERYDIALOG_H
