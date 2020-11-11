#include <string>
//#include "table.hpp"
#include "player.hpp"

Player::Player(std::string name, int id, Table table):
    m_name(name), m_id(id),m_table(table){

}

int Player::countScore(){
    //todo
    return 0; //to eliminate warning
}

int Player::get_id(){
    return m_id;
}

