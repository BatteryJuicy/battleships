#include <stdexcept>
#include <vector>
#include <iostream>

#include <board.h>
#include <utils.h>

coord::coord(unsigned int x, unsigned int y) : x(x), y(y) {}

Board::Board(unsigned int _size_)
{

    if (_size_ > 26 || _size_ < 2)
    {
        throw std::invalid_argument("board size must be between 2 and 26");
    }

    size = _size_;

    //--------creating the border-------

    std::vector<std::vector<Cell>> border;
    border.reserve(4);

    //creating a temporary array to store the sizes of each of the 4 rows, to make the board (size+2)*(size+2)
    unsigned int s[4] = {size + 2, size, size, size + 2};

    for (int i = 0; i < 4; i++)
    {
        std::vector<Cell> row;
        row.reserve(s[i]);
        for (unsigned int j = 0; j < s[i]; j++)
        {
            row.emplace_back(Cell::CellType::BORDER);
        }
        border.push_back(std::move(row));
    }
    
    //---------creating the board----------

    //reserving space for each row + 2 borders above and bellow the board.
    board.reserve(size + 2);

    //adding the top border
    board.push_back(std::move(border[0]));

    for (unsigned int i = 0; i < size; i++)
    {
        std::vector<Cell> row;
        row.reserve(size + 2);

        //border cell at board index [i][0]
        row.push_back(std::move(border[1][i]));

        //creating and adding the board cells
        for (unsigned int j = 0; j < size; j++)
        {
            row.emplace_back(Cell::CellType::SEA);
        }
        
        //border cell at board index [i][size + 1] (at the right).
        row.push_back(std::move(border[2][i]));

        //adding the row to the board
        board.push_back(std::move(row));
    }
    //adding the bottom border
    board.push_back(std::move(border[3]));

}

const std::vector<std::vector<Cell>>& Board::getBoard() const
{
    return board;
}

unsigned int Board::getSize() const
{
    return size;
}

Cell& Board::getCell(coord c)
{
    c.x++;c.y++; //mapping coordinates to the main board ignoring the border cells

    if (c.x < 1 || c.x > board.size() || c.y < 1 || c.y > board.size()) {
        throw std::out_of_range("getCell: coordinates out of range");
    }

    return board[c.y][c.x];
}

const Cell& Board::getCell(coord c) const
{
    c.x++;c.y++; //mapping coordinates to the main board ignoring the border cells

    if (c.x < 1 || c.x > board.size() || c.y < 1 || c.y > board.size()) {
        throw std::out_of_range("getCell: coordinates out of range");
    }

    return board[c.y][c.x];
}