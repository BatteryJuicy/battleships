#include <string>

#ifndef CELL_H
#define CELL_H

namespace Battleships{
/**
 * @brief Cell that makes up the board that can either be s ship, sea or border cell
 * 
 */
class Cell{
public:
    /**
     * @brief specifies the type of cell that determines the function of the cell.
     * 
     */
    enum class CellType {SEA, BOAT, BORDER};

    std::string typeToString() const;
private:
    bool guessed;
    bool hit;
    CellType type;
public:
    //default constructor

    /**
     * @brief Default constructor for Cell object.
     * 
     * @note sets CellType::SEA by default unless specified.
     */
    Cell();

    /**
     * @brief Construct a new Cell object
     * 
     * @param t @ref CellType "CellType" of the cell
     */
    Cell(CellType t);

    //getters
    /**
     * @brief getter of hit 
     * 
     * @return hit member.
     * 
     * @note returns true if the cell has CellType::BOAT and is guessed.
     */
    bool isHit() const;
    /**
     * @brief getter of guessed
     * 
     * @return true: if guessed through 
     * @return false 
     */
    bool isGuessed() const;

    /**
     * @brief Get the CellType
     * 
     * @return CellType of the cell
     */
    CellType getType() const;
    
    //setters
    /**
     * @brief Set the Guessed object
     * 
     * @param guess 
     */
    void setGuessed(bool guess);
    /**
     * @brief Set the Hit object
     * 
     * @param hit 
     */
    void setHit(bool hit);
    /**
     * @brief Set the Type object
     * 
     * @param t 
     */
    void setType(CellType t);
};
}
#endif