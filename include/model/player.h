#ifndef PLAYER_H
#define PLAYER_H

#include <ship.h>

class Player{
private:
    int ships_remaining;
    std::vector<Ship> ships;
    Board board;

public:

    Player(int size);

    /**
     * @brief Get the Board object
     * 
     * @return Board& 
     */
    Board& getBoard();

    /**
     * @brief Guesses the cell at BOARD index (x,y) and changes its member variables accordingly.
     * 
     * @param x 
     * @param y 
     */
    void guessCell(int x, int y);
};
#endif 