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
        std::vector<DominoField*> *column;

        if(id == 1)
            column = m_firstRow;
        else if(id == 2)
            column = m_secondRow;

        m_clickedDomino = (*column)[index]->getDomino();

        if(m_p1->get_nextTask() == NextTaskDomino::ChooseDomino){
            for(int i = 0; i < 4; i++){
                this->removeItem((*column)[i]->getDomino());
                (*column)[i]->setDomino(nullptr);
            }
            m_otherScene->setClickedDomino(m_clickedDomino);
            m_p1->setNextTask(NextTaskDomino::PlaceDomino);

            m_clickedDomino->setXP1(0);
            m_clickedDomino->setYP1(0);
            m_clickedDomino->setXP2(150);
            m_clickedDomino->setYP2(0);
            m_clickedDomino->changeSize(150);
            m_otherScene->addItem(m_clickedDomino);
            m_clickedDomino->setOpacity(0.3);
            m_clickedDomino->setDominoStatus(DominoStatus::Placed);

            this->update(m_view->rect());
        }
        else if(m_p1->get_nextTask() == NextTaskDomino::ReserveDomino){
            m_p1->reserveDomino(m_clickedDomino);
            m_clickedDomino->setPlayer(m_p1);
            m_clickedDomino->setDominoStatus(DominoStatus::Reserved);
            m_p1->setNextTask(NextTaskDomino::ChooseDomino);
            this->update(m_view->rect());
            // promeni turn
            // m_p2->setNextTask(Choosedomino)
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

Player *DominoScene::p1() const
{
    return m_p1;
}

void DominoScene::setP1(Player *p1)
{
    m_p1 = p1;
}

TableScene *DominoScene::otherScene() const
{
    return m_otherScene;
}

void DominoScene::setOtherScene(TableScene *otherScene)
{
    m_otherScene = otherScene;
}
