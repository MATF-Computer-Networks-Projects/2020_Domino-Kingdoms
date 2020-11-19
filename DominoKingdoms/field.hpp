#ifndef FIELD_H
#define FIELD_H

#include "enums.h"

class Field
{

private: // variables

   FieldType fType;
   int crownsNumber;

public: // methods
    Field(FieldType ft, int cn);

};

#endif // FIELD_H
