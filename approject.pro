QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    application.cpp \
    building.cpp \
    cattle.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    player.cpp \
    poultry.cpp \
    scoreboard.cpp \
    sheep_farm.cpp \
    signup.cpp \
    silo.cpp \
    warehouse.cpp

HEADERS += \
    application.h \
    building.h \
    cattle.h \
    login.h \
    mainwindow.h \
    map.h \
    player.h \
    poultry.h \
    scoreboard.h \
    sheep_farm.h \
    signup.h \
    silo.h \
    warehouse.h

FORMS += \
    cattle.ui \
    login.ui \
    mainwindow.ui \
    map.ui \
    poultry.ui \
    scoreboard.ui \
    sheep_farm.ui \
    signup.ui \
    silo.ui \
    warehouse.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    data.qrc

DISTFILES += \
    data.json
