#-------------------------------------------------
#
# Project created by QtCreator 2015-07-24T19:22:07
#
#-------------------------------------------------

QT       += core gui dbus x11extras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dde-launcher
TEMPLATE = app

PKGCONFIG += x11 xcb xcb-ewmh
CONFIG += c++11 link_pkgconfig

include(./widgets/widgets.pri)
include(./cutelogger/cutelogger.pri)

SOURCES += main.cpp \
    views/launcherframe.cpp \
    views/navigationbar.cpp \
    views/basetablewidget.cpp \
    views/apptablewidget.cpp \
    views/categoryframe.cpp \
    app/xcb_misc.cpp \
    app/daemon.cpp \
    app/logmanager.cpp \
    app/launcherapp.cpp \
    views/categorytablewidget.cpp \
    views/displaymodeframe.cpp \
    views/basecheckedbutton.cpp \
    views/baseframe.cpp \
    views/viewmodebutton.cpp \
    views/navigationbuttonframe.cpp \
    dbusinterface/launcher_interface.cpp \
    dbusinterface/dbustype.cpp \
    controller/dbuscontroller.cpp \
    dbusinterface/fileInfo_interface.cpp \
    views/appitem.cpp \
    views/appitemmanager.cpp \
    views/categoryitem.cpp

HEADERS += \
    views/launcherframe.h \
    views/navigationbar.h \
    views/basetablewidget.h \
    views/apptablewidget.h \
    views/categoryframe.h \
    app/define.h \
    app/xcb_misc.h \
    app/daemon.h \
    app/logmanager.h \
    app/launcherapp.h \
    views/categorytablewidget.h \
    app/signalmanager.h \
    app/global.h \
    views/displaymodeframe.h \
    views/basecheckedbutton.h \
    views/baseframe.h \
    views/viewmodebutton.h \
    views/navigationbuttonframe.h \
    dbusinterface/launcher_interface.h \
    dbusinterface/dbustype.h \
    controller/dbuscontroller.h \
    dbusinterface/fileInfo_interface.h \
    views/appitem.h \
    views/appitemmanager.h \
    views/fwd.h \
    views/categoryitem.h

RESOURCES += \
    oldskin.qrc \
    images.qrc

target.path = /usr/bin/
INSTALLS += target