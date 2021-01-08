#include "tablescene.h"
#include <iostream>

TableScene::TableScene(QObject *o)
{
    this->setParent(o);
}

QGraphicsView *TableScene::view() const
{
    return m_view;
}

void TableScene::setView(QGraphicsView *view)
{
    m_view = view;
}

Player *TableScene::p1() const
{
    return m_p1;
}

void TableScene::setP1(Player *p1)
{
    m_p1 = p1;
}

Domino *TableScene::clickedDomino() const
{
    return m_clickedDomino;
}

void TableScene::setClickedDomino(Domino *clickedDomino)
{
    m_clickedDomino = clickedDomino;
}

DominoScene *TableScene::otherScene() const
{
    return m_otherScene;
}

void TableScene::setOtherScene(DominoScene *otherScene)
{
    m_otherScene = otherScene;
}

void TableScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (mouseEvent->button() == Qt::RightButton && m_p1->get_nextTask() == NextTaskDomino::PlaceDomino)
    {
        int x = mouseEvent->scenePos().x();
        int y = mouseEvent->scenePos().y();

        m_clickedDomino->rotate();
        this->update(m_view->rect());
    }
}

void TableScene::keyPressEvent(QKeyEvent *keyEvent)
{
    if(m_p1->get_nextTask() == NextTaskDomino::PlaceDomino){
        if(keyEvent->key() == Qt::Key_Right){
            if(m_clickedDomino->getXP2() + 150 > 600 || m_clickedDomino->getXP1() + 150 > 600)
                return;
            m_clickedDomino->setXP1(m_clickedDomino->getXP1() + 150);
            m_clickedDomino->setXP2(m_clickedDomino->getXP2() + 150);
        }
        else if(keyEvent->key() == Qt::Key_Left){
            if(m_clickedDomino->getXP1() - 150 < 0 || m_clickedDomino->getXP2() - 150 < 0)
                return;
            m_clickedDomino->setXP2(m_clickedDomino->getXP2() - 150);
            m_clickedDomino->setXP1(m_clickedDomino->getXP1() - 150);
        }
        else if(keyEvent->key() == Qt::Key_Up){
            if(m_clickedDomino->getYP1() - 150 < 0 || m_clickedDomino->getYP2() - 150 < 0)
                return;
            m_clickedDomino->setYP1(m_clickedDomino->getYP1() - 150);
            m_clickedDomino->setYP2(m_clickedDomino->getYP2() - 150);
        }
        else if(keyEvent->key() == Qt::Key_Down){
            if(m_clickedDomino->getYP1() + 150 > 600 || m_clickedDomino->getYP2() + 150 > 600)
                return;
            m_clickedDomino->setYP1(m_clickedDomino->getYP1() + 150);
            m_clickedDomino->setYP2(m_clickedDomino->getYP2() + 150);
        }
        else if(keyEvent->key() == Qt::Key_Return){
            int j1 = m_clickedDomino->getXP1() / 150;
            int i1 = m_clickedDomino->getYP1() / 150;

            int j2 = m_clickedDomino->getXP2() / 150;
            int i2 = m_clickedDomino->getYP2() / 150;

            if(m_p1->canPlaceDomino(m_clickedDomino)){
                m_clickedDomino->setOpacity(1);

                m_p1->set_playerTableField(m_clickedDomino->getFieldType1(), m_clickedDomino->getCrowns1(), i1, j1);
                m_p1->set_playerTableField(m_clickedDomino->getFieldType2(), m_clickedDomino->getCrowns2(), i2, j2);
                m_p1->setNextTask(NextTaskDomino::ReserveDomino);
            }
            else{
                std::cout << "Ne moze ovde postavis brapooo" << std::endl;
            }
        }
        QWidget *viewport = m_view->viewport();
        viewport->repaint();
        this->update(m_view->rect());

    }
}

Player *TableScene::currentPlayer() const
{
    return m_currentPlayer;
}

void TableScene::setCurrentPlayer(Player *currentPlayer)
{
    m_currentPlayer = currentPlayer;
}

Player *TableScene::nextPlayer() const
{
    return m_nextPlayer;
}

void TableScene::setNextPlayer(Player *nextPlayer)
{
    m_nextPlayer = nextPlayer;
}
