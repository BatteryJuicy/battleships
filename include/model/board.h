#include <vector>

#ifndef BOARD_H
#define BOARD_H

#include "cell.h"
#include <utils.h>

/**
 * @brief A 2d vector array of Cell objects.
 * 
 */
class Board{
private:
    //the length of each side of the square board
    int size;

    //size * size 2D array (implemented with vectors)
    std::vector<std::vector<Cell>> board;
public:
    Board();

    Board(int size);

    /**
     * @brief Get a const reference to the board.
     * 
     * @return const std::vector<std::vector<Cell>>& 
     */
    const std::vector<std::vector<Cell>>& getBoard() const;

    /**
     * @brief Get the length of the board's side.
     * 
     * @return int board.size.
     */
    int getSize();
    
    /**
     * @brief Get the Cell object at board index (x,y).
     * 
     * @param coord object containing a point (x,y)
     * @return Cell& reference to the non-border cell at BOARD index (x,y).
     * @note (x,y) = (0,0) is mapped to (1,1) in the actual border matrix to skip the border cells.
     */
    Cell& getCell(coord c);
};
#endif