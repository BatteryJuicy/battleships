#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <GameView.h>
#include <GameModel.h>

namespace Controller
{
    class GameController{
    private:
        GameModel model;
        GameView view;
    public:

        GameController(unsigned int boardSize);

        GameModel& getModel();
        GameView& getView();

    };
}

#endif