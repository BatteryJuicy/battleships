#include <iostream>
#include <string>

#include <utils.h>
#include <GameController.h>

using namespace Controller;

int main()
{
    GameController controller = GameController(8, 1200, 600);

    displayBoard(controller.getModel().Player1().getBoard());
    displayBoard(controller.getModel().Player2().getBoard());

    controller.run();

    return 0;
}