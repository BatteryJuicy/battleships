
#include <GameModel.h>

#include <iostream>

using namespace Battleships;

GameModel::GameModel(unsigned int boardSize) : player1(boardSize), player2(boardSize), currentTurn(GameModel::Turn::PLAYER1) {}

void GameModel::makeGuess(Coord c)
{
    Player& target = (currentTurn == GameModel::Turn::PLAYER1) ? player2 : player1;

    target.applyGuess(c);

    //std::cout << "player" << ((currentTurn == GameModel::Turn::PLAYER1) ? "1 " : "2 ") << "guessed" << c.x << " " << c.y << std::endl;

    currentTurn = (currentTurn == GameModel::Turn::PLAYER1) ? GameModel::Turn::PLAYER2 : GameModel::Turn::PLAYER1;
}

Player& GameModel::Player1()
{
    return player1;
}
Player& GameModel::Player2()
{
    return player2;
}

GameModel::Turn GameModel::getTurn()
{
    return currentTurn;
}