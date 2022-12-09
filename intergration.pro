QT       += core gui sql multimedia multimediawidgets serialport charts printsupport axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
   #b Amine/DuMesengerConnectionDialog.cpp \
    #Amine/arduino.cpp \
 #   Amine/employe.cpp \
  #  Amine/employee.cpp \
   # Amine/mainwindow6.cpp \
    #Amine/qcustomplot.cpp \
    #Amine/widget5.cpp \
    Amine/DuMesengerConnectionDialog.cpp \
    Amine/arduino.cpp \
    Amine/employe.cpp \
    Amine/employee.cpp \
    Amine/mainamine.cpp \
   # Amine/qcustomplot.cpp \
    Amine/widget5.cpp \
    Dah/client.cpp \
    Dah/mainwindow7.cpp \
    equipement.cpp \
    exportexcelobjet.cpp \
    main3.cpp \
    mainwnourh.cpp \
    salle1/mainwindow.cpp \
    salle1/qcustomplot.cpp \
    salle1/salle.cpp \
    salle1/connection.cpp \
    salle1/ARDUINO/mainwindow1.cpp \
    societe/mainwindow2.cpp \
    societe/QrCode.cpp \
    societe/societe.cpp \
    widget.cpp

HEADERS += \
 #   Amine/DuMesengerConnectionDialog.h \
  #  Amine/arduino.h \
   # Amine/employe.h \
    #Amine/employee.h \
   # Amine/mainwindow6.h \
   # Amine/qcustomplot.h \
   # Amine/widget5.h \
    Amine/DuMesengerConnectionDialog.h \
    Amine/arduino.h \
    Amine/employe.h \
    Amine/employee.h \
    Amine/mainamine.h \
   # Amine/qcustomplot.h \
   # Amine/widget.h \
    Amine/widget5.h \
    Dah/client.h \
    Dah/mainwindow7.h \
    Dah/webaxwidget.h \
    equipement.h \
    exportexcelobjet.h \
    mainwnourh.h \
    salle1/qcustomplot.h \
    salle1/mainwindow.h \
    salle1/salle.h \
    salle1/connection.h \
    salle1/ARDUINO/mainwindow1.h \
    societe/mainwindow2.h \
    societe/QrCode.hpp \
    societe/societe.h \
    widget.h

FORMS += \
   # Amine/DuMesengerConnectionDialog.ui \
   # Amine/authentif.ui \
   # Amine/employee.ui \
   # Amine/mainwindow6.ui \
   # Amine/widget5.ui \
    Amine/DuMesengerConnectionDialog.ui \
    Amine/authentif.ui \
    Amine/employee.ui \
    Amine/mainamine.ui \
  #  Amine/widget.ui \
    Amine/widget5.ui \
    Dah/mainwindow7.ui \
    mainwnourh.ui \
    salle1/mainwindow.ui \
    salle1/ARDUINO/mainwindow1.ui \
    societe/mainwindow2.ui \
    widget.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    Amine/employee.pro \
    Dah/Atelier_Connexion.pro

DISTFILES += \
    Amine/Atelier_Connexion.pro.user \
    Amine/Atelier_Connexion.pro.user.d567f1b.4.8-pre1 \
    Amine/employee.pro.user \
    Amine/employee.pro.user.56740f0 \
    Amine/employee.pro.user.80fc153 \
    Amine/employee.pro.user.ddd801e \
    Dah/icon.ico \
    Dah/icon.png

RESOURCES += \
    Dah/imgs.qrc \
    Dah/res.qrc \
    Dah/resource.qrc


