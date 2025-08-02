#ifndef VIEW_H
#define VIEW_H

#include <vector>

#include <GameModel.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>

namespace Battleships{
/**
 * @brief Responsible for rendering the game interface and handling user interactions.
 *
 */
class GameView{
private:
    Fl_Window *window;
    std::vector<std::vector<Fl_Button*>> playerBoard; //player1 board
    std::vector<std::vector<Fl_Button*>> opponentBoard; //player2's board where player1 guesses.

    Fl_PNG_Image* buttonSprite_sea;
    Fl_PNG_Image* buttonSprite_miss;
    Fl_PNG_Image* buttonSprite_hit;


    //UI creations helpers
    void createWindow(int width, int height);
    void createBoards(unsigned int boardSize);
public:

    GameView(int width, int height, unsigned int boardSize);

    std::vector<std::vector<Fl_Button*>>& getPlayerBoard();
    std::vector<std::vector<Fl_Button*>>& getOpponentBoard();

    void show();

    void updateBoard(GameModel& model);

};
}
#endif