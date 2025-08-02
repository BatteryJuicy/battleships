#ifndef H_UTILS_H
#define H_UTILS_H

#include <GameController.h>

/**
 * @brief prints the cell acording to its CellType
 * 
 * @param cell 
 */
void printCell(Battleships::Cell cell);

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
void displayBoard(const Battleships::Board& board);

/**
 * @brief Prints the full board of the player including boarder cells.
 * 
 * @param p player reference
 */
void printBoard(Battleships::Player& p);
#endif