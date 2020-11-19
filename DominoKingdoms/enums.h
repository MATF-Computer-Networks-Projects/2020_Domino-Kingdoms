#ifndef ENUMS_H
#define ENUMS_H

enum class Board_Status{
    OnTable,
    InDeck,
    OnBoard
};

enum class FieldType{
    Forest,
    Water,
    Quarry,
    Wheat,
    Meadow,
    Swamp,
    Empty
};

enum class DominoPosition{
    V12,
    H21,
    V21,
    H12,
    error
};

enum class NextTaskDomino{
    ChooseDomino,
    PlaceDomino,
    ReserveDomino
};

#endif // ENUMS_H
