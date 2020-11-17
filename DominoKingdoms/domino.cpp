#include "domino.hpp"
#include <cstdlib>
#include <iostream>

#include<QPainter>
#include<QPixmap>
#include<QPointF>
#include<QRectF>
#include<QString>

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

QString FieldType2QString(FieldType ft){
    switch (ft) {
    case FieldType::Forest:
        return QString(":/Images/Images/forest1.jpg");
    case FieldType::Meadow:
        return QString(":/Images/Images/meadow1.jpg");
    case FieldType::Quarry:
        return QString(":/Images/Images/quarry1.jpg");
    case FieldType::Water:
        return QString(":/Images/Images/sea1.jpg");
    case FieldType::Swamp:
        return QString(":/Images/Images/swamp1.jpg");
    case FieldType::Wheat:
        return QString(":/Images/Images/wheat1.jpg");
    }
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
//    if(!correctDominoPosition(m_xPos1,m_yPos1,m_xPos2,m_yPos2)){
//        throw "impossible domino";
//    }
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
    const QPointF qpf1 = QPointF(m_xPos1,m_yPos1);
    const QPointF qpf2 = QPointF(m_xPos2+100,m_yPos2+100);
    return QRectF(qpf1,qpf2);
}

void Domino::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QPixmap pm_1 = QPixmap(FieldType2QString(m_leftId));
    painter->drawPixmap(m_xPos1,m_yPos1,m_width,m_height,pm_1);
    QPixmap pm_2 = QPixmap(FieldType2QString(m_rightId));
    painter->drawPixmap(m_xPos2,m_yPos2,m_width,m_height,pm_2);
}
