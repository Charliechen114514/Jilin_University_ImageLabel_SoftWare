/********************************************************************************
** Form generated from reading UI file 'autolabel.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTOLABEL_H
#define UI_AUTOLABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_autolabel
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *autolabel)
    {
        if (autolabel->objectName().isEmpty())
            autolabel->setObjectName("autolabel");
        autolabel->resize(800, 600);
        menubar = new QMenuBar(autolabel);
        menubar->setObjectName("menubar");
        autolabel->setMenuBar(menubar);
        centralwidget = new QWidget(autolabel);
        centralwidget->setObjectName("centralwidget");
        autolabel->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(autolabel);
        statusbar->setObjectName("statusbar");
        autolabel->setStatusBar(statusbar);

        retranslateUi(autolabel);

        QMetaObject::connectSlotsByName(autolabel);
    } // setupUi

    void retranslateUi(QMainWindow *autolabel)
    {
        autolabel->setWindowTitle(QCoreApplication::translate("autolabel", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class autolabel: public Ui_autolabel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTOLABEL_H
