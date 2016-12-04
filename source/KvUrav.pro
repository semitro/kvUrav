#-------------------------------------------------
#
# Project created by QtCreator 2014-09-30T16:55:44
#
#-------------------------------------------------

QT       += core gui

VERSION = 4.04
QMAKE_TARGET_COMPANY = Smt inc 2014 ©
QMAKE_TARGET_PRODUCT = полезности для школы
QMAKE_TARGET_DESCRIPTION = программа включает в себя: решалку кв. уравнений; счётчик среднего арифметического и оценки за тест; основные права и обязанности школьников и учителей.
QMAKE_TARGET_COPYRIGHT = Smt inc
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = KvUrav
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ocenka.cpp \
    startwindow.cpp \
    midrating.cpp \
    myMath.cpp

HEADERS  += mainwindow.h \
    ocenka.h \
    startwindow.h \
    midrating.h \
    myMath.h

FORMS    += mainwindow.ui \
    ocenka.ui \
    startwindow.ui \
    midrating.ui

CONFIG += mobility
#MOBILITY =
#
#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/../build-KvUrav-Android_armeabi_GCC_4_8_Qt_5_3_2-Release

#OTHER_FILES +=

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml \



RESOURCES += \
    images.qrc


