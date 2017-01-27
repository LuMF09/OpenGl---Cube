#-------------------------------------------------
#
# Project created by QtCreator 2016-11-15T14:43:46
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CubeMenu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glslprogram.cpp \
    glutils.cpp \
    mainview.cpp \
    scenebasic.cpp \
    dialog.cpp \
    dialogeyes.cpp

HEADERS  += mainwindow.h \
    glslprogram.h \
    glutils.h \
    mainview.h \
    scene.h \
    scenebasic.h \
    dialog.h \
    dialogeyes.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialogeyes.ui

win32: LIBS += -L$$PWD/./ -lglew32 -lopengl32 -lglu32

INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.
