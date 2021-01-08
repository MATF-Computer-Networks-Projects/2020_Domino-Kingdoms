#include "field.hpp"
#include "enums.h"

bool Field::getVisited() const
{
    return m_visited;
}

void Field::setVisited(bool visited)
{
    m_visited = visited;
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

FieldType Field::get_fType(){
    return m_fType;
}

int Field::get_crownsNumber(){
    return m_crownsNumber;
}

void Field::set_fType(FieldType ft){
    m_fType = ft;
}
void Field::set_crownsNumber(int cn){
    m_crownsNumber = cn;
}





