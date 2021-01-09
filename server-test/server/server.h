#ifndef SERVER_H
#define SERVER_H

#include <QDebug>
#include <QTcpSocket>
#include <QTcpServer>
#include <QObject>
#include <QVector>
#include <QIODevice>
#include <QMap>
#include <QDataStream>

#include "signals.h"

class server : public QObject
{
    Q_OBJECT

public:
    explicit server(QObject *parent = 0);
    ~server();
    void startServer();
    void sendMessageToClients(QString message);


public slots:
    void newClientConnection();
    void socketDisconnected();
    void socketReadyRead();
    void socketStateChanged(QAbstractSocket::SocketState state);


private:
    struct player{
        int number;
        QTcpSocket* socket;
        QString name;
    };
    QTcpServer *_server;
    QMap<QTcpSocket*,player*> clients;
    QDataStream in;

};

#endif // SERVER_H
