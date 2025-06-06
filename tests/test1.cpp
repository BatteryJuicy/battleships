#include <iostream>
#include <string>

#include <GameController.h>

using namespace Controller;

int main()
{
    GameController controller = GameController(8);

    Board& board = controller.getModel().Player1().getBoard();

    //PRINT BOARD WITH BORDER
    for (unsigned int i = 0; i < board.getBoard().size(); i++)
    {

        for (Cell c : board.getBoard()[i])
        {
            if (c.getType() == Cell::CellType::SEA){
                std::cout << "O";
            }
            else if(c.getType() == Cell::CellType::BOAT){
                std::cout << "A";
            }
            else{
                std::cout << "X";
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    std::cin.get();
}