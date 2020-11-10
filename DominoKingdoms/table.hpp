#ifndef TABLE_H
#define TABLE_H

#include <vector>

#include "domino.hpp"


class Table{

private: //variables

    int m_xPos, m_yPos, m_width, m_height, m_score;
    std::vector<Domino> m_dominos;

public: //methods

    Table(int xPos, int yPos, int width, int height, std::vector<Domino> dominos);

};

#endif // TABLE_H
