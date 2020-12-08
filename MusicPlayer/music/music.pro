#-------------------------------------------------
#
# Project created by QtCreator 2017-08-01T18:54:04
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets
QT       += sql
QT       += winextras


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = MusicPlayer
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
           widget.cpp \
           dialog.cpp

HEADERS += widget.h \
           connection.h \
           dialog.h

FORMS   += widget.ui \
           dialog.ui

RESOURCES += image.qrc

DISTFILES += ios8_Music_48px_1173465_easyicon.net.ico

#RC_ICONS   = ios8_Music_72px_1173465_easyicon.net.ico
