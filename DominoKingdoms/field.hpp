#ifndef FIELD_H
#define FIELD_H

#include "enums.h"

class Field
{

private: // variables

   FieldType m_fType;
   int m_crownsNumber;
   bool m_visited;

public: // methods
    Field();
    Field(FieldType ft, int cn);
    FieldType get_fType();
    int get_crownsNumber();
    void set_fType(FieldType ft);
    void set_crownsNumber(int cn);
    bool getVisited() const;
    void setVisited(bool visited);
};

#endif // FIELD_H
