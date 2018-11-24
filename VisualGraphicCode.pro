#-------------------------------------------------
#
# Project created by QtCreator 2018-11-24T12:57:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisualGraphicCode
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dev/src/add_op.cpp \
    dev/src/button.cpp \
    dev/src/gray_op.cpp \
    dev/src/list_graph.cpp \
    dev/src/model_name.cpp \
    dev/src/op_list.cpp \
    dev/src/OpList_manege.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
        mainwindow.h \
    creator_build/ui_mainwindow.h \
    dev/inc/add_op.hpp \
    dev/inc/button.hpp \
    dev/inc/gray_op.hpp \
    dev/inc/image_op_base.hpp \
    dev/inc/image_op_inc.hpp \
    dev/inc/list_graph.hpp \
    dev/inc/math_tool.hpp \
    dev/inc/model_name.hpp \
    dev/inc/op_list.hpp \
    dev/inc/OpList_manege.hpp \
    mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
