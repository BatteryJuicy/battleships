#ifndef UTILS_H
#define UTILS_H

#include <cell.h>
#include <board.h>

/**
 * @brief prints the cell acording to its CellType
 * 
 * @param cell 
 */
void printCell(Cell cell);

/**
 * @brief Converts int to char
 * 
 * @param n must be between 0 and 25 (inclusive)
 * @return char that can range from 'A' to 'Z'
 */
char numToLetter(int n);

/**
 * @brief displays the board with letters and number to index each cell.
 * 
 * @param board a const reference to the board that will be displayed. 
 */
void displayBoard(const Board& board);
#endif