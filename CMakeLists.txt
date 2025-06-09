cmake_minimum_required(VERSION 3.10)
project(Battleships)

#set cmake version
set(CMAKE_CXX_STANDARD 17)

<<<<<<< HEAD
#add the FLTK dir so cmake can find it
add_subdirectory(external/fltk)

# Include headers
=======
#set(FLTK_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/fltk)
#set(FLTK_LIBRARIES ${PROJECT_SOURCE_DIR}/external/fltk/lib)

# Include directories
>>>>>>> 340a6ceb0fdde9c0c93765cdf60d94fa145395d1
include_directories(
    ${PROJECT_SOURCE_DIR}/include/controller
    ${PROJECT_SOURCE_DIR}/include/model
    ${PROJECT_SOURCE_DIR}/include/util
    ${PROJECT_SOURCE_DIR}/include/view
)
<<<<<<< HEAD
=======
include_directories(${FLTK_INCLUDE_DIR})

# Find FLTK
#find_package(FLTK REQUIRED)
>>>>>>> 340a6ceb0fdde9c0c93765cdf60d94fa145395d1

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

# Executable
add_executable(Battleships ${SOURCES})

# Link FLTK
#target_link_libraries(Battleships fltk)
