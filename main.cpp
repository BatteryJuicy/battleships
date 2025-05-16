#include <iostream>
#include "UI/ui.h"

using namespace std;

int main()
{
    std::cout << "Hello world\n";

    Board b = Board(10);
    displayBoard(b);
}

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

void displayBoard(Board board)
{
    int size = board.getSize();

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            printCell(board.getCell(x, y));
            cout << " ";
        }
        cout << endl;
    }
}