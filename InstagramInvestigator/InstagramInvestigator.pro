#-------------------------------------------------
#
# Project created by QtCreator 2016-04-19T23:16:31
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lcurl

TARGET = InstagramInvestigator
TEMPLATE = app

QMAKE_RPATHDIR += /prefered/path/to/lib/

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    addurllist.h \
    coutoldurls.h

FORMS    += mainwindow.ui
