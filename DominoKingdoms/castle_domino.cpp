#include<QPointF>
#include<QRectF>
#include<QPixmap>
#include<QPainter>
#include<QString>
#include "castle_domino.hpp"

CastleDomino::CastleDomino(int pid){
    this->setXP(300);
    this->setYP(300);
    this->setWidth(150);
    this->setHeight(150);
    this->setCurrentlyCompatible(false);
    this->setPID(pid);
}

QRectF CastleDomino::boundingRect() const
{
    QPointF pointTopLeft = QPointF(this->getXP(),this->getYP());
    QPointF pointBottomRight = QPointF(this->getXP()+this->getWidth(),
                                       this->getYP()+this->getHeight());

    return QRectF(pointTopLeft,pointBottomRight);
}

void CastleDomino::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pm = QPixmap(this->playerId2QString(this->getPID()));
    painter->drawPixmap(this->getXP(),this->getYP(),this->getWidth(),this->getHeight(),pm);
}

int CastleDomino::getXP() const
{
    return m_xPos;
}

int CastleDomino::getYP() const
{
    return m_yPos;
}

int CastleDomino::getWidth() const
{
    return m_width;
}

int CastleDomino::getHeight() const
{
    return m_height;
}

int CastleDomino::getPID() const
{
    return m_pid;
}

void CastleDomino::setCurrentlyCompatible(bool b)
{
    m_currentlyCompatible = b;
}

void CastleDomino::setWidth(int w)
{
    m_width = w;
}

void CastleDomino::setHeight(int h)
{
    m_height = h;
}

void CastleDomino::setXP(int x)
{
    m_xPos = x;
}

void CastleDomino::setYP(int y)
{
    m_yPos = y;
}

void CastleDomino::setPID(int pid)
{
    m_pid = pid;
}

QString CastleDomino::playerId2QString(int pid){
    switch (pid) {
    case 1:
        return QString(":/Images/Images/castle-1.jpg");
    case 2:
        return QString(":/Images/Images/castle-2.jpg");
    case 3:
        return QString(":/Images/Images/castle-3.jpg");
    case 4:
        return QString(":/Images/Images/castle-4.jpg");
    default:
        return QString("Error with player ID");
    }
}
