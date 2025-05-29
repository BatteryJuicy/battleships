cmake_minimum_required(VERSION 3.5.0)
project(BattleShips VERSION 0.1.0 LANGUAGES C CXX)

# Recursively get all directories under include
file(GLOB_RECURSE ALL_INCLUDE_DIRS LIST_DIRECTORIES true
     "${PROJECT_SOURCE_DIR}/include/*")

# Filter only directories (optional safeguard)
set(INCLUDE_DIRS "")
foreach(dir ${ALL_INCLUDE_DIRS})
    if(IS_DIRECTORY ${dir})
        list(APPEND INCLUDE_DIRS ${dir})
    endif()
endforeach()

# Add them to the include path
include_directories(${INCLUDE_DIRS})


set(SOURCES 
    #model
    src/model/board.cpp
    src/model/cell.cpp
    src/model/GameModel.cpp
    src/model/player.cpp
    src/model/ship.cpp

    #controller
    src/controller/GameController.cpp

    #view
    src/view/GameView.cpp
    src/view/UI.cpp

    #util
    src/util/utils.cpp
)

#main application
add_executable(BattleShips ${SOURCES} src/main.cpp)

#tests
enable_testing()

add_executable(BattleShips_TEST ${SOURCES} tests/test1.cpp)

add_test(NAME BattleShips_TEST COMMAND BattleShips_TEST)