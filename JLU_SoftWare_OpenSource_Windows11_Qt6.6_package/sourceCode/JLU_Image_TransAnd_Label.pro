QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    curpicforlabeling_mainwindow.cpp \
    editpiclabelclass.cpp \
    helpandcheck.cpp \
    labelclass.cpp \
    labelquerydialog.cpp \
    labelsquerytextclass.cpp \
    main.cpp \
    mainwindow.cpp \
    manuallylabel.cpp \
    setorshiftcurmaxpointcountswindows.cpp \
    setpenwidthwindows.cpp \
    smartlineeditclass.cpp

HEADERS += \
    curpicforlabeling_mainwindow.h \
    editpiclabelclass.h \
    helpandcheck.h \
    labelclass.h \
    labelquerydialog.h \
    labelsquerytextclass.h \
    mainwindow.h \
    manuallylabel.h \
    setorshiftcurmaxpointcountswindows.h \
    setpenwidthwindows.h \
    smartlineeditclass.h

FORMS += \
    curpicforlabeling_mainwindow.ui \
    helpandcheck.ui \
    labelquerydialog.ui \
    mainwindow.ui \
    manuallylabel.ui \
    setorshiftcurmaxpointcountswindows.ui \
    setpenwidthwindows.ui

INCLUDEPATH += ..\include
LIBS += ..\bin\\libopencv_*.dll

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
