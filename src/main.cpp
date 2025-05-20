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

}