#include "domino.hpp"
#include "field.hpp"
#include <vector>

#ifndef PLAYER_H
#define PLAYER_H

#define tableFields 19

#include <string>

class Player{

private: //variables

    std::string m_name;
    int m_id;
    NextTaskDomino nextTask;
    std::vector<std::vector<Field>> playerTable;

public: //methods

    Player(std::string name, int id);
    int countScore();
    int getId();
    void reserveDomino(Domino d);
    QString NextTaskDomino2QString(NextTaskDomino ntd);
};

#endif // PLAYER_H
