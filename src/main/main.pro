QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    accountantmainwindow.cpp \
    apply.cpp \
    database.cpp \
    department.cpp \
    edit_expanses.cpp \
    edit_expense.cpp \
    employeemainwindow.cpp \
    expenses.cpp \
    main.cpp \
    mainwindow.cpp \
    statement.cpp \
    user.cpp \

HEADERS += \
    accountantmainwindow.hpp \
    apply.hpp \
    database.hpp \
    department.hpp \
    edit_expanses.hpp \
    edit_expense.hpp \
    employeemainwindow.hpp \
    expenses.hpp \
    mainwindow.hpp \
    statement.hpp \
    user.hpp \

FORMS += \
    accountantmainwindow.ui \
    apply.ui \
    authForm.ui \
    edit_expanses.ui \
    edit_expense.ui \
    employeemainwindow.ui \
    mainwindow.ui \


CONFIG += c++11
