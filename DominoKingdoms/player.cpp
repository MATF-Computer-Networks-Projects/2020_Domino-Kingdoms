#include <string>
//#include "table.hpp"
#include "player.hpp"

Player::Player(std::string name, int id):
    m_name(name), m_id(id){
    if(id<0 || id >4){
        throw "Incorrect player id";
    }
}

int Player::countScore(){
    //todo
    return 0; //to eliminate warning
}

int Player::getId(){
    return m_id;
}

QString Player::NextTaskDomino2QString(NextTaskDomino ntd){
    switch(ntd) {
    case NextTaskDomino::ChooseDomino:
        //todo
        return nullptr;
    case NextTaskDomino::PlaceDomino:
        //todo
        return nullptr;
    case NextTaskDomino::ReserveDomino:
        //todo
        return nullptr;
    default :
        return QString("Next task not correct");
    }
}

