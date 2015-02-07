#-------------------------------------------------
#
# Project created by QtCreator 2015-02-07T19:59:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQLikeUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    src/ui/loginform.cpp

HEADERS  += mainwindow.h \
    src/ui/loginform.h

FORMS    += mainwindow.ui \
    src/ui/loginform.ui

RESOURCES += \
    rs/rs.qrc
