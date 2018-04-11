#-------------------------------------------------
#
# Project created by QtCreator 2018-03-26T19:10:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EDP_calculator
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


SOURCES += \
        main.cpp \
        edp_window_1.cpp \
        standard_math.cpp \
        edp_window_2.cpp \
    advanced_math.cpp

HEADERS += \
        edp_window_1.h \
        standard_math.h \
        edp_window_2.h \
        included_headers.h \
    advanced_math.h

FORMS += \
        edp_window_1.ui \
        edp_window_2.ui
