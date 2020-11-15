#include <string>
//#include "table.hpp"
#include "player.hpp"

Player::Player(std::string name, int id):
    m_name(name), m_id(id){

}

int Player::countScore(){
    //todo
    return 0; //to eliminate warning
}

int Player::getId(){
    return m_id;
}

