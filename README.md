# Battleships

## Overview

#### This is a simple GUI PvE game of Battleships with two modes:

1. **Easy**

   - The computer uses simple algorithms to place and guess ships.

2. **Hard**

   - Neuroevolution-based AI.

## Implementation

- MVC design architecture  
- FLTK GUI  
- Neuroevolution AI model

## Build

To build and run the game:
    
1. Make sure cmake is installed in your system.
    
2. Move to the parent directory and create a build folder.

3. Inside the build folder run the command
    ```bash
    cmake ..
    ```
This tells CMake to find the `CMakeLists.txt` file which specifies how to build the game.

4. Run the command
    ```bash
    make
    ```
And wait for everything to get built. The executable should appear in the build folder.

## Modules

- [FLTK](https://www.fltk.org)
- [pybind11](https://github.com/pybind/pybind11)
- [NEAT-python](https://neat-python.readthedocs.io/en/latest)

## Author

Andreas Thanopoulos