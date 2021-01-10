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
#include "player.hpp"
#include "tablescene.h"

class TableScene;

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

    Player *p1() const;
    void setP1(Player *p1);

    TableScene *otherScene() const;
    void setOtherScene(TableScene *otherScene);

    int activeColumn() const;
    void setActiveColumn(int activeColumn);

private:
    std::vector<DominoField*> *m_firstRow;
    std::vector<DominoField*> *m_secondRow;
    Domino* m_clickedDomino;
    QGraphicsView *m_view;
    Player *m_p1;
    TableScene *m_otherScene;
    int m_activeColumn;

signals:
    void signalReservedDomino();
    void signalChosenDomino();
    void updateColor();

public:
    int sPlayerId;
//    1 5
//    2 6
//    3 7
//    4 8
    int sDominoFieldNumber;

};

#endif // DOMINOSCENE_H
