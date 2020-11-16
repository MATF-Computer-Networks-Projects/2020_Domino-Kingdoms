#include "domino.hpp"
#include <cstdlib>
#include <iostream>

#include<QPainter>
#include<QPixmap>

bool correctDominoPosition(int x1, int y1, int x2, int y2){
    if(x1 == x2){
        if(abs(y1-y2)>1 || y1 == y2){
            std::cerr<<"Bad domino coordinates"<<std::endl;
            return false;
        }
    }
    if(y1 == y2){
        if(abs(x1-x2)>1 || x1 == x2){
            std::cerr<<"Bad domino coordinates\n";
            return false;
        }
    }
    if(x1 != x2 && y1 != y2){
        return false;
    }
    return true;
}

Domino::Domino(int xPos1, int yPos1, int xPos2,int yPos2,
               int width, int height,
               int value, int crownsLeft, int crownsRight,
               int reservedBy,bool currentlyCompatible, Board_Status boardStatus,
               FieldType leftId, FieldType rightId)
    : m_xPos1(xPos1), m_yPos1(yPos1), m_xPos2(xPos2), m_yPos2(yPos2),
      m_width(width), m_height(height),
      m_value(value), m_crownsLeft(crownsLeft), m_crownsRight(crownsRight),
      m_reservedBy(reservedBy), m_currentlyCompatible(currentlyCompatible),
      m_boardStatus(boardStatus), m_leftId(leftId), m_rightId(rightId)
{
    if(!correctDominoPosition(m_xPos1,m_yPos1,m_xPos2,m_yPos2)){
        throw "impossible domino";
    }
}

bool Domino::compatibleWith(Domino){
    // TODO
    return true;
}

void Domino::rotate(){
    // 90 deg clockwise
}

int Domino::getCrownsRight(){
    return m_crownsRight;
}

int Domino::getCrownsLeft(){
    return m_crownsLeft;
}

int Domino::getReservedBy(){
    return m_reservedBy;
}

void Domino::setBoardStatus(Board_Status b){
    m_boardStatus = b;
}

QRectF Domino::boundingRect() const {
    return QRectF(0,0,m_width,m_height);
}

void Domino::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QPixmap pm_1 = QPixmap(":/Images/Images/forest1.jpg");
    painter->drawPixmap(0,0,m_width/2,m_height,pm_1);
    QPixmap pm_2 = QPixmap(":/Images/Images/quarry1.jpg");
    painter->drawPixmap(m_width/2,0,m_width/2,m_height,pm_2);
}
