#ifndef TABLESCENE_H
#define TABLESCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <vector>
#include <QGraphicsSceneMouseEvent>

class TableScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TableScene(QObject *o = 0);
};

#endif // TABLESCENE_H
