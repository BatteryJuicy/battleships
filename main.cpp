#include <iostream>
#include "UI/ui.h"

using namespace std;

int main()
{
    std::cout << "Hello world\n";

    Board b = Board(10);
    b.display();
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

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printCell(board.GetBoard()[i][j]);
            cout << " ";
        }
        cout << endl;
    }
}