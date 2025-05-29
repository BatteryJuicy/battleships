#include <player.h>
#include <board.h>

Player::Player(int size)
{
    initBoard(size);
}

void Player::initBoard(int size)
{
    board = Board(size);
}

Board& Player::getBoard()
{
    return board;
}

void Player::guessCell(int x, int y)
{
    Cell& c = board.getCell(x, y);

    c.setGuessed(true);
    
    //change cell state in the case of a hit
    if (c.getType() == Cell::CellType::BOAT){
        c.setHit(true);
    }
}
