#include <vector>

#include "cell.h"

#ifndef BOARD_H
#define BOARD_H

class Board{
private:
    int size;
    std::vector<std::vector<Cell>> board;
public:
    Board(int size);

    //getters
    const std::vector<std::vector<Cell>>& GetBoard() const;
    Cell getCell(int x, int y);
    int getSize();

    void guess(int, int);
};
#endif