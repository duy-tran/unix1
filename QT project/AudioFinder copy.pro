#-------------------------------------------------
#
# Project created by QtCreator 2016-06-17T17:10:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AudioFinder
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filelist.cpp \
    fileswindow.cpp \
    audiofile.cpp

HEADERS  += mainwindow.h \
    filelist.h \
    fileswindow.h \
    audiofile.h

FORMS    += mainwindow.ui \
    fileswindow.ui

DISTFILES += \
    findImage.sh \
    checkDir.sh \
    findFile.sh \
