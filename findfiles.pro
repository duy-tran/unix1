QT += widgets

HEADERS       = window.h \
    filelist.h \
    imagefile.h
SOURCES       = main.cpp \
                window.cpp \
    imagefile.cpp \
    filelist.cpp \
    testList.cpp

# install
target.path = ~/unix/project1
INSTALLS += target

DISTFILES += \
    findImage.sh
