#include <vector>

#ifndef UI_H
#define UI_H

class Cell{
public:
    enum class CellType {SEA, BOAT};

private:
    bool guessed;
    bool hit;
    CellType type;
public:
    Cell();

    //getters
    bool isHit();
    bool isGuessed();
    CellType getType();
    //setters
    void setGuessed(bool guess);
    void setHit(bool hit);
    void setType(CellType t);
};

class Board{
private:
    int size;
    std::vector<std::vector<Cell>>  board;
public:
    Board(int size);

    void display() const;

    const std::vector<std::vector<Cell>>& GetBoard() const;

    int getSize();

    void guess(int, int);
};
#endif