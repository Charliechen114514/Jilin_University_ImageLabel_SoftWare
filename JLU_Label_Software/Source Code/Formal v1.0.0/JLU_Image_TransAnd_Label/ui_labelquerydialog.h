/********************************************************************************
** Form generated from reading UI file 'labelquerydialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABELQUERYDIALOG_H
#define UI_LABELQUERYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <labelsquerytextclass.h>

QT_BEGIN_NAMESPACE

class Ui_labelQuerydialog
{
public:
    QGridLayout *gridLayout;
    QTextBrowser *showText_selectExsitedLabel;
    QTextBrowser *showText_addLabel;
    QTextBrowser *showLabelCountsTxtBrowser;
    labelsQueryTextClass *getTextedLineEdit;
    QVBoxLayout *showbox;
    QPushButton *acceptAndAddBtn;
    QPushButton *rejectAndTryAgainBtn;
    QPushButton *removeLabelButton;
    QPushButton *ensureTheLabelRes;
    QPushButton *btn_importLabels;

    void setupUi(QWidget *labelQuerydialog)
    {
        if (labelQuerydialog->objectName().isEmpty())
            labelQuerydialog->setObjectName("labelQuerydialog");
        labelQuerydialog->resize(694, 491);
        labelQuerydialog->setMinimumSize(QSize(0, 100));
        labelQuerydialog->setMaximumSize(QSize(16777215, 664));
        gridLayout = new QGridLayout(labelQuerydialog);
        gridLayout->setObjectName("gridLayout");
        showText_selectExsitedLabel = new QTextBrowser(labelQuerydialog);
        showText_selectExsitedLabel->setObjectName("showText_selectExsitedLabel");
        showText_selectExsitedLabel->setMaximumSize(QSize(16777215, 70));

        gridLayout->addWidget(showText_selectExsitedLabel, 0, 0, 1, 1);

        showText_addLabel = new QTextBrowser(labelQuerydialog);
        showText_addLabel->setObjectName("showText_addLabel");
        showText_addLabel->setMaximumSize(QSize(16777215, 70));

        gridLayout->addWidget(showText_addLabel, 0, 1, 1, 2);

        showLabelCountsTxtBrowser = new QTextBrowser(labelQuerydialog);
        showLabelCountsTxtBrowser->setObjectName("showLabelCountsTxtBrowser");
        showLabelCountsTxtBrowser->setMaximumSize(QSize(16777215, 20));
        showLabelCountsTxtBrowser->setFrameShape(QFrame::Panel);

        gridLayout->addWidget(showLabelCountsTxtBrowser, 1, 0, 1, 1);

        getTextedLineEdit = new labelsQueryTextClass(labelQuerydialog);
        getTextedLineEdit->setObjectName("getTextedLineEdit");

        gridLayout->addWidget(getTextedLineEdit, 1, 1, 1, 2);

        showbox = new QVBoxLayout();
        showbox->setObjectName("showbox");
        showbox->setSizeConstraint(QLayout::SetFixedSize);

        gridLayout->addLayout(showbox, 2, 0, 3, 1);

        acceptAndAddBtn = new QPushButton(labelQuerydialog);
        acceptAndAddBtn->setObjectName("acceptAndAddBtn");
        acceptAndAddBtn->setMinimumSize(QSize(0, 100));

        gridLayout->addWidget(acceptAndAddBtn, 2, 1, 1, 1);

        rejectAndTryAgainBtn = new QPushButton(labelQuerydialog);
        rejectAndTryAgainBtn->setObjectName("rejectAndTryAgainBtn");
        rejectAndTryAgainBtn->setMinimumSize(QSize(0, 100));

        gridLayout->addWidget(rejectAndTryAgainBtn, 2, 2, 1, 1);

        removeLabelButton = new QPushButton(labelQuerydialog);
        removeLabelButton->setObjectName("removeLabelButton");
        removeLabelButton->setMinimumSize(QSize(0, 100));

        gridLayout->addWidget(removeLabelButton, 4, 2, 1, 1);

        ensureTheLabelRes = new QPushButton(labelQuerydialog);
        ensureTheLabelRes->setObjectName("ensureTheLabelRes");
        ensureTheLabelRes->setMinimumSize(QSize(0, 100));

        gridLayout->addWidget(ensureTheLabelRes, 3, 1, 1, 1);

        btn_importLabels = new QPushButton(labelQuerydialog);
        btn_importLabels->setObjectName("btn_importLabels");
        btn_importLabels->setMinimumSize(QSize(0, 100));

        gridLayout->addWidget(btn_importLabels, 4, 1, 1, 1);


        retranslateUi(labelQuerydialog);

        QMetaObject::connectSlotsByName(labelQuerydialog);
    } // setupUi

    void retranslateUi(QWidget *labelQuerydialog)
    {
        labelQuerydialog->setWindowTitle(QCoreApplication::translate("labelQuerydialog", "Form", nullptr));
        showText_selectExsitedLabel->setHtml(QCoreApplication::translate("labelQuerydialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\350\257\267\345\234\250\350\277\231\351\207\214\351\200\211\346\213\251\345\267\262\346\234\211\347\232\204\346\240\207\347\255\276\357\274\214\346\210\226\350\200\205\357\274\214\345\210\260\346\227\201\350\276\271\346\267\273\345\212\240\346\226\260\347\232\204\346\240\207\347\255\276</span></p></body></html>", nullptr));
        showText_addLabel->setHtml(QCoreApplication::translate("labelQuerydialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\345\246\202\351\234\200\346\267\273\345\212\240\346\240\207\347\255\276\357\274\214\350\257\267\345\234\250\350\277\231\351\207\214\344\271\246\345\206\231\344\275\240\347\232\204\346\226\260\346\240\207\347\255\276\345\220\215\347\247\260,\347\204\266\345\220\216\347\202\271\345\207\273\342\200\224\342\200\224\346\267\273\345\212\240\346\240\207\347\255\276"
                        "\357\274\214\347\204\266\345\220\216\351\200\211\346\213\251\344\275\240\346\203\263\350\246\201\346\211\223\344\270\212\347\232\204\346\240\207\347\255\276\345\220\216\347\202\271\345\207\273\347\241\256\345\256\232</span></p></body></html>", nullptr));
        showLabelCountsTxtBrowser->setHtml(QCoreApplication::translate("labelQuerydialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\216\260\345\234\250\345\260\232\346\227\240\346\240\207\347\255\276\357\274\214\346\267\273\345\212\240\344\270\200\344\270\252\345\220\247\357\274\201awa</p></body></html>", nullptr));
        getTextedLineEdit->setText(QCoreApplication::translate("labelQuerydialog", "\345\234\250\350\277\231\351\207\214\350\276\223\345\205\245\344\275\240\347\232\204\346\240\207\347\255\276\357\274\214\345\257\271\344\272\206\357\274\214\350\256\260\345\276\227\346\230\257\350\213\261\346\226\207:(", nullptr));
        acceptAndAddBtn->setText(QCoreApplication::translate("labelQuerydialog", "\347\241\256\345\256\232\346\267\273\345\212\240", nullptr));
        rejectAndTryAgainBtn->setText(QCoreApplication::translate("labelQuerydialog", "\345\217\226\346\266\210\357\274\214\346\210\221\345\217\215\346\202\224\346\210\221\347\232\204\346\267\273\345\212\240\357\274\201", nullptr));
        removeLabelButton->setText(QCoreApplication::translate("labelQuerydialog", "\347\247\273\351\231\244\346\240\207\347\255\276", nullptr));
        ensureTheLabelRes->setText(QCoreApplication::translate("labelQuerydialog", "\347\241\256\345\256\232\351\200\211\346\213\251\350\277\231\344\270\252\346\240\207\347\255\276", nullptr));
        btn_importLabels->setText(QCoreApplication::translate("labelQuerydialog", "\345\257\274\345\205\245\345\244\226\351\203\250\346\240\207\347\255\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class labelQuerydialog: public Ui_labelQuerydialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABELQUERYDIALOG_H
