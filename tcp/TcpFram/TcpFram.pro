#-------------------------------------------------
#
# Project created by QtCreator 2019-02-19T09:13:50
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpFram
TEMPLATE = app


SOURCES += main.cpp\
        tcpwidget.cpp \
    socketform.cpp

HEADERS  += tcpwidget.h \
    socketform.h

FORMS    += tcpwidget.ui \
    socketform.ui
