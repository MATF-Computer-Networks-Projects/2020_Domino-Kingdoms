#include "dominoscene.h"
#include <iostream>

std::pair<int, int> coordinatesToIndex(int x, int y){
    int id = -1;
    int index = -1;
    if(x >= 0 && x <= 200)
        id = 1;
    else if(x >= 300 && x <= 500)
        id = 2;

    if(y >= 0 && y <= 100)
        index = 0;
    else if(y >= 200 && y<= 300)
        index = 1;
    else if(y >= 400 && y<= 500)
        index = 2;
    else if(y >= 600 && y<= 700)
        index = 3;

    return std::make_pair(id, index);
}

DominoScene::DominoScene(QObject *o)
{
    this->setParent(o);
}

std::vector<DominoField *> *DominoScene::firstRow() const
{
    return m_firstRow;
}

void DominoScene::setFirstRow(std::vector<DominoField *> *firstRow)
{
    m_firstRow = firstRow;
}

std::vector<DominoField *> *DominoScene::secondRow() const
{
    return m_secondRow;
}

void DominoScene::setSecondRow(std::vector<DominoField *> *secondRow)
{
    m_secondRow = secondRow;
}

void DominoScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent){
    if (mouseEvent->button() == Qt::LeftButton)
    {
        int x = mouseEvent->scenePos().x();
        int y = mouseEvent->scenePos().y();
        std::pair<int, int> position = coordinatesToIndex(x, y);
        int id = position.first;
        int index = position.second;
        std::vector<DominoField*> *row;

        if(id == 1)
            row = m_firstRow;
        else if(id == 2)
            row = m_secondRow;

        QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());
        m_clickedDomino = nullptr;
        m_clickedDomino = qgraphicsitem_cast<Domino *>(item);
        if(m_clickedDomino){
            this->removeItem((*row)[index]->getDomino());
            (*row)[index]->setDomino(nullptr);
            this->update(m_view->rect());
        }
    }
}

QGraphicsView *DominoScene::view() const
{
    return m_view;
}

void DominoScene::setView(QGraphicsView *view)
{
    m_view = view;
}
