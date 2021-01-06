#include "tablescene.h"

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
