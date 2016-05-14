#-------------------------------------------------
#
# Project created by QtCreator 2016-05-03T17:52:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = pd2-Taiko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewindow.cpp \
    dialog.cpp \
    scene.cpp \
    drum.cpp

HEADERS  += mainwindow.h \
    gamewindow.h \
    dialog.h \
    scene.h \
    drum.h

FORMS    += mainwindow.ui \
    gamewindow.ui \
    dialog.ui

RESOURCES += \
    res.qrc
