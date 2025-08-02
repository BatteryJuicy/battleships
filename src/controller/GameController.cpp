#include <stdexcept>

#include <iostream>

#include <GameController.h>
#include <board.h>
#include <player.h>

using namespace Battleships;

namespace {
/**
 * @brief a struct for the purpose of passing \c this to a static function.
 * 
 */
struct CallBackData{
    GameController* controller;
    Coord coord;

    CallBackData(GameController* c, Coord _c) : controller(c), coord(_c) {}
};
}

void GameController::handleButton_guess(Fl_Widget* w, void* data)
{
    //retrieving the data
    CallBackData* d = static_cast<CallBackData*>(data);
    GameController* c = d->controller;
    Coord coords = d->coord;

    if (c->model.getTurn() == GameModel::Turn::PLAYER1){
        c->model.makeGuess(coords);
        c->view.updateBoard(c->getModel());
    }   

}

GameController::GameController(unsigned int boardSize, int wWidth, int wHeight) 
    : model(boardSize), view(wWidth, wHeight, boardSize) 
{
    //initializing board button functions
    for (unsigned int i = 0; i < boardSize; i++)
    {
        for (unsigned int j = 0; j < boardSize; j++)
        {
            CallBackData* d = new CallBackData(this, Coord(j, i));
            view.getOpponentBoard()[i][j]->callback(GameController::handleButton_guess, d);
        }
        
    }
    
}

GameModel& GameController::getModel()
{
    return model;
}

GameView& GameController::getView()
{
    return view;
}

void GameController::run()
{
    view.show();
    Fl::run();
}