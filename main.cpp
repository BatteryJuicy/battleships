#include <iostream>
#include "UI/ui.h"

using namespace std;
void displayBoard(Board board);

void printCell(Cell cell);

int main()
{
    try
    {
        Board b = Board(8);
        displayBoard(b);
    }
    catch(const invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

}