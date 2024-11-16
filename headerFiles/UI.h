#ifndef UI_H
#define UI_H

class Board{
private:
    int size;
    char** board;
public:
    Board(int size);

    void display() const;
};
#endif