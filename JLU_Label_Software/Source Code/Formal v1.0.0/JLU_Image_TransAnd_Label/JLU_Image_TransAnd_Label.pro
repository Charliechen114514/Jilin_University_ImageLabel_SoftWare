QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    autolabel.cpp \
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
    autolabel.h \
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



win32:CONFIG(release, debug|release): LIBS += -LD:/opencv/mybuild/install/x64/vc16/lib/ -lopencv_world460
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/opencv/mybuild/install/x64/vc16/lib/ -lopencv_world460d

INCLUDEPATH += D:/opencv/mybuild/install/include/opencv2
DEPENDPATH += D:/opencv/mybuild/install/include/opencv2

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += D:/opencv/mybuild/install/x64/vc16/lib/libopencv_world460.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += D:/opencv/mybuild/install/x64/vc16/lib/libopencv_world460d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += D:/opencv/mybuild/install/x64/vc16/lib/opencv_world460.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += D:/opencv/mybuild/install/x64/vc16/lib/opencv_world460d.lib

win32:CONFIG(release, debug|release): LIBS += -LD:/opencv/mybuild/install/x64/vc16/lib/ -lopencv_img_hash460
else:win32:CONFIG(debug, debug|release): LIBS += -LD:/opencv/mybuild/install/x64/vc16/lib/ -lopencv_img_hash460d

INCLUDEPATH += D:/opencv/mybuild/install/include
DEPENDPATH += D:/opencv/mybuild/install/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += D:/opencv/mybuild/install/x64/vc16/lib/libopencv_img_hash460.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += D:/opencv/mybuild/install/x64/vc16/lib/libopencv_img_hash460d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += D:/opencv/mybuild/install/x64/vc16/lib/opencv_img_hash460.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += D:/opencv/mybuild/install/x64/vc16/lib/opencv_img_hash460d.lib
