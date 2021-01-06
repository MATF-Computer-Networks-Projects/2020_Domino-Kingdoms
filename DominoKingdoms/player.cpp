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

void Player::setNextTask(const NextTaskDomino &nextTask)
{
    m_nextTask = nextTask;
}

QColor Player::getColor() const
{
    return color;
}

void Player::setColor(const QColor &value)
{
    color = value;
}

bool Player::canPlaceDomino(Domino *domino)
{
    int j1 = domino->getXP1() / 150;
    int i1 = domino->getYP1() / 150;

    int j2 = domino->getXP2() / 150;
    int i2 = domino->getYP2() / 150;

    if(get_playerTableField(i1, j1).get_fType() != FieldType::Empty
                        || get_playerTableField(i2, j2).get_fType() != FieldType::Empty)
        return false;

    FieldType ft1 = domino->getFieldType1();
    FieldType ft2 = domino->getFieldType2();

    if(compatibleDomino(i1, j1, i1+1, j1, ft1))
        return true;
    else if(compatibleDomino(i1, j1, i1, j1+1, ft1))
        return true;
    else if(compatibleDomino(i1, j1, i1-1, j1, ft1))
        return true;
    else if(compatibleDomino(i1, j1, i1, j1-1, ft1))
        return true;

    if(compatibleDomino(i2, j2, i2+1, j2, ft2))
        return true;
    else if(compatibleDomino(i2, j2, i2, j2+1, ft2))
        return true;
    else if(compatibleDomino(i2, j2, i2-1, j2, ft2))
        return true;
    else if(compatibleDomino(i2, j2, i2, j2-1, ft2))
        return true;

    return false;
}

bool Player::compatibleDomino(int i1, int j1, int i2, int j2, FieldType fieldType)
{
    if(i2 < 0 || i2 > 4 || j2 < 0 || j2 > 4)
        return false;
    FieldType ft = m_playerTable[i2][j2].get_fType();
    if(ft == fieldType || ft == FieldType::Castle)
        return true;
    else
        return false;
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
    m_nextTask = NextTaskDomino::ReserveDomino;
    switch (id) {
    case 1:
        color = Qt::red;
        break;
    case 2:
        color = Qt::green;
        break;
    case 3:
        color = Qt::blue;
        break;
    case 4:
        color = Qt::yellow;
        break;
    default:
        break;
    }
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

void Player::reserveDomino(Domino *d)
{
    m_reservedDomino = d;
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
