QT += core gui

QT += widgets

TARGET += demineur
TEMPLATE += app

SOURCES +=  \
    sources/model/board.cpp \
    sources/model/player.cpp \
    sources/model/position.cpp \
    sources/model/game.cpp \
    sources/model/ruleendgame.cpp \
    sources/model/timeT.cpp \
    sources/main.cpp \
    sources/observer/observable.cpp \
    sources/observer/observer.cpp\
    sources/tests/positiontest.cpp \
    sources/tests/playertest.cpp \
    sources/tests/rulesendgametest.cpp \
    sources/tests/boardtest.cpp \
    sources/tests/timetest.cpp \
    sources/tests/gametest.cpp \
    sources/views/viewcase.cpp \
    sources/views/viewboard.cpp \
    sources/views/viewmainwindow.cpp \
    sources/views/viewparameter.cpp \
    sources/views/viewendgame.cpp \
    sources/views/viewstart.cpp


HEADERS += \
    headers/model/board.h \
    headers/model/game.h \
    headers/model/player.h \
    headers/model/position.h \
    headers/model/keyboard.hpp\
    headers/model/stringConvert.hpp\
    headers/model/ruleendgame.h \
    headers/model/timeT.h \
    headers/observer/observable.h \
    headers/observer/observer.h \
    headers/tests/test.h \
    headers/tests/catch.hpp \
    headers/views/viewcase.h \
    headers/views/viewboard.h \
    headers/views/viewmainwindow.h \
    headers/views/viewparameter.h \
    headers/views/viewendgame.h \
    headers/views/viewstart.h

RESOURCES += \
    images/bomb.png\
    images/flag.png\


