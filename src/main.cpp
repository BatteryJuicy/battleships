#include <iostream>
#include <string>

#include <ui.h>

using namespace std;

int main()
{
    Board b = Board();

    //PRINT BOARD
    try
    {
        b = Board(8);
        displayBoard(b);
    }
    catch(invalid_argument& e)
    {
        cerr << e.what() << '\n';
    }

    //PRINT BOARD WITH BORDER
/*     for (int i = 0; i < b.getSize() + 2; i++)
    {

        for (Cell c : b1[i])
        {
            if (c.getType() == Cell::CellType::SEA){
                cout << "O";
            }
            else if(c.getType() == Cell::CellType::BOAT){
                cout << "A";
            }
            else{
                cout << "X";
            }
            cout << " ";
        }
        cout << endl;
    } */


}