#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <model/board.h>

namespace Controller{

    /**
     * @brief Initializes the board.
     * 
     * @param size 
     */
    void initBoard(int size);

    /**
     * @brief Get the Board object
     * 
     * @return Board& 
     */
    Board& getBoard();

    /**
     * @brief Guesses the cell at BOARD index (x,y) and changes its member variables accordingly.
     * 
     * @param x 
     * @param y 
     */
    void guess(int x, int y);
}
#endif