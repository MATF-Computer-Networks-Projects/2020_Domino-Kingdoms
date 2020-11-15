#include "domino.hpp"

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{

private: //variables

    std::string m_name;
    int m_id;

public: //methods

    Player(std::string name, int id);
    int countScore();
    int getId();
    void reserveDomino(Domino d);
};

#endif // PLAYER_H
