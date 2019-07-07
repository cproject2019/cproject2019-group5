#-------------------------------------------------
#
# Project created by QtCreator 2017-05-13T17:35:07
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Application
TEMPLATE = app


SOURCES += main.cpp\
    loginform.cpp \
    mainform.cpp \
        mainwindow.cpp \
    StuManager.cpp \
    addstudlg.cpp \
    createdb.cpp \
    ShopManager.cpp \
    addshopdlg.cpp \
    buyeventdlg.cpp \
    buymanager.cpp

HEADERS  += mainwindow.h \
    StuManager.h \
    addstudlg.h \
    createdb.h \
    ShopManager.h \
    addshopdlg.h \
    buyeventdlg.h \
    buymanager.h \
    loginform.h \
    mainform.h

FORMS    += mainwindow.ui \
    StuManager.ui \
    addstudlg.ui \
    ShopManager.ui \
    addshopdlg.ui \
    buyeventdlg.ui \
    buymanager.ui

SUBDIRS += \
    ../../../../3/LoginForm02/LoginForm02.pro

