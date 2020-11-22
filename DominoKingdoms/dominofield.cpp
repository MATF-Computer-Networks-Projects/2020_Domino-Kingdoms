#include "dominofield.h"

DominoField::DominoField(int X1, int Y1, int X2, int Y2)
    : m_isEmpty(true), m_domino(nullptr), m_X1(X1), m_Y1(Y1), m_X2(X2), m_Y2(Y2)
{}

bool DominoField::getIsEmpty(){
    return m_isEmpty;
}

void DominoField::setIsEmpty(bool value){
    m_isEmpty = value;
}

Domino* DominoField::getDomino(){
    return m_domino;
}

void DominoField::setDomino(Domino *domino){
    m_domino = domino;
}

int DominoField::getX1(){
    return m_X1;
}

int DominoField::getY1(){
    return m_Y1;
}

int DominoField::getX2(){
    return m_X2;
}

int DominoField::getY2(){
    return m_Y2;
}
