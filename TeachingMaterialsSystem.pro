#-------------------------------------------------
#
# Project created by QtCreator 2018-03-26T19:55:50
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TeachingMaterialsSystem
TEMPLATE = app


SOURCES += main.cpp\
        Logindialog.cpp \
    RegisterDialog.cpp \
    StudentManage.cpp \
    Automation.cpp \
    ElectricalAutomation.cpp \
    Information.cpp \
    Communication.cpp \
    ElectronicTechnology.cpp \
    StuPassWord.cpp \
    TAutomation.cpp \
    TCommunication.cpp \
    TElectricalautomation.cpp \
    TeaPassWord.cpp \
    TInformation.cpp \
    TElectronicTechnology.cpp \
    TeacherManage.cpp

HEADERS  += Logindialog.h \
    RegisterDialog.h \
    StudentManage.h \
    Automation.h \
    ElectricalAutomation.h \
    Information.h \
    Communication.h \
    ElectronicTechnology.h \
    StuPassWord.h \
    TAutomation.h \
    TCommunication.h \
    TElectricalautomation.h \
    TeaPassWord.h \
    TInformation.h \
    TElectronicTechnology.h \
    TeacherManage.h

FORMS    += \
    LoginDialog.ui \
    RegisterDialog.ui \
    StudentManage.ui \
    Automation.ui \
    ElectricalAutomation.ui \
    Information.ui \
    Communication.ui \
    ElectronicTechnology.ui \
    StuPassWord.ui \
    TAutomation.ui \
    TCommunication.ui \
    TElectricalautomation.ui \
    TeaPassWord.ui \
    TInformation.ui \
    TElectronicTechnology.ui \
    TeacherManage.ui

RESOURCES += \
    res/res.qrc
RC_FILE = logo.rc
