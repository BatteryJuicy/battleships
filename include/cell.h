#include <string>

#ifndef CELL_H
#define CELL_H

class Cell{
public:
    enum class CellType {SEA, BOAT, BORDER};

    std::string typeToString() const;
private:
    bool guessed;
    bool hit;
    CellType type;
public:
    //default constructor
    Cell();

    Cell(CellType t);

    //getters
    bool isHit();
    bool isGuessed();
    CellType getType();
    //setters
    void setGuessed(bool guess);
    void setHit(bool hit);
    void setType(CellType t);
};
#endif