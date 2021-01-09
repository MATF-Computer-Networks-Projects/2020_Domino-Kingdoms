#include "otherscene.h"

OtherScene::OtherScene(QObject *o)
{
    this->setParent(o);
}

QGraphicsView *OtherScene::view() const
{
    return m_view;
}

void OtherScene::setView(QGraphicsView *view)
{
    m_view = view;
}

Player *OtherScene::p1() const
{
    return m_p1;
}

void OtherScene::setP1(Player *p1)
{
    m_p1 = p1;
}
