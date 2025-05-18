#ifndef UI_H
#define UI_H

#include "Cell.h"
#include "Board.h"

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

// A is 0 and Z is 25
char numToLetter(int n)
{
    if(n >= 0 || n <= 25){
        return static_cast<char>('A' + n);
    }
    else{
        throw invalid_argument("Input must be between 0 and 25");
    }
}

void displayBoard(Board board)
{
    int size = board.getSize();

    cout << "    ";
    for (int i = 0; i < size; i++)
    {
        cout << numToLetter(i) << " ";
    }
    cout << endl;

    for (int y = 0; y < size; y++)
    { 
        if(y >= 9){
            cout << y+1 << "  ";
        }
        else{
            cout << " " << y+1 << "  ";
        }

        for (int x = 0; x < size; x++)
        {
            printCell(board.getCell(x, y));
            cout << " ";
        }
        cout << "  " << y + 1;

        cout << endl;
    }

    cout << "    ";
    for (int i = 0; i < size; i++)
    {
        cout << numToLetter(i) << " ";
    }
    cout << endl;
}

#endif