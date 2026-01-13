#include <GameView.h>
#include <BoardButton.h>
#include <config.h>

#include <iostream>

#include <FL/Fl_Box.H>

using namespace Battleships;

ImageLoadException::ImageLoadException(const std::string& msg) : std::runtime_error(msg) {}

void GameView::loadSprites()
{
    // sprites paths
    const unsigned int spriteCount = 4;
    std::string spriteFileEncoding = ".png";
    std::string spriteDir = "../assets/";
    std::string spriteNames[spriteCount] = {"cell_default", "cell_hit", "cell_miss", "cell_shipSank"};

    for (int i = 0; i < spriteCount; i++)
    {
        std::string fullPath = spriteDir + spriteNames[i] + spriteFileEncoding;
        Fl_PNG_Image getTemp(fullPath.c_str());

        if (getTemp.fail()) {
            throw ImageLoadException("FAIL: Could not load sprite: " + fullPath + ". Try reloading cmake.");
        }
        
        //adding the pair <spriteNames[i], Fl_image(<file path>)> to the sprites hashtable.
        buttonSprites[spriteNames[i]] = getTemp.copy(cellButtonSize, cellButtonSize);
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

            BoardButton* b = new BoardButton(x, y, cellButtonSize, cellButtonSize, buttonSprites["cell_default"]);
            row.push_back(b);
        }
        board.push_back(row);
    }
    group->end();
}

//CONTROLLER MUST PASS THE FUNCTIONS THE BUTTONS EXECUTE
void GameView::addBoards(unsigned int boardSize)
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

    //------------player board------------
    
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

    addBoards(boardSize);

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
                b->image(buttonSprites["cell_hit"]);
            }
            else{
                b->image(buttonSprites["cell_miss"]);
            }
        }
        
    }
    
    
}