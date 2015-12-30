#-------------------------------------------------
#
# Project created by QtCreator 2015-12-21T19:26:00
#
#-------------------------------------------------

QT       -= gui

TARGET = n2draw
TEMPLATE = lib


DEFINES += N2DRAW_LIBRARY
DEFINES += _UNICODE


SOURCES += \
../../source/n2appmanager.cpp            \
../../source/n2draw.cpp                  \
../../source/n2imagemanager.cpp          \
../../source/n2view.cpp                  \
../../source/n2connection.cpp            \
../../source/n2drawmanager.cpp           \
../../source/n2miniXml.cpp               \
../../source/n2viewglue.cpp              \
../../source/n2commander.cpp             \


HEADERS += \
../../header/MerlinoVCPU.h             \
../../header/n2connection.h            \
../../header/n2drawmanager.h           \
../../header/n2miniXml.h               \
../../header/n2viewglue.h              \
../../header/n2appmanager.h            \
../../header/n2draw.h                  \
../../header/n2imagemanager.h          \
../../header/n2view.h                  \
../../header/n2utoatou.h               \
../../header/n2exception.h             \
../../header/n2commander.h             \



DESTDIR =../../../../../../dist

TARGET = n2draw


INCLUDEPATH +=../../header
INCLUDEPATH +=../../../bmpImage/header


linux {
CONFIG += c++11
}
