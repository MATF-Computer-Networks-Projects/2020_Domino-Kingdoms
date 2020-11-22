#ifndef DOMINOFIELD_H
#define DOMINOFIELD_H

#include <domino.hpp>

class DominoField
{
public:
    DominoField(int, int, int, int);
    bool getIsEmpty();
    void setIsEmpty(bool);
    Domino* getDomino();
    void setDomino(Domino*);
    int getX1();
    int getY1();
    int getX2();
    int getY2();

private:
    bool m_isEmpty;
    Domino *m_domino;
    int m_X1;
    int m_Y1;
    int m_X2;
    int m_Y2;
};

#endif // DOMINOFIELD_H
