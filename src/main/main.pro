QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    accountantmainwindow.cpp \
    department.cpp \
    employeemainwindow.cpp \
    expenses.cpp \
    main.cpp \
    mainwindow.cpp \
    statement.cpp \
    user.cpp \

HEADERS += \
    accountantmainwindow.hpp \
    department.hpp \
    employeemainwindow.hpp \
    expenses.hpp \
    mainwindow.hpp \
    statement.hpp \
    user.hpp \

FORMS += \
    accountantmainwindow.ui \
    auth.ui \
    employeemainwindow.ui \
    mainwindow.ui \


CONFIG += c++11
