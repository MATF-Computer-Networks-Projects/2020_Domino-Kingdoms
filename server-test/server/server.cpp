#include "server.h"

server::server(QObject *parent) :
    QObject(parent)
{

}

server::~server()
{

}

void server::startServer()
{
    clients = QMap<QTcpSocket*, player*>();
    _server = new QTcpServer();
    _server->setMaxPendingConnections(4);

    connect(_server,SIGNAL(newConnection()),this,SLOT(newClientConnection()));
    if(_server->listen(QHostAddress::Any,8001)){
        qDebug()<<"Server has started"
               <<"Listening to port 8001";
    }
    else{
        qDebug()<<"Server failed to start";
    }
}

void server::sendMessageToClients(QString message)
{

}

void server::newClientConnection()
{
    QTcpSocket *client = _server->nextPendingConnection();
    QString ipAddr = client->peerAddress().toString();
    int port = client->peerPort();

    connect(client,&QTcpSocket::disconnected,this,&server::socketDisconnected);
    connect(client,&QTcpSocket::readyRead,this,&server::socketReadyRead);
    connect(client,&QTcpSocket::stateChanged,this,&server::socketStateChanged);

    player *p = new player();
    p->number = 1;
    p->socket = client;
    p->name = "";

    clients.insert(client,p);

    qDebug()<<"Socket connected from " + ipAddr + ":" +QString::number(port);

}

void server::socketDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(QObject::sender());
    QString socketIpAddress = client->peerAddress().toString();
    int port = client->peerPort();
    qDebug() <<"Socket disconnected from " + socketIpAddress + ":" + QString::number(port);
    for(auto it : clients){
        if((*it).name == clients[client]->name){
            clients.remove((*it).socket);
        }
    }
}

void server::socketReadyRead()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(QObject::sender());
    QString socketIpAdress = client->peerAddress().toString();
    int port =client->peerPort();
    player *playerp = (clients.find(client)).value();
//    if(player == clients.end())
//        qDebug<<"Nema takvog igraca";
    in.setDevice(client);
    in.setVersion(QDataStream::Qt_5_9);

    in.startTransaction();

    int type;
    in>>type;

    if(type == Signals::send_name_init){
        qDebug()<<"Dobio je ime";
        QByteArray message;
        in>>message;
        playerp->name = QString::fromUtf8(message);
    }
    else if(type == Signals::send_request){
        qDebug()<<"Dobio je zahtev";
        QByteArray block;
        QDataStream out(&block,QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_9);

        out<<Signals::send_number;
        out<<(int)clients.size();

        for(auto it = clients.begin();it!=clients.end();it++){

               out<<(*it)->name<<(*it)->number;

        }

        QTcpSocket *client = qobject_cast<QTcpSocket*>(QObject::sender());
        //auto it = clients.find(client);
        client->flush();


        //qDebug()<<"Request salje: "<< clients[client]->name;
        if(client->isOpen() && client->isWritable()){
            client->write(block);
        }
        else{
            qDebug()<<"NIJE OTVOREN I NE MOZe Da sE PISE";
        }

    }
    else if(type == Signals::number_incremented){

        qDebug()<<"Dobio je signal za inkrementaciju";
        QTcpSocket *client = qobject_cast<QTcpSocket*>(QObject::sender());
        qDebug()<<"Stari broj klijenta: " << clients[client]->number;
        clients[client]->number+=1;
        qDebug()<<"Novi broj klijenta: " << clients[client]->number;
//        QByteArray block;
//        QDataStream out(&block,QIODevice::WriteOnly);
//        out.setVersion(QDataStream::Qt_5_9);
//        out<<Signals::finished_update;

    }
    if(!in.commitTransaction()){
        qDebug()<<"NIJE KOMITOVAO";
        return;
    }

}

void server::socketStateChanged(QAbstractSocket::SocketState state)
{
    QTcpSocket* client =qobject_cast<QTcpSocket*>(QObject::sender());
    QString socketIpAdress = client->peerAddress().toString();
    int port =client->peerPort();

    QString data = QString(client->readAll());

    QString desc;

    if(state==QAbstractSocket::UnconnectedState)
        desc = "The socket is not connected.";
    else if(state == QAbstractSocket::HostLookupState)
        desc = "The socket is performing a host name lookup.";
    else if(state==QAbstractSocket::ConnectingState)
        desc = "The socket has started establishing a connection.";
    else if(state == QAbstractSocket::ConnectedState)
        desc ="A connection is established.";
    else if(state==QAbstractSocket::BoundState)
        desc = "The socket is bound to an address and port.";
    else if(state==QAbstractSocket::ClosingState)
        desc = "The socket is about to close.";
    else if(state==QAbstractSocket::ListeningState)
        desc = "For internal use only.";

    qDebug() <<"Socket state changed (" + socketIpAdress+  ":" + QString::number(port)+ ")" + desc;

}

































