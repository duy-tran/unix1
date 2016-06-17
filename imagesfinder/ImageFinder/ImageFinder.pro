#-------------------------------------------------
#
# Project created by QtCreator 2016-06-17T17:10:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageFinder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imagefile.cpp \
    filelist.cpp \
    fileswindow.cpp

HEADERS  += mainwindow.h \
    imagefile.h \
    filelist.h \
    fileswindow.h

FORMS    += mainwindow.ui \
    fileswindow.ui

DISTFILES += \
    findImage.sh
