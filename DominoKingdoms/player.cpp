#include <string>
//#include "table.hpp"
#include "player.hpp"
#include "enums.h"

Domino *Player::getSelectedDomino() const
{
    return m_selectedDomino;
}

void Player::setSelectedDomino(Domino *selectedDomino)
{
    m_selectedDomino = selectedDomino;
}

Player::Player(std::string name, int id):
    m_name(name), m_id(id){
    if(id<0 || id >4){
        throw "Incorrect player id";
    }

    m_playerTable.resize(tableFields);
    for(int i=0; i<tableFields; i++)
        m_playerTable[i].resize(tableFields,Field(FieldType::Empty,0));
    m_playerTable[tableFields/2][tableFields/2] = Field(FieldType::Castle,0);
}

int Player::countScore(){
    //todo
    return 0; //to eliminate warning
}

int Player::get_id(){
    return m_id;
}

std::string Player::get_name(){
    return m_name;
}

NextTaskDomino Player::get_nextTask(){
    return m_nextTask;
}

std::vector<std::vector<Field> > Player::get_playerTable()
{
    return m_playerTable;
}

Field Player::get_playerTableField(int x, int y){
    return m_playerTable[x][y];
}

QString Player::NextTaskDomino1(NextTaskDomino ntd){
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

void Player::set_id(int id){
    m_id = id;
}

void Player::set_name(const std::string &name){
    m_name = name;
}

void Player::set_playerTable(const std::vector<std::vector<Field> > &playerTable)
{
    m_playerTable = playerTable;
}

void Player::set_playerTableField(FieldType fd, int cn, int x, int y){
    m_playerTable[x][y] = Field(fd,cn);
}
