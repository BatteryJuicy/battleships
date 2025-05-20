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
     * @brief Construct a new Cell object  with CellType::SEA.
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
     * @return true: if the cell has CellType::BOAT and is guessed (hit)
     * @return false: if the cell has CellType::SEA and is guessed (miss)
     */
    bool isHit();
    /**
     * @brief getter of guessed
     * 
     * @return true: if guessed through 
     * @return false 
     */
    bool isGuessed();

    /**
     * @brief Get the CellType
     * 
     * @return CellType of the cell
     */
    CellType getType();
    
    //setters
    void setGuessed(bool guess);
    void setHit(bool hit);
    void setType(CellType t);
};
#endif