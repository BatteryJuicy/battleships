#ifndef VIEW_H
#define VIEW_H

#include <vector>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

class GameView{
private:
    Fl_Window *window;
    std::vector<std::vector<Fl_Button*>> playerboard; //player1 board
    std::vector<std::vector<Fl_Button*>> opponentBoard; //player2's board where player1 guesses.

    //UI creations helpers
    void createWindow(int width, int height);
    void createBoards(unsigned int boardSize);
public:

    GameView(int width, int height, unsigned int boardSize);

    std::vector<std::vector<Fl_Button*>>& getPlayerBoard();
    std::vector<std::vector<Fl_Button*>>& getOpponentBoard();

    void show();

    void updateBoard();

};
#endif