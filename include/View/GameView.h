#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <unordered_map>
#include <stdexcept>

#include <GameModel.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

namespace Battleships
{
/**
 * @brief Custom exception for when a sprite couldn't be loaded
 * 
 */
class ImageLoadException : public std::runtime_error {
public:
    ImageLoadException(const std::string& msg);
};

/**
 * @brief Responsible for rendering the game interface and handling user interactions.
 *
 */
class GameView{
private:
    Fl_Window *window;
    // player1 board.
    std::vector<std::vector<Fl_Button*>> playerBoard;
    // player2's board where player1 guesses (doesn't store info about oponent's ships)
    std::vector<std::vector<Fl_Button*>> opponentBoard;

    /**
     * @brief HashTable that stores the button sprites and accesses them with key=<file name>.
     * 
     */
    std::unordered_map<std::string, Fl_Image*> buttonSprites;

    const int cellButtonSize;

    //UI creations helpers
    
    void loadSprites();
    void createWindow(int width, int height);
    void makeBoard(std::vector<std::vector<Fl_Button*>>& board, Fl_Group* group, unsigned int boardSize);
    void addBoards(unsigned int boardSize);
public:

    GameView(int width, int height, unsigned int boardSize);

    std::vector<std::vector<Fl_Button*>>& getPlayerBoard();
    std::vector<std::vector<Fl_Button*>>& getOpponentBoard();

    void show();

    void updateBoard(GameModel& model);

};
}
#endif