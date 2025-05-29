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

void Player::guessCell(coord c)
{
    Cell& cell = board.getCell(c);

    cell.setGuessed(true);
    
    //change cell state in the case of a hit
    if (cell.getType() == Cell::CellType::BOAT){
        cell.setHit(true);
    }
}
