#include "table.hpp"

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{

private: //variables

    std::string m_name;
    int m_id;
    Table m_table;

public: //methods

    Player(std::string name, int id, Table table);
    int countScore();
    int get_id();
};

#endif // PLAYER_H
