#ifndef OTHERSCENE_H
#define OTHERSCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <vector>
#include <QGraphicsSceneMouseEvent>
#include "player.hpp"

class OtherScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit OtherScene(QObject *o = 0);

    QGraphicsView *view() const;
    void setView(QGraphicsView *view);

    Player *p1() const;
    void setP1(Player *p1);

private:
    QGraphicsView *m_view;
    Player *m_p1;
};

#endif // OTHERSCENE_H
