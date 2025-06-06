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

    /**
     * @brief Default constructorfor Cell object.
     * 
     * @note sets CellType::SEA.
     * 
     */
    Cell();

    /**
     * @brief Construct a new Cell object
     * 
     * @param t CellType of the cell
     */
    Cell(CellType t);

    //getters
    /**
     * @brief getter of hit 
     * 
     * @return hit member.
     * 
     * @note
     *  returns true if the cell has CellType::BOAT and is guessed.
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
    void setGuessed(bool guess);
    void setHit(bool hit);
    void setType(CellType t);
};
#endif