#include <stdexcept>

#include <logic/controller.h>
#include <model/Cell.h>
#include <model/board.h>

namespace Controller{

    static Board* boardInstance = nullptr;

    void initBoard(int size)
    {
        if (boardInstance == nullptr){
            boardInstance = new Board(size);
        }
    }

    Board& getBoard()
    {
        if (boardInstance == nullptr){
            throw std::runtime_error("Board not initialized.");
        }
        else{
            return *boardInstance;
        }
    }

    void guess(int x, int y)
    {
        Board& board = getBoard();

        Cell& c = board.getCell(x, y);

        c.setGuessed(true);
        
        //change cell state in the case of a hit
        if (c.getType() == Cell::CellType::BOAT){
            c.setHit(true);
        }
    }
}
