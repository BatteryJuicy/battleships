
#include <GameModel.h>

GameModel::GameModel(unsigned int boardSize) : player1(boardSize), player2(boardSize) {}

void GameModel::makeGuess(coord c)
{
    Player& target = (currentTurn == GameModel::Turn::PLAYER1) ? player2 : player1;

    target.applyGuess(c);
}

Player& GameModel::Player1()
{
    return player1;
}
Player& GameModel::Player2()
{
    return player2;
}