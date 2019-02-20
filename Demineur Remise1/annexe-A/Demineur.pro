TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += \
    board.h \
    player.h \
    time.h \
    rulesendgame.h \
    position.h \
    game.h \
    observable.h \
    observer.h
