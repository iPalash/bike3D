#-------------------------------------------------
#
# Project created by QtCreator 2013-09-08T20:14:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game_Menu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newgame.cpp \
    highscores.cpp \
    instructions.cpp \
    theme.cpp \
    practicemode.cpp

HEADERS  += mainwindow.h \
    newgame.h \
    highscores.h \
    instructions.h \
    theme.h \
    practicemode.h

FORMS    += mainwindow.ui \
    newgame.ui \
    highscores.ui \
    instructions.ui \
    theme.ui \
    practicemode.ui

RESOURCES += \
    QBike.qrc
