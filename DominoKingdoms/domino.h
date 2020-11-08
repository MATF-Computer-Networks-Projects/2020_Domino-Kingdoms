#ifndef DOMINO_HPP
#define DOMINO_HPP

#include "player.h"

enum class Board_Status{
    OnTable,
    InDeck,
    OnBoard
};

class Domino{

private: //variables

    int m_xPos1, m_yPos1, m_xPos2, m_yPos2, m_width, m_height, m_leftId,
        m_rightId, m_value, m_crownsLeft, m_crownsRight, m_reservedBy;
    bool m_currentlyCompatible;
    Board_Status m_boardStatus;

public: //methods

    Domino(int xPos1, int yPos1, int xPos2,int yPos2,
           int width, int height, int leftId, int rightId,
           bool currentlyCompatible, Board_Status boardStatus,
           int value, int crownsLeft, int crownsRight, int reservedBy);
    void rotate();
    bool compatibleWith(Domino d);
    void reserve(Player p);
};

#endif // DOMINO_HPP
