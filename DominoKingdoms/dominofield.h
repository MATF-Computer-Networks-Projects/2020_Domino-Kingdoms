#ifndef DOMINOFIELD_H
#define DOMINOFIELD_H

#include <domino.hpp>

class DominoField
{
public:
    DominoField();
    bool getIsEmpty();
    void setIsEmpty(bool);
    Domino* getDomino();
    void setDomino(Domino*);

private:
    bool m_isEmpty;
    Domino *m_domino;
};

#endif // DOMINOFIELD_H
