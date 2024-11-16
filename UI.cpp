#include <iostream>
#include "headerFiles/UI.h"

using namespace std;

Board::Board(int size) : size(size) 
{
    board = new char*[size];
    for (int i = 0; i < size; i++)
    {
        board[i] = new char[size];
    }
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = 'O';
        }
    }
}

void Board::display() const
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}