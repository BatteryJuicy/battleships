#include <GameView.h>

#include <iostream>

void GameView::createWindow(int width, int height)
{
    int screen_w = Fl::w();  // Full screen width
    int screen_h = Fl::h();  // Full screen height

    int x = (screen_w - width) / 2;
    int y = (screen_h - height) / 2;

    window = new Fl_Window(x, y, width, height, "BATTLESHIPS");
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
    
    
}

GameView::GameView(int width, int height, unsigned int boardSize) {
    createWindow(width, height);

    createBoards(boardSize);

    window->end();
}

std::vector<std::vector<Fl_Button*>>& GameView::getPlayerBoard()
{
    return playerboard;
}
std::vector<std::vector<Fl_Button*>>& GameView::getOpponentBoard()
{
    return opponentBoard;
}

void GameView::show()
{
    window->show();
}