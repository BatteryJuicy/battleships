#include <stdexcept>

#include <iostream>

#include <GameController.h>
#include <board.h>
#include <player.h>

struct CallBackData{
    Controller::GameController* controller;
    Coord* coord;

    CallBackData(Controller::GameController* c, Coord* _c) : controller(c), coord(_c) {}
};

void Controller::GameController::handleGuessButton(Fl_Widget* w, void* data)
{
    CallBackData* d = static_cast<CallBackData*>(data);
    Controller::GameController* c = d->controller;
    Coord* coords = d->coord;

    if (c->model.getTurn() == GameModel::Turn::PLAYER1){
        c->model.makeGuess(*coords);
    }   

}

Controller::GameController::GameController(unsigned int boardSize, int wWidth, int wHeight) 
    : model(boardSize), view(wWidth, wHeight, boardSize) 
{
    //initializing board button functions
    for (unsigned int i = 0; i < boardSize; i++)
    {
        for (unsigned int j = 0; j < boardSize; j++)
        {
            CallBackData* d = new CallBackData(this, new Coord(j, i));
            view.getOpponentBoard()[i][j]->callback(Controller::GameController::handleGuessButton, d);
        }
        
    }
    
}

GameModel& Controller::GameController::getModel()
{
    return model;
}

GameView& Controller::GameController::getView()
{
    return view;
}

void Controller::GameController::run()
{
    view.show();
    Fl::run();
}