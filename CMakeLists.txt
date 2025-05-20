cmake_minimum_required(VERSION 3.5.0)
project(BattleShips VERSION 0.1.0 LANGUAGES C CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(SOURCES 
    src/model/board.cpp
    src/model/cell.cpp
    src/util/utils.cpp
    src/logic/controller.cpp
)

#main application
add_executable(BattleShips ${SOURCES} src/main.cpp)

#tests
enable_testing()

add_executable(BattleShips_TEST ${SOURCES} tests/test1.cpp)

add_test(NAME BattleShips_TEST COMMAND BattleShips_TEST)