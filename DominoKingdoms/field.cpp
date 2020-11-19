#include "field.hpp"
#include "enums.h"

Field::Field(FieldType ft, int cn):
    m_fType(ft), m_crownsNumber(cn)
{

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





