#include "field.hpp"
#include "enums.h"

QString FieldType2QStringF(FieldType ft){
    switch (ft) {
    case FieldType::Forest:
        return QString(":/Images/Images/3.jpg");
    case FieldType::Meadow:
        return QString(":/Images/Images/1.jpeg");
    case FieldType::Quarry:
        return QString(":/Images/Images/2.jpg");
    case FieldType::Water:
        return QString(":/Images/Images/4.jpeg");
    case FieldType::Swamp:
        return QString(":/Images/Images/5.jpg");
    case FieldType::Wheat:
        return QString(":/Images/Images/6.png");
    default:
        return QString("field type not correct");
    }
}

QString Crowns2QStringF(int cr){
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

bool Field::getVisited() const
{
    return m_visited;
}

void Field::setVisited(bool visited)
{
    m_visited = visited;
}

Field &Field::operator=(const Field &other)
{
    m_visited = other.getVisited();
    m_crownsNumber = other.get_crownsNumber();
    m_fType = other.get_fType();
}

Field::Field(const Field &other)
{
    m_visited = other.getVisited();
    m_crownsNumber = other.get_crownsNumber();
    m_fType = other.get_fType();
}

QRectF Field::boundingRect() const
{
    return QRectF(QPoint(0,0),QPointF(100,100));
}

void Field::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pm_1 = QPixmap(FieldType2QStringF(m_fType));
    painter->drawPixmap(0,0,100,100,pm_1);
    if(m_crownsNumber>0){
        QPixmap pm_11 = QPixmap(Crowns2QStringF(m_crownsNumber));
        painter->drawPixmap(0,0,100,100,pm_11);
    }

}

Field::Field()
{
    m_fType = FieldType::Empty;
    m_crownsNumber = 0;
    m_visited = false;
}

Field::Field(FieldType ft, int cn):
    m_fType(ft), m_crownsNumber(cn)
{
    m_visited = false;
}

FieldType Field::get_fType() const{
    return m_fType;
}

int Field::get_crownsNumber() const{
    return m_crownsNumber;
}

void Field::set_fType(FieldType ft){
    m_fType = ft;
}
void Field::set_crownsNumber(int cn){
    m_crownsNumber = cn;
}





