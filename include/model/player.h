#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

#include <board.h>
#include <ship.h>

class Player{
private:
    int ships_remaining;
    std::vector<Ship> ships;
    Board board;

public:

    /**
     * @brief Construct a new Player object
     * 
     * @param size the size of the board
     *
     */
    Player(unsigned int size);

    /**
     * @brief Get the Board object
     * 
     * @return Board& 
     */
    Board& getBoard();

    /**
     * @brief Applies the guess at the cell at BOARD index (x,y) and changes its member variables accordingly.
     * 
     * @param x 
     * @param y 
     */
    void applyGuess(Coord c);
};
#endif 