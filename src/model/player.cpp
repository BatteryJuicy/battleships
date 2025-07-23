#include <player.h>
#include <board.h>

Player::Player(unsigned int size) : board(size) {}

Board& Player::getBoard()
{
    return board;
}

void Player::applyGuess(Coord c)
{
    Cell& cell = board.getCell(c);

    cell.setGuessed(true);
    
    //change cell state in the case of a hit
    if (cell.getType() == Cell::CellType::BOAT){
        cell.setHit(true);
    }
}

std::vector<Ship>& Player::getShips()
{
    return ships;
}
