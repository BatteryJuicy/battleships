#include <iostream>
#include <string>

#include <utils.h>
#include <GameController.h>

using namespace Controller;

int main()
{
    GameController controller = GameController(8);

    displayBoard(controller.getModel().Player1().getBoard());
    displayBoard(controller.getModel().Player2().getBoard());
}