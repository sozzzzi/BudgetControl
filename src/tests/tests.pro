QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS +=  ../main/user.hpp \
            ../main/expenses.hpp \
            ../main/statement.hpp

SOURCES +=  tst_test_bg.cpp \
            ../main/user.cpp \
            ../main/expenses.cpp \
            ../main/statement.cpp

