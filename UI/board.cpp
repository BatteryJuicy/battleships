#include <iostream>

#include "board.h"

using namespace std;

//------------------------

void printCell(Cell cell)
{
    if (!cell.isGuessed()){
        cout << 'O';
        return;
    }

    if (cell.isHit()){
        cout << 'X';
    }
    else{
        cout << '-';
    }
}

//----------------------

Board::Board(int _size_) : size(_size_), board(_size_, std::vector<Cell>(_size_))
{
    
}

void Board::display() const
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printCell(board[i][j]);
            cout << " ";
        }
        cout << endl;
    }
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