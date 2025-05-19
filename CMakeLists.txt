cmake_minimum_required(VERSION 3.5.0)
project(BattleShips VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES 
    src/main.cpp
    src/model/board.cpp
    src/model/cell.cpp
    src/util/utils.cpp
)

add_executable(BattleShips ${SOURCES})

