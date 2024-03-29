#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT+= core gui sql
QT+= sql
QT+= printsupport
QT+= core gui charts network multimediawidgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    DuMesengerConnectionDialog.cpp \
    arduino.cpp \
    employe.cpp \
    employee.cpp \
        main.cpp \
    connection.cpp \
    mainamine.cpp \
    mainwindow5.cpp \
    qcustomplot.cpp \
    widget5.cpp

HEADERS += \
    DuMesengerConnectionDialog.h \
    arduino.h \
    employe.h \
    employee.h \
    connection.h \
    mainamine.h \
    mainwindow5.h \
    qcustomplot.h \
    widget5.h

FORMS += \
        DuMesengerConnectionDialog.ui \
        employee.ui \
        mainamine.ui \
        mainwindow5.ui \
        widget5.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
