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
     */
    Player(int size);

    /**
     * @brief initializes the board of the player.
     * 
     * @param size is the size of the board
     */
    void initBoard(int size);

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