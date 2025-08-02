#include <stdexcept>
#include <iostream>

#include <cell.h>

using namespace Battleships;

Cell::Cell() : guessed(false), hit(false), type(Cell::CellType::SEA) {}

Cell::Cell(CellType t) : guessed(false), hit(false), type(t) {}

bool Cell::isGuessed() const
{
    return guessed;
}
bool Cell::isHit() const
{
    return hit;
}
Cell::CellType Cell::getType() const 
{
    return type;
}

void Cell::setGuessed(bool guess_)
{
    guessed = guess_;
}
void Cell::setHit(bool hit_)
{
    hit = hit_;
}
void Cell::setType(Cell::CellType t)
{
    type = t;
}

std::string Cell::typeToString() const
{
    switch (type)
    {
    case CellType::BOAT:
        return "BOAT";
        break;
    case CellType::SEA:
        return "SEA";
        break;
    case CellType::BORDER:
        return "BORDER";
        break;
    default:
        throw std::logic_error("Unhandled CellType while converting to string.");
        break;
    }
}
