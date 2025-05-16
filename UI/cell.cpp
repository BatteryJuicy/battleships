#include "cell.h"

Cell::Cell() : guessed(false), hit(false)
{

}

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