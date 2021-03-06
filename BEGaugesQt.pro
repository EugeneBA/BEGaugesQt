#-------------------------------------------------
#
# Project created by QtCreator 2018-08-10T18:20:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BEGaugesQt
TEMPLATE = app

#enable C++11
QMAKE_CXXFLAGS += -std=c++0x

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    src/CircularGauges/cgitem.cpp \
    src/CircularGauges/cgwidget.cpp \
    src/CircularGauges/cgscale.cpp \
    src/CircularGauges/cgarc.cpp \
    src/CircularGauges/cgneedle.cpp \
    src/CircularGauges/cgtriangleneedle.cpp \
    src/CircularGauges/cgtrapezeneedle.cpp \
    demo/clockwidget.cpp \
    src/CircularGauges/cgvalues.cpp \
    src/CircularGauges/cgticks.cpp \
    src/CircularGauges/cgtext.cpp \
    demo/arrowmeterwidget.cpp \
    demo/multimeterwidget.cpp

HEADERS += \
        mainwindow.h \
    src/CircularGauges/cgitem.h \
    src/CircularGauges/cgwidget.h \
    src/CircularGauges/cgscale.h \
    src/CircularGauges/cgarc.h \
    src/CircularGauges/cgneedle.h \
    src/CircularGauges/cgtriangleneedle.h \
    src/CircularGauges/cgtrapezeneedle.h \
    demo/clockwidget.h \
    src/CircularGauges/cgvalues.h \
    src/CircularGauges/cgticks.h \
    src/CircularGauges/cgtext.h \
    demo/arrowmeterwidget.h \
    demo/multimeterwidget.h

FORMS += \
        mainwindow.ui \
    demo/multimeterwidget.ui
