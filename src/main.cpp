#include <iostream>
#include <string>

#include <logic/controller.h>
#include <model/board.h>
#include <model/cell.h>
#include <util/utils.h>

using namespace std;

int main()
{
    Controller::initBoard(8);

    Board& board = Controller::getBoard();

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