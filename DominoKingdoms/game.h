#ifndef GAME_H
#define GAME_H
#include <QQueue>
#include <vector>
#include <dominofield.h>
#include <domino.hpp>
#include <player.hpp>


class Game
{
public:
    Game();

    QQueue<int> *queue() const;
    void setQueue(QQueue<int> *queue);
    void setupQueue(std::vector<DominoField*> column);
    void play();
    int nextPlayer();

private:
    QQueue<int> *m_queue;


};

#endif // GAME_H
