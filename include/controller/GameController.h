#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <board.h>
#include <player.h>

#include <GameModel.h>
#include <GameView.h>

class GameController{
public:
    enum class Turn {PLAYER, AI};
private:
    GameModel model;
    GameView view;
public:

    Turn currentTurn;
};
#endif