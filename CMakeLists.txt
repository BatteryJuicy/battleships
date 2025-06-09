cmake_minimum_required(VERSION 3.10)
project(Battleships)

set(CMAKE_CXX_STANDARD 17)

set(FLTK_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/fltk)
set(FLTK_LIBRARIES ${PROJECT_SOURCE_DIR}/external/fltk/lib)

# Include directories
include_directories(include external)
include_directories(${FLTK_INCLUDE_DIRS})

# Find FLTK
find_package(FLTK REQUIRED)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Executable
add_executable(Battleships ${SOURCES})

# Link FLTK
target_link_libraries(Battleships fltk)
