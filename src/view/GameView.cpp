#include <GameView.h>

#include <iostream>

#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_RGB_Image.H>

using namespace Battleships;

ImageLoadException::ImageLoadException(const std::string& msg) : std::runtime_error(msg) {}

//--------------BOARDBUTTON--------------

Fl_RGB_Image* BoardButton::makeDimmed(const Fl_PNG_Image* src, float factor) {
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

BoardButton::BoardButton(int X, int Y, int W, int H, Fl_Image* buttonSprite)
    : Fl_Button(X, Y, W, H) 
{
    normal_sprite = buttonSprite;
    hover_sprite = makeDimmed((const Fl_PNG_Image*)buttonSprite, 0.9f);
    click_sprite = makeDimmed((const Fl_PNG_Image*)buttonSprite, 0.7f);
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

//--------------GAMEVIEW--------------

//padding 
const int cellPadding = 5;
const int boardPadding = 100;

void GameView::loadSprites()
{
    const unsigned int spriteCount = 4;
    std::string spriteDir = "../assets/";
    std::string spriteNames[spriteCount] = {"cell_default.png", "cell_hit.png", "cell_miss.png", "cell_shipSank.png"};
    Fl_Image** images[spriteCount] = {
        &buttonSprite_sea,
        &buttonSprite_hit,
        &buttonSprite_miss,
        &buttonSprite_sank
    };

    for (int i = 0; i < spriteCount; i++)
    {
        std::string fullPath = spriteDir + spriteNames[i];
        Fl_PNG_Image getTemp(fullPath.c_str());

        if (getTemp.fail()) {
            throw ImageLoadException("FAIL: Could not load sprite: " + fullPath + ". Try reloading cmake.");
        }
        
        *images[i] = getTemp.copy(cellButtonSize, cellButtonSize);
    }
    
}

void GameView::createWindow(int width, int height)
{
    int screen_w = Fl::w();  // Full screen width
    int screen_h = Fl::h();  // Full screen height

    int x = (screen_w - width) / 2;
    int y = (screen_h - height) / 2;

    window = new Fl_Window(x, y, width, height, "BATTLESHIPS");

    window->color(FL_DARK3);

    // // Create an invisible box to act as the resizable area
    // Fl_Box* resizableDummy = new Fl_Box(0, 0, 1, 1);
    // resizableDummy->hide();  // Don't want it to be seen

    // // Set dummy as the resizable widget
    // window->resizable(resizableDummy);
}

void GameView::makeBoard(std::vector<std::vector<Fl_Button*>>& board, Fl_Group* group, unsigned int boardSize)
{
    board.reserve(boardSize);
    for (unsigned int i = 0; i < boardSize; i++)
    {
        std::vector<Fl_Button*> row;
        row.reserve(boardSize);

        for (unsigned int j = 0; j < boardSize; j++)
        {
            int x = group->x() + j*(cellButtonSize + cellPadding);
            int y = group->y() + i*(cellButtonSize + cellPadding);

            BoardButton* b = new BoardButton(x, y, cellButtonSize, cellButtonSize, buttonSprite_sea);
            b->box(FL_NO_BOX); // Remove the default button box
            b->take_focus(); // Prevent it from receiving keyboard focus
            b->clear_visible_focus(); // Disable the focus rectangle

            b->image(buttonSprite_sea);

            row.push_back(b);
        }
        board.push_back(row);
    }
    group->end();
}

//CONTROLLER MUST PASS THE FUNCTIONS THE BUTTONS EXECUTE
void GameView::createBoards(unsigned int boardSize)
{
    //window dimentions
    int w = window->w();
    int h = window->h();

    const int boardPixelSize = (cellButtonSize+cellPadding)*(boardSize-1) + cellButtonSize;

    //padding for the edges of the window to place the board
    const int horizontalPadding = (w - 2 * boardPixelSize - boardPadding) / 2;
    const int VerticalPadding = (h - boardPixelSize) / 2;

    //-----------opponent's board------------

    Fl_Group* opponentBoard_Group = new Fl_Group(
                                    horizontalPadding + boardPixelSize + boardPadding,
                                    VerticalPadding, 
                                    boardPixelSize,
                                    boardPixelSize
    );
    
    makeBoard(opponentBoard, opponentBoard_Group, boardSize);

    //--------player board---------
    
    Fl_Group* playerBoard_Group = new Fl_Group(
                                    horizontalPadding,
                                    VerticalPadding, 
                                    boardPixelSize,
                                    boardPixelSize
    );

    makeBoard(playerBoard, playerBoard_Group, boardSize);
    
}

GameView::GameView(int width, int height, unsigned int boardSize) : cellButtonSize(height/12) {

    try
    {
        loadSprites();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::exit(1);
    }
    
    createWindow(width, height);

    createBoards(boardSize);

    window->end();
}

std::vector<std::vector<Fl_Button*>>& GameView::getPlayerBoard()
{
    return playerBoard;
}
std::vector<std::vector<Fl_Button*>>& GameView::getOpponentBoard()
{ 
    return opponentBoard;
}

void GameView::show()
{
    window->show();
}

void GameView::updateBoard(GameModel& model)
{
    Player& player = (model.getTurn() == GameModel::Turn::PLAYER1) 
                        ? model.Player1() 
                        : model.Player2();

    Board& board = player.getBoard();

    for (Ship& s : player.getShips())
    {
        //if ship is shunken mark the cells differently
    }

    for (unsigned int y = 0; y < board.getSize(); y++)
    {
        for (unsigned int x = 0; x < board.getSize(); x++)
        {
            Fl_Button* b = opponentBoard[y][x];
            Cell& c = board.getCell(Coord(x, y));

            if (c.isGuessed() == true){
                b->deactivate();
            }
            
            if (c.isHit() == true){
                b->image(buttonSprite_hit);
            }
            else{
                b->image(buttonSprite_miss);
            }
        }
        
    }
    
    
}