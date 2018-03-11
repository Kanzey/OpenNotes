#-------------------------------------------------
#
# Project created by QtCreator 2018-03-02T21:39:59
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Notes
TEMPLATE = app
CONFIG += c++11

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
        mainwindow.cpp \
    dbmanager.cpp \
    qctabwidget.cpp \
    qctabbar.cpp \
    section.cpp \
    settingmanager.cpp \
    tagdelegate.cpp \
    note/note.cpp \
    note/notedelegate.cpp \
    note/notelistoptionsdialog.cpp \
    note/notedisplaysettings.cpp \
    note/notedisplay.cpp \
    note/noteproxymodel.cpp


HEADERS += \
        mainwindow.h \
    dbmanager.h \
    qctabwidget.h \
    qctabbar.h \
    section.h \
    settingmanager.h \
    tagdelegate.h \
    note/note.h \
    note/notedelegate.h \
    note/notedisplay.h \
    note/notedisplaysettings.h \
    note/notelistoptionsdialog.h \
    note/noteproxymodel.h

FORMS += \
    note/notedisplay.ui \
    note/notelistoptionsdialog.ui \
    mainwindow.ui

DISTFILES +=
