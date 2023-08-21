<<<<<<< HEAD
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
    setseperatormainwindow.cpp \
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
    setseperatormainwindow.h \
    smartlineeditclass.h

FORMS += \
    curpicforlabeling_mainwindow.ui \
    helpandcheck.ui \
    labelquerydialog.ui \
    mainwindow.ui \
    manuallylabel.ui \
    setorshiftcurmaxpointcountswindows.ui \
    setpenwidthwindows.ui \
    setseperatormainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    def_source.qrc

INCLUDEPATH +=
INCLUDEPATH +=  \
    D:/opencv/mybuild/install/include \
    D:/opencv/mybuild/install/include/opencv2 \
    D:/opencv/mybuild/install/x64/vc16/
DEPENDPATH += D:/opencv/mybuild/install/x64/vc16/


LIBS += \
    D:/opencv/mybuild/install/x64/vc16/lib/opencv_world460d.lib \
    D:/opencv/mybuild/install/x64/vc16/lib/opencv_img_hash460d.lib
win32:LIBS += -luser32
=======
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
    setseperatormainwindow.cpp \
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
    setseperatormainwindow.h \
    smartlineeditclass.h

FORMS += \
    curpicforlabeling_mainwindow.ui \
    helpandcheck.ui \
    labelquerydialog.ui \
    mainwindow.ui \
    manuallylabel.ui \
    setorshiftcurmaxpointcountswindows.ui \
    setpenwidthwindows.ui \
    setseperatormainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    def_source.qrc
>>>>>>> 5b85c2e78731c3e34a4c5d175edd7a5553af08ad
