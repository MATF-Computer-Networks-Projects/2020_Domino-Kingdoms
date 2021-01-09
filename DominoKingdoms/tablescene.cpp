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
        int preX = m_clickedDomino->getXP2();
        int preY = m_clickedDomino->getYP2();

        m_clickedDomino->rotate();

        int postX = m_clickedDomino->getXP2();
        int postY = m_clickedDomino->getYP2();

        this->update(preX, preY, 150, 150);
        this->update(postX, postY, 150, 150);
    }
}

void TableScene::moveDominoRight(forUpdate* post){
    if(m_clickedDomino->getXP2() + 150 > 600 || m_clickedDomino->getXP1() + 150 > 600)
        return;
    this->removeItem(m_clickedDomino);
    m_clickedDomino->setXP1(m_clickedDomino->getXP1() + 150);
    m_clickedDomino->setXP2(m_clickedDomino->getXP2() + 150);
    this->addItem(m_clickedDomino);
    post->forUpdateX1 = m_clickedDomino->getXP1();
    post->forUpdateX2 = m_clickedDomino->getXP2();
}

void TableScene::moveDominoLeft(forUpdate *post){
    if(m_clickedDomino->getXP1() - 150 < 0 || m_clickedDomino->getXP2() - 150 < 0)
        return;
    this->removeItem(m_clickedDomino);
    m_clickedDomino->setXP2(m_clickedDomino->getXP2() - 150);
    m_clickedDomino->setXP1(m_clickedDomino->getXP1() - 150);
    this->addItem(m_clickedDomino);
    post->forUpdateX2 = m_clickedDomino->getXP2();
    post->forUpdateX1 = m_clickedDomino->getXP1();
}

void TableScene::moveDominoUp(forUpdate *post){
    if(m_clickedDomino->getYP1() - 150 < 0 || m_clickedDomino->getYP2() - 150 < 0)
        return;
    this->removeItem(m_clickedDomino);
    m_clickedDomino->setYP1(m_clickedDomino->getYP1() - 150);
    m_clickedDomino->setYP2(m_clickedDomino->getYP2() - 150);
    this->addItem(m_clickedDomino);
    post->forUpdateY1 = m_clickedDomino->getYP1();
    post->forUpdateY2 = m_clickedDomino->getYP2();
}

void TableScene::moveDominoDown(forUpdate *post){
    if(m_clickedDomino->getYP1() + 150 > 600 || m_clickedDomino->getYP2() + 150 > 600)
        return;
    this->removeItem(m_clickedDomino);
    m_clickedDomino->setYP1(m_clickedDomino->getYP1() + 150);
    m_clickedDomino->setYP2(m_clickedDomino->getYP2() + 150);
    this->addItem(m_clickedDomino);
    post->forUpdateY1 = m_clickedDomino->getYP1();
    post->forUpdateY2 = m_clickedDomino->getYP2();
}

void TableScene::setDominoOnTable(){
    int j1 = m_clickedDomino->getXP1() / 150;
    int i1 = m_clickedDomino->getYP1() / 150;

    int j2 = m_clickedDomino->getXP2() / 150;
    int i2 = m_clickedDomino->getYP2() / 150;

    if(m_p1->canPlaceDomino(m_clickedDomino)){
        m_clickedDomino->setOpacity(0.4);

        m_p1->set_playerTableField(m_clickedDomino->getFieldType1(), m_clickedDomino->getCrowns1(), i1, j1);
        m_p1->set_playerTableField(m_clickedDomino->getFieldType2(), m_clickedDomino->getCrowns2(), i2, j2);
        m_p1->setNextTask(NextTaskDomino::ReserveDomino);
    }
    else
        std::cout << "Ne moze ovde postavis brapooo" << std::endl;
}

void TableScene::updateTableScene(forUpdate *pre, forUpdate *post){

    this->update(pre->forUpdateX1, pre->forUpdateY1, 150, 150);
    this->update(pre->forUpdateX2, pre->forUpdateY2, 150, 150);
    this->update(post->forUpdateX1, post->forUpdateY1, 150, 150);
    this->update(post->forUpdateX2, post->forUpdateY2, 150, 150);
}

void TableScene::keyPressEvent(QKeyEvent *keyEvent)
{
    if(m_p1->get_nextTask() == NextTaskDomino::PlaceDomino){

        forUpdate dominoPre(m_clickedDomino);
        forUpdate dominoPost(m_clickedDomino);

        if(keyEvent->key() == Qt::Key_Right)
            moveDominoRight(&dominoPost);

        else if(keyEvent->key() == Qt::Key_Left)
            moveDominoLeft(&dominoPost);

        else if(keyEvent->key() == Qt::Key_Up)
            moveDominoUp(&dominoPost);

        else if(keyEvent->key() == Qt::Key_Down)
            moveDominoDown(&dominoPost);

        else if(keyEvent->key() == Qt::Key_Return)
                setDominoOnTable();

        updateTableScene(&dominoPre, &dominoPost);
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
