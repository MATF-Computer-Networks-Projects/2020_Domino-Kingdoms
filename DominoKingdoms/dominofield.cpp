#include "dominofield.h"

DominoField::DominoField()
    : m_isEmpty(false), m_domino(nullptr)
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
