#include "headerFiles/UI.h"
#include <iostream>

int main()
{
    std::cout << "Hello world\n";

    Board b = Board(5);
    b.display();
}