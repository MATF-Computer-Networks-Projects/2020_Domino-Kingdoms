#include "game.h"
#include <iterator>
#include <algorithm>
#include <iostream>

Game::Game()
{
    m_queue = new QQueue<int>();
    for(int i = 1; i < 5; i++)
        m_queue->enqueue(i);
}

QQueue<int> *Game::queue() const
{
    return m_queue;
}

void Game::setQueue(QQueue<int> *queue)
{
    m_queue = queue;
}

void Game::play()
{
    //TODO
}

int Game::nextPlayer()
{
    if(m_queue->size() > 0)
        return m_queue->dequeue();
    return -1;
}

void Game::setupQueue(std::vector<DominoField*> column)
{
    std::vector<Domino*> dominoes;
    for(auto &c : column)
        dominoes.push_back(c->getDomino());

    std::sort(dominoes.begin(), dominoes.end(), [](Domino* d1, Domino* d2){
        return (*d1).getValue() < (*d2).getValue();
    });

    for(auto &d : dominoes)
        m_queue->enqueue(d->getPlayer()->get_id());
}
