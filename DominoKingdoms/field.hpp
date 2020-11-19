#ifndef FIELD_H
#define FIELD_H

#include "enums.h"

class Field
{

private: // variables

   FieldType m_fType;
   int m_crownsNumber;

public: // methods

    Field(FieldType ft, int cn);
    FieldType get_fType();
    int get_crownsNumber();
    void set_fType(FieldType ft);
    void set_crownsNumber(int cn);
};

#endif // FIELD_H
