QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    accountantmainwindow.cpp \
    adminmainwindow.cpp \
    apply.cpp \
    database.cpp \
    department.cpp \
    edit_departments.cpp \
    edit_expanses.cpp \
    edit_expense.cpp \
    edit_user.cpp \
    employeemainwindow.cpp \
    expenses.cpp \
    main.cpp \
    mainwindow.cpp \
    statement.cpp \
    table_statements.cpp \
    user.cpp \

HEADERS += \
    accountantmainwindow.hpp \
    adminmainwindow.hpp \
    apply.hpp \
    database.hpp \
    department.hpp \
    edit_departments.hpp \
    edit_expanses.hpp \
    edit_expense.hpp \
    edit_user.hpp \
    employeemainwindow.hpp \
    expenses.hpp \
    mainwindow.hpp \
    statement.hpp \
    table_statements.hpp \
    user.hpp \

FORMS += \
    accountantmainwindow.ui \
    adminmainwindow.ui \
    apply.ui \
    authForm.ui \
    edit_departments.ui \
    edit_expanses.ui \
    edit_expense.ui \
    edit_user.ui \
    employeemainwindow.ui \
    mainwindow.ui \
    table_statements.ui


CONFIG += c++11

RESOURCES += \
    resources.qrc
