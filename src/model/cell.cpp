#include <stdexcept>
#include <iostream>

#include <cell.h>

Cell::Cell() : guessed(false), hit(false), type(Cell::CellType::SEA) {}

Cell::Cell(CellType t) : guessed(false), hit(false), type(t) {}

bool Cell::isGuessed()
{
    return guessed;
}
bool Cell::isHit()
{
    return hit;
}
void Cell::setGuessed(bool guess_)
{
    guessed = guess_;
}
void Cell::setHit(bool hit_)
{
    hit = hit_;
}
Cell::CellType Cell::getType()
{
    return type;
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
