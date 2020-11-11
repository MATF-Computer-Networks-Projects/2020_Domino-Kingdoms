#include "table.hpp"
#include "domino.hpp"

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
    void reserve_domino(Domino d);
};

#endif // PLAYER_H
