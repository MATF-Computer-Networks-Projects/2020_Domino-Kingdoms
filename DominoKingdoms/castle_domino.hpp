#ifndef CASTLE_DOMINO_HPP
#define CASTLE_DOMINO_HPP

#include "domino.hpp"

#include <QGraphicsItem>
#include <QString>

class CastleDomino : public QGraphicsItem
{

private: //variables

    int m_xPos, m_yPos, m_width, m_height, m_pid;
    bool m_currentlyCompatible;

public: //methods

    CastleDomino(int);

    bool compatibleWith(Domino d);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    int getXP() const;
    int getYP() const;
    int getWidth() const;
    int getHeight() const;
    int getPID() const;

    void setCurrentlyCompatible(bool);
    void setWidth(int);
    void setHeight(int);
    void setXP(int);
    void setYP(int);
    void setPID(int);

    QString playerId2QString(int pid);
};


#endif // CASTLE_DOMINO_HPP
