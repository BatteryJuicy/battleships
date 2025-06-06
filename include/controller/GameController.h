#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <GameModel.h>
#include <GameView.h>

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