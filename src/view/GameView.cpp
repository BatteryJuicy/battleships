#include <GameView.h>

#include <FL/Fl_Box.H>

#include <iostream>

using namespace Battleships;

void GameView::createWindow(int width, int height)
{
    int screen_w = Fl::w();  // Full screen width
    int screen_h = Fl::h();  // Full screen height

    int x = (screen_w - width) / 2;
    int y = (screen_h - height) / 2;

    window = new Fl_Window(x, y, width, height, "BATTLESHIPS");

    // Create an invisible box to act as the resizable area
    Fl_Box* resizableDummy = new Fl_Box(0, 0, 1, 1);
    resizableDummy->hide();  // Don't want it to be seen

    // Set dummy as the resizable widget
    window->resizable(resizableDummy);
}

//CONTROLLER MUST PASS THE FUNCTIONS THE BUTTONS EXECUTE
void GameView::createBoards(unsigned int boardSize)
{
    //window dimentions
    int w = window->w();
    int h = window->h();

    //pixel size of each cell of each board
    const int cellSize = h/12;

    //padding for the edges of the window to place the board
    const int cellPadding = 5;
    const int boardPadding = 100;

    const int boardPixelSize = (cellSize+cellPadding)*(boardSize-1) + cellSize;

    const int horizontalPadding = (w - 2 * boardPixelSize - boardPadding) / 2;
    const int VerticalPadding = (h - boardPixelSize) / 2;

    //-----------opponent's board------------

    Fl_Group* opponentBoard_Group = new Fl_Group(
                                    horizontalPadding + boardPixelSize + boardPadding,
                                    VerticalPadding, 
                                    boardPixelSize,
                                    boardPixelSize
                                    );

    opponentBoard.reserve(boardSize);
    for (int i = 0; i < boardSize; i++)
    {
        std::vector<Fl_Button*> row;
        row.reserve(boardSize);

        for (int j = 0; j < boardSize; j++)
        {
            int x = opponentBoard_Group->x() + j*(cellSize + cellPadding);
            int y = opponentBoard_Group->y() + i*(cellSize + cellPadding) ;
            Fl_Button* b = new Fl_Button(x, y, cellSize, cellSize);

            row.push_back(b);
        }
        opponentBoard.push_back(row);
    }
    opponentBoard_Group->end();

    //--------player board---------
    
    Fl_Group* playerBoard_Group = new Fl_Group(
                                    horizontalPadding,
                                    VerticalPadding, 
                                    boardPixelSize,
                                    boardPixelSize
                                    );

    playerBoard.reserve(boardSize);
    for (int i = 0; i < boardSize; i++)
    {
        std::vector<Fl_Button*> row;
        row.reserve(boardSize);

        for (int j = 0; j < boardSize; j++)
        {
            int x = playerBoard_Group->x() + j*(cellSize + cellPadding);
            int y = playerBoard_Group->y() + i*(cellSize + cellPadding) ;
            Fl_Button* b = new Fl_Button(x, y, cellSize, cellSize);

            row.push_back(b);
        }
        playerBoard.push_back(row);
    }

    playerBoard_Group->end();
    
}

GameView::GameView(int width, int height, unsigned int boardSize) {
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

    for (int y = 0; y < board.getSize(); y++)
    {
        for (int x = 0; x < board.getSize(); x++)
        {
            Fl_Button* b = opponentBoard[y][x];
            Cell& c = board.getCell(Coord(x, y));

            if (c.isGuessed() == true){
                b->deactivate();
            }
            
            if (c.isHit() == true){
                b->color(FL_RED);
            }
            else{
                b->color(FL_GRAY);
            }
        }
        
    }
    
    
}