QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    atributo.cpp \
    carta.cpp \
    deck.cpp \
    jogadorwidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    atributo.h \
    carta.h \
    deck.h \
    jogadorwidget.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Paises.csv

RESOURCES += \
    arquivos.qrc

# Add this line to disable resource compression for debugging
#QMAKE_RESOURCEDIR += $$PWD

# Add this line to copy the resource files to the build directory during debugging
#RESOURCES += $$QMAKE_RESOURCEDIR/arquivos.qrc
