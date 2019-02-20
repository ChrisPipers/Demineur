TEMPLATE = app
TARGET = demineur
CONFIG += c++14
QT += core

CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++14 \
                    -pedantic-errors

SOURCES +=  \
    sources/model/board.cpp \
    sources/model/player.cpp \
    sources/model/position.cpp \
    sources/model/game.cpp \
    sources/main.cpp \
    sources/observer/observable.cpp \
    sources/observer/observer.cpp \
    sources/tests/positiontest.cpp \
    sources/tests/playertest.cpp \
    sources/tests/rulesendgametest.cpp \
    sources/tests/boardtest.cpp \
    sources/tests/timetest.cpp \
    sources/tests/gametest.cpp \
    sources/model/ruleendgame.cpp \
    sources/model/timeT.cpp

HEADERS += \
    headers/model/board.h \
    headers/model/game.h \
    headers/model/player.h \
    headers/model/position.h \
    headers/model/keyboard.hpp\
    headers/model/stringConvert.hpp\
    headers/observer/observable.h \
    headers/observer/observer.h \
    headers/tests/test.h \
    headers/tests/catch.hpp \
    headers/model/ruleendgame.h \
    headers/model/timeT.h

