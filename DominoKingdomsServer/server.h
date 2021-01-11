#ifndef SERVER_H
#define SERVER_H

#include <QWidget>
#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <QVector>
#include <QIODevice>
#include <QMap>
#include <QDataStream>
#include <string>
#include <QString>
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

#include "signals.h"
#include "../DominoKingdoms/player.hpp"

class Player;

class server : public QObject
{
    Q_OBJECT

public:
    explicit server(QObject *parent = 0);
    ~server();
    void startServer();
    void setDeck();
    void processEndGame();

public slots:
    void newClientConnection();
    void socketDisconnected();
    void socketReadyRead();
    void socketStateChanged(QAbstractSocket::SocketState state);


private:
    QTcpServer *_server;
    QMap <QTcpSocket*, Player*> _clients;
    QDataStream _in;

    std::vector<Domino*> dominoes;
    std::vector<int> currentTurn;
    std::vector<int> nextTurn;

    int currIndexPlayer;

    int playingPlayer;
    QString playerName;

    bool beginning;

    int numOfDominoesUsed;

    QMap <QString, int> endGamePoints;

public:
    int nextPlayersId;
};

#endif // SERVER_H
