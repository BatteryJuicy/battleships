#include <stdexcept>

#include <GameController.h>
#include <board.h>
#include <player.h>

Controller::GameController::GameController(unsigned int boardSize) : model(boardSize), view() {}

GameModel& Controller::GameController::getModel()
{
    return model;
}

GameView& Controller::GameController::getView()
{
    return view;
}