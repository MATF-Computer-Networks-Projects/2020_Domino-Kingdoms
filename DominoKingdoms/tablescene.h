#ifndef TABLESCENE_H
#define TABLESCENE_H

#include <QGraphicsScene>
#include <QPoint>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <vector>
#include <QGraphicsSceneMouseEvent>
#include "dominoscene.h"
#include <QKeyEvent>

class DominoScene;

class TableScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit TableScene(QObject *o = 0);

    struct forUpdate
    {
        forUpdate(Domino* d) {
            int forUpdateX1 = d->getXP1();
            int forUpdateY1 = d->getYP1();
            int forUpdateX2 = d->getXP2();
            int forUpdateY2 = d->getYP2();
        }

        int forUpdateX1;
        int forUpdateY1;
        int forUpdateX2;
        int forUpdateY2;
    };

    QGraphicsView *view() const;
    void setView(QGraphicsView *view);

    Player *p1() const;
    void setP1(Player *p1);

    Domino *clickedDomino() const;
    void setClickedDomino(Domino *clickedDomino);

    DominoScene *otherScene() const;
    void setOtherScene(DominoScene *otherScene);

    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void keyPressEvent(QKeyEvent *keyEvent);

    Player *currentPlayer() const;
    void setCurrentPlayer(Player *currentPlayer);

    Player *nextPlayer() const;
    void setNextPlayer(Player *nextPlayer);

    void moveDominoRight(forUpdate* post);
    void moveDominoLeft(forUpdate* post);
    void moveDominoUp(forUpdate* post);
    void moveDominoDown(forUpdate* post);
    void setDominoOnTable();
    void updateTableScene(forUpdate *pre, forUpdate *post);

private:
    QGraphicsView *m_view;
    DominoScene *m_otherScene;
    Domino *m_clickedDomino;
    Player *m_p1;
    Player *m_currentPlayer;
    Player *m_nextPlayer;
};

#endif // TABLESCENE_H
