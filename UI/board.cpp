#include <iostream>

#include "board.h"

using namespace std;

Board::Board(int _size_)
{
    if (_size_ > 26 || _size_ < 2)
    {
        throw invalid_argument("board size must be between 2 and 26");
    }
    size = _size_;
    board = std::vector<std::vector<Cell>>(size, std::vector<Cell>(size));
}

const std::vector<std::vector<Cell>>& Board::GetBoard() const
{
    return board;
}

int Board::getSize()
{
    return size;
}

void Board::guess(int x, int y)
{
    Cell c = board[y][x];

    c.setGuessed(true);
    
    if (c.getType() == Cell::CellType::BOAT){
        c.setHit(true);
    }
}