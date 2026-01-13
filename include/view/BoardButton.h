#ifndef BOARDBUTTON_H
#define BOARDBUTTON_H

#include <FL/Fl_Button.H>
#include <FL/Fl_PNG_Image.H>

namespace Battleships
{
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

    /**
     * @brief Overrides default handle to change the buttong sprites depending click state and
     * wether the mosue hovers over the button.
     * 
     * @param event 
     * @return int 
     */
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
    Fl_RGB_Image* BoardButton::makeDimmedSprite(const Fl_PNG_Image* src, float factor);
};
}
#endif