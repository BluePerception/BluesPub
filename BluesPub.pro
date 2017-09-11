#-------------------------------------------------
#
# Project created by QtCreator 2017-08-16T11:05:12
#
#-------------------------------------------------

QT       +=     core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BluesPub
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++0x

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    startcontroller.cpp \
    maincontroller.cpp \
    startview.cpp \
    controller.cpp \
    db_user.cpp \
    signinview.cpp \
    signincontroller.cpp \
    user.cpp \
    usercontroller.cpp \
    logincontroller.cpp \
    loginview.cpp \
    clientview.cpp \
    clientcontroller.cpp \
    clientvaluationview.cpp\
    clientvaluationcontroller.cpp\
    client.cpp \
    waiter.cpp \
    holder.cpp \
    holderview.cpp \
    waiterview.cpp \
    waitercontroller.cpp \
    holdercontroller.cpp \
    db_list.cpp \
    listitem.cpp \
    drink.cpp \
    food.cpp \
    utility.cpp \
    db_valuation.cpp \
    rate.cpp \
    dbxml.cpp \
    editusercontroller.cpp \
    edituserview.cpp \
    checker.cpp \
    table.cpp \
    total.cpp \
    order.cpp \
    db_table.cpp \
    listview.cpp \
    listcontroller.cpp \
    orderview.cpp \
    ordercontroller.cpp \
    totalview.cpp \
    totalcontroller.cpp \
    removewaiterview.cpp \
    removewaitercontroller.cpp \
    valuationview.cpp \
    valuationcontroller.cpp \
    holderlistview.cpp \
    holderlistcontroller.cpp \
    addlistitemview.cpp \
    addlistitemcontroller.cpp


HEADERS  += mainwindow.h \
    startcontroller.h \
    maincontroller.h \
    startview.h \
    controller.h \
    db_user.h \
    signinview.h \
    signincontroller.h \
    user.h \
    usercontroller.h \
    logincontroller.h \
    loginview.h \
    clientview.h \
    clientcontroller.h \
    clientvaluationview.h \
    clientvaluationcontroller.h \
    client.h \
    waiter.h \
    holder.h \
    holderview.h \
    waiterview.h \
    waitercontroller.h \
    holdercontroller.h \
    db_list.h \
    listitem.h \
    drink.h \
    food.h \
    utility.h \
    db_valuation.h \
    rate.h \
    dbxml.h \
    editusercontroller.h \
    edituserview.h \
    checker.h \
    table.h \
    total.h \
    order.h \
    db_table.h \
    listview.h \
    listcontroller.h \
    orderview.h \
    ordercontroller.h \
    totalview.h \
    totalcontroller.h \
    removewaiterview.h \
    removewaitercontroller.h \
    valuationview.h \
    valuationcontroller.h \
    holderlistview.h \
    holderlistcontroller.h \
    addlistitemview.h \
    addlistitemcontroller.h

FORMS    += mainwindow.ui \
    startview.ui \
    signinview.ui \
    loginview.ui \
    clientview.ui \
    clientvaluationview.ui \
    holderview.ui \
    waiterview.ui \
    edituserview.ui \
    listview.ui \
    orderview.ui \
    totalview.ui \
    removewaiterview.ui \
    valuationview.ui \
    holderlistview.ui \
    addlistitemview.ui

DISTFILES +=

RESOURCES += \
    images/copertina.qrc
