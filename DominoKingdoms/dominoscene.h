#ifndef DOMINOSCENE_H
#define DOMINOSCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <vector>
#include <QGraphicsSceneMouseEvent>

class DominoScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DominoScene(QObject *o = 0);
};

#endif // DOMINOSCENE_H
