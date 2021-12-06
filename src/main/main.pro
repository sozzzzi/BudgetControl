QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    accountantmainwindow.cpp \
    employeemainwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    user.cpp \

HEADERS += \
    accountantmainwindow.hpp \
    employeemainwindow.hpp \
    mainwindow.hpp \
    user.hpp \

FORMS += \
    accountantmainwindow.ui \
    auth.ui \
    employeemainwindow.ui \
    mainwindow.ui \


CONFIG += c++11
