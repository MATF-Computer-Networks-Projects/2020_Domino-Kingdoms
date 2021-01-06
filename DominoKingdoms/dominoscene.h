#ifndef DOMINOSCENE_H
#define DOMINOSCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <vector>
#include <QGraphicsSceneMouseEvent>
#include "dominofield.h"

class DominoScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DominoScene(QObject *o = 0);

    std::vector<DominoField *> *firstRow() const;
    void setFirstRow(std::vector<DominoField *> *firstRow);

    std::vector<DominoField *> *secondRow() const;
    void setSecondRow(std::vector<DominoField *> *secondRow);

    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

    QGraphicsView *view() const;
    void setView(QGraphicsView *view);

private:
    std::vector<DominoField*> *m_firstRow;
    std::vector<DominoField*> *m_secondRow;
    Domino* m_clickedDomino;
    QGraphicsView *m_view;
};

#endif // DOMINOSCENE_H
