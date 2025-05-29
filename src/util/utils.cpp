#include <stdexcept>
#include <iostream>

#include <board.h>
#include <cell.h>

void printCell(Cell cell)
{
    //normal
    if (!cell.isGuessed()){
        std::cout << 'O';
        return;
    }
    //hit
    else if (cell.isHit()){
        std::cout << 'X';
    }
    //miss
    else{
        std::cout << '-';
    }
}

char numToLetter(int n)
{
    if(n >= 0 || n <= 25){
        return static_cast<char>('A' + n);
    }
    else{
        throw std::invalid_argument("Input must be between 0 and 25");
    }
}

void displayBoard(Board board)
{
    int size = board.getSize();

    //print letters above the board
    std::cout << "    ";
    for (int i = 0; i < size; i++)
    {
        std::cout << numToLetter(i) << " ";
    }
    std::cout << std::endl;

    for (int y = 0; y < size; y++)
    { 
        //print numbers left of the board
        //1. double digit 
        if(y >= 9){
            std::cout << y+1 << "  ";
        }
        //2. single digit. first space is to match up with the double digits
        else{
            std::cout << " " << y+1 << "  ";
        }
        //printing the board
        for (int x = 0; x < size; x++)
        {
            printCell(board.getCell(coord(x,y)));
            std::cout << " ";
        }
        //printing numbers on the right
        std::cout << "  " << y + 1;

        std::cout << std::endl;
    }

    //printing the letters at the bottom
    std::cout << "    ";
    for (int i = 0; i < size; i++)
    {
        std::cout << numToLetter(i) << " ";
    }
    std::cout << std::endl;
}

coord::coord(int x, int y) : x(x), y(y) {}