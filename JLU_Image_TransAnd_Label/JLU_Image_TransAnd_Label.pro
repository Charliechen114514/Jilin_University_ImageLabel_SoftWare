QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    editpiclabelclass.cpp \
    labelquerydialog.cpp \
    labelsquerytextclass.cpp \
    main.cpp \
    mainwindow.cpp \
    manuallylabel.cpp \
    setpenwidthwindows.cpp \
    smartlineeditclass.cpp

HEADERS += \
    editpiclabelclass.h \
    labelquerydialog.h \
    labelsquerytextclass.h \
    mainwindow.h \
    manuallylabel.h \
    setpenwidthwindows.h \
    smartlineeditclass.h

FORMS += \
    labelquerydialog.ui \
    mainwindow.ui \
    manuallylabel.ui \
    setpenwidthwindows.ui

INCLUDEPATH += D:\opencv\build\include
LIBS += D:\opencv\build\x64\vc14\bin\opencv_world460d.dll

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
