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
    default:
        return QString("field type not correct");
    }
}

QString Crowns2QString(int cr){
    switch (cr) {
    case 1:
        return QString(":/Images/Images/crowns-1.png");
    case 2:
        return QString(":/Images/Images/crowns-2.png");
    case 3:
        return QString(":/Images/Images/crowns-3.png");
    default:
        return QString("Incorrect number of crowns");
    }
}

Domino::Domino(int xPos1, int yPos1, int xPos2,int yPos2,
               int width, int height,
               int value, int crowns1, int crowns2,
               int reservedBy,bool currentlyCompatible, Board_Status boardStatus,
               FieldType ft1, FieldType ft2)
    : m_xPos1(xPos1), m_yPos1(yPos1), m_xPos2(xPos2), m_yPos2(yPos2),
      m_width(width), m_height(height),
      m_value(value), m_crowns1(crowns1), m_crowns2(crowns2),
      m_reservedBy(reservedBy), m_currentlyCompatible(currentlyCompatible),
      m_boardStatus(boardStatus), m_fieldType1(ft1), m_fieldType2(ft2)
{
//    if(!correctDominoPosition(m_xPos1,m_yPos1,m_xPos2,m_yPos2)){
//        throw "impossible domino";
//    }
}

Domino::Domino(int crowns1, int crowns2, FieldType fieldType1, FieldType fieldType2, int value):
      m_xPos1(0), m_yPos1(0), m_xPos2(0), m_yPos2(0),
      m_width(100), m_height(100),
      m_value(value), m_crowns1(crowns1), m_crowns2(crowns2),
      m_reservedBy(-1), m_currentlyCompatible(false),
      m_boardStatus(Board_Status::InDeck), m_fieldType1(fieldType1), m_fieldType2(fieldType2)
{

}

bool Domino::compatibleWith(Domino){
    // TODO
    return true;
}

int Domino::getXP1() const{
    return m_xPos1;
}

int Domino::getYP1() const{
    return m_yPos1;
}

int Domino::getXP2() const {
    return m_xPos2;
}

int Domino::getYP2() const{
    return m_yPos2;
}

int Domino::getValue(){
    return m_value;
}


void Domino::setCurrentlyCompatible(bool cc){
    m_currentlyCompatible = cc;
}

void Domino::rotate(){
    // 90 deg clockwise
}

int Domino::getCrowns2(){
    return m_crowns2;
}

int Domino::getCrowns1(){
    return m_crowns1;
}

int Domino::getReservedBy(){
    return m_reservedBy;
}

void Domino::setBoardStatus(Board_Status b){
    m_boardStatus = b;
}

int Domino::getWidth() const{
    return m_width;
}

int Domino::getHeight() const{
    return m_height;
}

void Domino::setWidth(int w){
    m_width = w;
}

void Domino::setHeight(int h){
    m_height = h;
}

FieldType Domino::getFieldType1() const{
    return m_fieldType1;
}

FieldType Domino::getFieldType2() const{
    return m_fieldType2;
}

QRectF Domino::boundingRect() const {
    QPointF qpf1 = QPointF(this->getXP1(),this->getYP1());
    QPointF qpf2 = QPointF(this->getXP2()+this->getWidth(),this->getYP2()+this->getHeight());
    return QRectF(qpf1,qpf2);
}

void Domino::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QPixmap pm_1 = QPixmap(FieldType2QString(this->getFieldType1()));
    painter->drawPixmap(this->getXP1(),this->getYP1(),this->getWidth(),this->getHeight(),pm_1);
    if(this->getCrowns1()>0){
        QPixmap pm_11 = QPixmap(Crowns2QString(this->getCrowns1()));
        painter->drawPixmap(this->getXP1(),this->getYP1(),this->getWidth(),this->getHeight(),pm_11);
    }

    QPixmap pm_2 = QPixmap(FieldType2QString(this->getFieldType2()));
    painter->drawPixmap(this->getXP2(),this->getYP2(),this->getWidth(),this->getHeight(),pm_2);
    if(this->getCrowns2()>0){
        QPixmap pm_12 = QPixmap(Crowns2QString(this->getCrowns2()));
        painter->drawPixmap(this->getXP2(),this->getYP2(),this->getWidth(),this->getHeight(),pm_12);
    }
}
