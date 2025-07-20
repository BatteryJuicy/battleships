#include <vector>

#ifndef BOARD_H
#define BOARD_H

#include "cell.h"

/**
 * @brief object to store x, y coordinates
 * 
 */
struct Coord{
    unsigned int x;
    unsigned int y;

    Coord(unsigned int x, unsigned int y);
};

/**
 * @brief A 2d vector array of Cell objects.
 * 
 */
class Board{
private:
    //the length of each side of the square board
    unsigned int size;

    //size X size 2D array to store the cells that make up the board.
    std::vector<std::vector<Cell>> board;
public:
    
    /**
     * @brief Construct a new Board object.
     * 
     * @param size the length of each side of the board.
     */
    Board(unsigned int size);

    /**
     * @brief Get a const reference to the board.
     * 
     * @return const std::vector<std::vector<Cell>>& 
     */
    const std::vector<std::vector<Cell>>& getBoard() const;

    /**
     * @brief get the size of the board.
     * 
     * @return unsigned int 
     */
    unsigned int getSize() const;
    
    /**
     * @brief Get the Cell object at board index (x,y).
     * 
     * @param coord object containing a point (x,y)
     * @return Cell& reference to the non-border cell at BOARD index (x,y).
     * @note (x,y) = (0,0) is mapped to (1,1) in the actual border matrix to skip the border cells.
     */
    Cell& getCell(Coord c);

    /**
     * @brief Get the Cell object at board index (x,y).
     * 
     * @param coord object containing a point (x,y)
     * @return const Cell& reference to the non-border cell at BOARD index (x,y).
     * @note (x,y) = (0,0) is mapped to (1,1) in the actual border matrix to skip the border cells.
     * @note Get's called by const Board& only.
     */
    const Cell& getCell(Coord c) const;
};
#endif