#ifndef FIELD_H
#define FIELD_H

#include "enums.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QPointF>

class Field : public QGraphicsItem
{

private: // variables

   FieldType m_fType;
   int m_crownsNumber;
   bool m_visited;

public: // methods
    Field();
    Field(FieldType ft, int cn);
    FieldType get_fType() const;
    int get_crownsNumber() const;
    void set_fType(FieldType ft);
    void set_crownsNumber(int cn);
    bool getVisited() const;
    void setVisited(bool visited);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget) override;

    Field & operator=(const Field &other);
    Field(const Field& other);
};

#endif // FIELD_H
