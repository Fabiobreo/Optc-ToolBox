QT       += core gui widgets
CONFIG += resources_big

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Optc
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

INCLUDEPATH += ./sources
INCLUDEPATH += ./sources/backend
INCLUDEPATH += ./sources/frontend
INCLUDEPATH += ./headers
INCLUDEPATH += ./headers/backend
INCLUDEPATH += ./headers/frontend
INCLUDEPATH += ./ui
INCLUDEPATH += ./resources

SOURCES += \
    sources/main.cpp \
    sources/frontend/details.cpp \
    sources/frontend/database.cpp \
    sources/frontend/optc.cpp \
    sources/frontend/mycharacterform.cpp \
    sources/frontend/socketselection.cpp \
    sources/frontend/characterItem.cpp \
    sources/frontend/loginform.cpp \
    sources/frontend/conditionWidget.cpp \
    sources/frontend/filterWidget.cpp \
    sources/backend/stats.cpp \
    sources/backend/enums.cpp \
    sources/backend/limitbreak.cpp \
    sources/backend/potential.cpp \
    sources/backend/special.cpp \
    sources/backend/socket.cpp \
    sources/backend/sailor.cpp \
    sources/backend/character.cpp \
    sources/backend/captain.cpp \
    sources/backend/mycharacter.cpp \
    sources/backend/parser.cpp \
    sources/backend/tools.cpp \
    sources/backend/material.cpp \
    sources/backend/tandem.cpp \
    sources/backend/filter.cpp \
    sources/frontend/advancedFilters.cpp \
    sources/frontend/sortwidget.cpp \
    sources/frontend/about.cpp \
    sources/frontend/donate.cpp

HEADERS += \
    headers/frontend/details.h \
    headers/frontend/database.h \
    headers/frontend/utility.h \
    headers/frontend/optc.h \
    headers/frontend/mycharacterform.h \
    headers/frontend/socketselection.h \
    headers/frontend/characterItem.h \
    headers/frontend/loginform.h \
    headers/frontend/conditionWidget.h \
    headers/frontend/filterWidget.h \
    headers/backend/stats.h \
    headers/backend/enums.h \
    headers/backend/limitbreak.h \
    headers/backend/potential.h \
    headers/backend/special.h \
    headers/backend/socket.h \
    headers/backend/sailor.h \
    headers/backend/character.h \
    headers/backend/captain.h \
    headers/backend/mycharacter.h \
    headers/backend/parser.h\
    headers/backend/tools.h \
    headers/backend/material.h \
    headers/backend/tandem.h \
    headers/backend/filter.h \
    headers/frontend/advancedFilters.h \
    headers/frontend/sortwidget.h \
    headers/frontend/about.h \
    headers/frontend/donate.h

FORMS += \
    ui/details.ui \
    ui/database.ui \
    ui/optc.ui \
    ui/mycharacterform.ui \
    ui/socketselection.ui \
    ui/loginform.ui \
    ui/conditionWidget.ui \
    ui/filterWidget.ui \
    ui/advancedFilters.ui \
    ui/sortwidget.ui \
    ui/about.ui \
    ui/donate.ui

RESOURCES += \
    resources/ui/resources.qrc
