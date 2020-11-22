#ifndef DOMINO_HPP
#define DOMINO_HPP

#include "enums.h"
#include <QGraphicsItem>

class Domino : public QGraphicsItem
{

private: //variables

    int m_xPos1, m_yPos1, m_xPos2, m_yPos2, m_width, m_height,
        m_value, m_crowns1, m_crowns2, m_reservedBy;
    bool m_currentlyCompatible, m_pressed, m_held;
    Board_Status m_boardStatus;
    FieldType m_fieldType1, m_fieldType2;

public: //methods

    Domino(int xPos1, int yPos1, int xPos2,int yPos2,
           int width, int height,
           int value, int crowns1, int crowns2,
           int reservedBy,bool currentlyCompatible, Board_Status boardStatus,
           FieldType ft1, FieldType ft2);

    Domino(int crowns1, int crowns2,FieldType fieldType1, FieldType fieldType2, int value);

    void rotate();
    bool compatibleWith(Domino d);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    int getCrowns2();
    int getCrowns1();
    int getReservedBy();
    int getXP1() const;
    int getYP1() const;
    int getXP2() const;
    int getYP2() const;
    int getValue();
    int getWidth() const;
    int getHeight() const;
    FieldType getFieldType1() const;
    FieldType getFieldType2() const;
    Board_Status getBoardStatus() const;
    bool isPressed();
    bool isHeld();

    void setCurrentlyCompatible(bool);
    void setBoardStatus(Board_Status);
    void setWidth(int);
    void setHeight(int);
    void setXP1(int);
    void setYP1(int);
    void setXP2(int);
    void setYP2(int);
    void setPressed();
    void setHeld();
    void unsetPressed();
    void unsetHeld();

    DominoPosition position2DominoPosition(int x1,int y1,int x2,int y2,int w,int h) const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // DOMINO_HPP
