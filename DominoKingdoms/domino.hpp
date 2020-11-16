#ifndef DOMINO_HPP
#define DOMINO_HPP

#include "enums.h"
#include <QGraphicsPixmapItem>

class Domino : public QGraphicsPixmapItem
{

private: //variables

    int m_xPos1, m_yPos1, m_xPos2, m_yPos2, m_width, m_height,
        m_value, m_crownsLeft, m_crownsRight, m_reservedBy;
    bool m_currentlyCompatible;
    Board_Status m_boardStatus;
    FieldType m_leftId, m_rightId;

public: //methods

    Domino(int xPos1, int yPos1, int xPos2,int yPos2,
           int width, int height,
           int value, int crownsLeft, int crownsRight,
           int reservedBy,bool currentlyCompatible, Board_Status boardStatus,
           FieldType leftId, FieldType rightId);
    void rotate();
    bool compatibleWith(Domino d);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    int getCrownsRight();
    int getCrownsLeft();
    int getReservedBy();

    void setBoardStatus(Board_Status b);
};

#endif // DOMINO_HPP
