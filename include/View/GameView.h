#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <stdexcept>

#include <GameModel.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>

namespace Battleships{

/**
 * @brief Custom exception for when a sprite couldn't be loaded
 * 
 */
class ImageLoadException : public std::runtime_error {
public:
    ImageLoadException(const std::string& msg);
};

/**
 * @brief Button that behaves more interactively
 * 
 */
class BoardButton : public Fl_Button {
private:
    Fl_Image* normal_sprite;
    Fl_Image* hover_sprite;
    Fl_Image* click_sprite;
public:

    /**
     * @brief Constructs a custom board button for the Battleships game.
     *
     * The BoardButton extends the standard FLTK Fl_Button by supporting
     * custom dimming effects for different interaction states (normal,
     * hover, click). It can display a sprite and change its appearance
     * dynamically when the mouse interacts with it.
     *
     * @param X The x-coordinate (in pixels) of the button's top-left corner.
     * @param Y The y-coordinate (in pixels) of the button's top-left corner.
     * @param W The width of the button in pixels.
     * @param H The height of the button in pixels.
     */
    BoardButton(int X, int Y, int W, int H, Fl_Image* buttonSprite);

    int handle(int event) override;

    /**
     * @brief Creates a dimmed copy of an image.
     *
     * This function takes an FLTK image (e.g., Fl_PNG_Image) and applies
     * a brightness scaling factor to all pixels, producing a visually
     * darker (dimmed) version of the image. Transparency (alpha channel)
     * is preserved.
     *
     * @param src The source image to dim.
     * @param factor Brightness scaling factor in the range [0.0, 1.0].
     *        - 1.0 means no dimming (original image).
     *        - 0.5 means half brightness.
     *        - 0.0 would result in a fully black image.
     *
     * @return A new Fl_RGB_Image pointer containing the dimmed copy.
     *         The caller is responsible for managing the memory of the
     *         returned image (e.g., deleting it when no longer needed).
     */
    Fl_RGB_Image* BoardButton::makeDimmed(const Fl_PNG_Image* src, float factor);
};

/**
 * @brief Responsible for rendering the game interface and handling user interactions.
 *
 */
class GameView{
private:
    Fl_Window *window;
    std::vector<std::vector<Fl_Button*>> playerBoard; //player1 board
    std::vector<std::vector<Fl_Button*>> opponentBoard; //player2's board where player1 guesses.

    Fl_Image* buttonSprite_sea;
    Fl_Image* buttonSprite_miss;
    Fl_Image* buttonSprite_hit;
    Fl_Image* buttonSprite_sank;

    const int cellButtonSize;

    //UI creations helpers
    void loadSprites();
    void createWindow(int width, int height);
    void makeBoard(std::vector<std::vector<Fl_Button*>>& board, Fl_Group* group, unsigned int boardSize);
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