cmake_minimum_required(VERSION 3.10)
project(Battleships)

#set cmake version
set(CMAKE_CXX_STANDARD 17)

#add the FLTK dir so cmake can find it
add_subdirectory(external/fltk)

# Include headers
include_directories(
    ${PROJECT_SOURCE_DIR}/include/controller
    ${PROJECT_SOURCE_DIR}/include/model
    ${PROJECT_SOURCE_DIR}/include/util
    ${PROJECT_SOURCE_DIR}/include/view
)

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Executable
add_executable(Battleships ${SOURCES})

# Link FLTK
target_link_libraries(Battleships fltk)