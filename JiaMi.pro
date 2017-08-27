#-------------------------------------------------
#
# Project created by QtCreator 2016-11-26T19:40:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JiaMi
TEMPLATE = app


SOURCES += main.cpp\
        myw.cpp

PRECOMPILED_HEADER =myw.h

HEADERS  += myw.h

FORMS    += myw.ui

CONFIG += C++11

INCLUDEPATH +=C:\Qt\cv\include
INCLUDEPATH +=C:\Qt\cv\include\opencv2
INCLUDEPATH +=C:\Qt\cv\include\opencv

LIBS +=  -L C:\Qt\cv\lib\libopencv*.a
