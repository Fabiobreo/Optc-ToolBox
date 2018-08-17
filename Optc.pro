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
    sources/backend/tools.cpp

HEADERS += \
    headers/frontend/details.h \
    headers/frontend/database.h \
    headers/frontend/optc.h \
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
    headers/backend/parser.h \
    headers/frontend/utility.h \
    headers/backend/tools.h \
    headers/backend/json.h

FORMS += \
    ui/details.ui \
    ui/database.ui \
    ui/optc.ui
