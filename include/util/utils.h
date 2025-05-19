#ifndef UTILS_H
#define UTILS_H

#include <model/board.h>
#include<model/cell.h>

void printCell(Cell cell);

// A is 0 and Z is 25
char numToLetter(int n);

void displayBoard(Board board);
#endif