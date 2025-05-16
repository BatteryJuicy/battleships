#include <iostream>
#include "headerFiles/UI.h"

using namespace std;

// int charToNum(char c)
// {
//     if(isalpha(static_cast<unsigned char>(c))){
//         return toupper(static_cast<unsigned char>(c)) - 'A';
//     }
//     else{
//         throw invalid_argument("Input must be a letter (A–Z or a–z).");
//     }
// }

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

//----------CELL----------
/* Cell::Cell() : guessed(false), hit(false)
{

}

bool Cell::isGuessed()
{
    return guessed;
}
bool Cell::isHit()
{
    return hit;
}
void Cell::setGuessed(bool guess_)
{
    guessed = guess_;
}
void Cell::setHit(bool hit_)
{
    hit = hit_;
}
Cell::CellType Cell::getType()
{
    return type;
}
void Cell::setType(Cell::CellType t)
{
    type = t;
} */

//----------BOARD----------

/* Board::Board(int _size_) : size(_size_), board(_size_, std::vector<Cell>(_size_))
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
} */