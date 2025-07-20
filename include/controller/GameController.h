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

        static void handleGuessButton(Fl_Widget* w, void* data);
    public:

        GameController(unsigned int boardSize, int wWidth, int wHeight);

        GameModel& getModel();
        GameView& getView();

        void run();

    };
}

#endif