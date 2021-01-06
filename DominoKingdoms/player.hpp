#include "domino.hpp"
#include "field.hpp"
#include <vector>
#include <string>
#include <QColor>

class Domino;

#ifndef PLAYER_H
#define PLAYER_H

#define tableFields 19

class Player{

private: //variables

    std::string m_name;
    int m_id;
    Domino *m_selectedDomino;
    Domino *m_reservedDomino;
    NextTaskDomino m_nextTask;
    std::vector<std::vector<Field>> m_playerTable;
    QColor color;

public: //methods

    Player(std::string name, int id);
    int countScore();
    int get_id();
    std::string get_name();
    NextTaskDomino get_nextTask();
    std::vector<std::vector<Field> > get_playerTable();
    Field get_playerTableField(int x, int y);

    void reserveDomino(Domino *d);
    QString NextTaskDomino1(NextTaskDomino ntd);
    void set_id(int id);
    void set_name(const std::string &name);
    std::vector<std::vector<Field> > get_playerTable() const;
    void set_playerTable(const std::vector<std::vector<Field> > &playerTable);
    void set_playerTableField(FieldType fd, int cn, int x, int y);

    Domino *getSelectedDomino() const;
    void setSelectedDomino(Domino *selectedDomino);

    void setNextTask(const NextTaskDomino &nextTask);
    QColor getColor() const;
    void setColor(const QColor &value);

    bool canPlaceDomino(Domino *domino);
    bool compatibleDomino(int i1, int j1, int i2, int j2, FieldType fieldType);
};

#endif // PLAYER_H
