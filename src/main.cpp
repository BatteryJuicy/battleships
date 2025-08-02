#include <iostream>
#include <string>

#include <utils.h>
#include <GameController.h>

int main()
{
    Battleships::GameController controller = Battleships::GameController(10, 1300, 600);

    displayBoard(controller.getModel().Player1().getBoard());
    displayBoard(controller.getModel().Player2().getBoard());

    controller.run();

    return 0;
}