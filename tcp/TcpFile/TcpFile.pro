#-------------------------------------------------
#
# Project created by QtCreator 2019-02-19T10:42:57
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TcpFile
TEMPLATE = app


SOURCES += main.cpp\
        tcpserverfile.cpp \
    tcpsocketform.cpp

HEADERS  += tcpserverfile.h \
    tcpsocketform.h

FORMS    += tcpserverfile.ui \
    tcpsocketform.ui

CONFIG += c++11
