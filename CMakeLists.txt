cmake_minimum_required(VERSION 3.5.0)
project(BattleShips VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCES 
    main.cpp
    UI/board.cpp
    UI/cell.cpp
)

add_executable(BattleShips ${SOURCES})

