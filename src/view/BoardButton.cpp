#include <BoardButton.h>
#include <FL/Fl_Button.H>

using namespace Battleships;

BoardButton::BoardButton(int X, int Y, int W, int H, Fl_Image* buttonSprite)
    : Fl_Button(X, Y, W, H) 
{
    normal_sprite = buttonSprite;
    hover_sprite = makeDimmedSprite((const Fl_PNG_Image*)buttonSprite, 0.9f);
    click_sprite = makeDimmedSprite((const Fl_PNG_Image*)buttonSprite, 0.7f);

    this->box(FL_NO_BOX); // Remove the default button box
    this->take_focus(); // Prevent it from receiving keyboard focus
    this->clear_visible_focus(); // Disable the focus rectangle

    this->image(buttonSprite);
}

int BoardButton::handle(int event) 
{
    if (!this->active()) return 0;

    switch(event) {
        case FL_ENTER:      // mouse enters
            this->image(hover_sprite);
            redraw();
            break;
        case FL_LEAVE:      // mouse leaves
            this->image(normal_sprite);
            redraw();
            break;
        case FL_PUSH:       // mouse button pressed
            this->image(click_sprite);
            redraw();
            break;
        case FL_RELEASE:    //mouse button released
            this->image(normal_sprite);
            redraw();
            break;
    }
    return Fl_Button::handle(event);
}

Fl_RGB_Image* BoardButton::makeDimmedSprite(const Fl_PNG_Image* src, float factor) {
    // factor < 1.0 makes it darker (e.g. 0.5 = half brightness)

    int w = src->w();
    int h = src->h();
    int d = src->d();  // depth: 3 = RGB, 4 = RGBA

    // Copy pixel data from the source
    const uchar* srcData = (const uchar*)src->data()[0];
    int dataSize = w * h * d;
    uchar* newData = new uchar[dataSize];

    for (int i = 0; i < dataSize; i += d) {
        newData[i + 0] = (uchar)(srcData[i + 0] * factor); // R
        newData[i + 1] = (uchar)(srcData[i + 1] * factor); // G
        newData[i + 2] = (uchar)(srcData[i + 2] * factor); // B
        if (d == 4) {
            newData[i + 3] = srcData[i + 3]; // keep alpha unchanged
        }
    }

    return new Fl_RGB_Image(newData, w, h, d);
}