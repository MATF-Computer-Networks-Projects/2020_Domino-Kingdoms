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

    QGraphicsView *view() const;
    void setView(QGraphicsView *view);

private:
    QGraphicsView *m_view;
};

#endif // TABLESCENE_H
