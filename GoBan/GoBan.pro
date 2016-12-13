#-------------------------------------------------
#
# Project created by QtCreator 2016-12-13T13:44:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GoBan
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    plateau.cpp \
    pierre.cpp \
    cases.cpp \
    joueur.cpp

HEADERS  += mainwindow.h\
    plateau.h \
    pierre.h \
    cases.h \
    joueur.h

FORMS    += mainwindow.ui
