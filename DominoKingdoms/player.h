#ifndef PLAYER_H
#define PLAYER_H

#include "table.h"

class Player{

private: //variables

    string m_name;
    int m_id;
    Table m_table;

public: //methods

    Player(string name, int id, Table table);
    int countScore();
};

#endif // PLAYER_H
