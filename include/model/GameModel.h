#ifndef MODEL_H
#define MODEL_H

#include <player.h>
#include <ai.h>

class GameModel{
public:
    enum class Turn {PLAYER1, PLAYER2};
private:
    Player player1;
    Player player2;

    Turn currentTurn;
public:

    GameModel(unsigned int boardSize);

    Player& Player1();
    Player& Player2();

    void makeGuess(coord c);

};
#endif