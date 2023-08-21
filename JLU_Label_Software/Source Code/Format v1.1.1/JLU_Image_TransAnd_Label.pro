QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autolabelvideowindow.cpp \
    autolabelwindow.cpp \
    curpicforlabeling_mainwindow.cpp \
    editpiclabelclass.cpp \
    helpandcheck.cpp \
    labelclass.cpp \
    labelquerydialog.cpp \
    labelsquerytextclass.cpp \
    main.cpp \
    mainwindow.cpp \
    manuallylabel.cpp \
    opencv_Qt_TransForm.cpp \
    setorshiftcurmaxpointcountswindows.cpp \
    setpenwidthwindows.cpp \
    setseperatormainwindow.cpp \
    smartlineeditclass.cpp

HEADERS += \
    autolabelvideowindow.h \
    autolabelwindow.h \
    curpicforlabeling_mainwindow.h \
    editpiclabelclass.h \
    helpandcheck.h \
    labelclass.h \
    labelquerydialog.h \
    labelsquerytextclass.h \
    mainwindow.h \
    manuallylabel.h \
    opencv_Qt_TransFormInterface.h \
    setorshiftcurmaxpointcountswindows.h \
    setpenwidthwindows.h \
    setseperatormainwindow.h \
    smartlineeditclass.h

FORMS += \
    autolabelvideowindow.ui \
    autolabelwindow.ui \
    curpicforlabeling_mainwindow.ui \
    helpandcheck.ui \
    labelquerydialog.ui \
    mainwindow.ui \
    manuallylabel.ui \
    setorshiftcurmaxpointcountswindows.ui \
    setpenwidthwindows.ui \
    setseperatormainwindow.ui

INCLUDEPATH +=  \
    $$PWD/include \
    $$PWD/include/opencv2 \

LIBS += \
   -L$$PWD/libs/ -lopencv_world460d -lopencv_img_hash460d

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    def_source.qrc