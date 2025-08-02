#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <GameView.h>
#include <GameModel.h>

namespace Battleships{
/**
* @brief Coordinates interactions between the game model and view, handling game flow and user input.
* 
*/
class GameController{
private:
    GameModel model;
    GameView view;
    
    /**
     * @brief handle button event on the oponent's board AKA the player guesses a cell.
     * 
     * @param w pointer to the widget that callbacks this function
     * @param data @ref CallBackData "CallBackData" defined in GameController.cpp
     */
    static void handleButton_guess(Fl_Widget* w, void* data);
    
    /**
     * @brief handle button event on the player's board when he places his ships.
     * 
     * @param w pointer to the widget that callbacks this function
     * @param data @ref CallBackData "CallBackData" defined in GameController.cpp
     */
    static void handleButton_placeShips(Fl_Widget* w, void* data);
public:

    GameController(unsigned int boardSize, int wWidth, int wHeight);

    /**
     * @brief Get the Model object
     * 
     * @return GameModel& 
     */
    GameModel& getModel();
    /**
     * @brief Get the View object
     * 
     * @return GameView& 
     */
    GameView& getView();

    void placeShips();

    void run();

};
}

#endif