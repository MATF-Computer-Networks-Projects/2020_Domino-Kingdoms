#include "server.h"


server::server(QObject *parent)
{
    nextPlayersId = 0;
}

server::~server()
{

}

void server::startServer()
{
    _clients = QMap<QTcpSocket*, Player*>();
    _server = new QTcpServer();
    _server->setMaxPendingConnections(4);

    connect(_server, SIGNAL(newConnection()), this, SLOT(newClientConnection()));

    if(_server->listen(QHostAddress::Any,8001)){
        qDebug()<<"Server has started listening to port 8001";
    }
    else{
        qDebug()<<"Server failed to start!";
    }
}

void server::newClientConnection()
{
    QTcpSocket *client = _server->nextPendingConnection();
    QString ipAddr = client->peerAddress().toString();
    int port = client->peerPort();

    connect(client, &QTcpSocket::disconnected, this, &server::socketDisconnected);
    connect(client, &QTcpSocket::readyRead, this, &server::socketReadyRead);
    connect(client, &QTcpSocket::stateChanged, this, &server::socketStateChanged);

//    Player *player = new Player("",++nextPlayersId);

    Player *player = new Player(std::string("marija"),++nextPlayersId);

    _clients.insert(client, player);

    qDebug()<<"Socket connected from " + ipAddr + " : " + QString::number(port);
}

void server::socketDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(QObject::sender());
    QString ipAddr = client->peerAddress().toString();
    int port = client->peerPort();


    _clients.remove(client);

    qDebug()<<"Socket disconnected from " + ipAddr + " : " + QString::number(port);
}

void server::socketReadyRead()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(QObject::sender());

    _in.setDevice(client);
    _in.setVersion(QDataStream::Qt_5_9);

    _in.startTransaction();

    int type;
    _in>>type;

    if(type == Signals::send_name){
         QByteArray input;
        _in>>input;
        QString input2 = QString::fromUtf8(input);
        _clients[client]->set_name(input2.toStdString());
        std::cout<<"Welcome " << _clients[client]->get_name()<<std::endl;
    }

    else if(type == Signals::send_update){
        int nxp1; int nxp2;
        int nyp1; int nyp2;
        int nft1; int nft2;
        int nc1; int nc2;
        _in>>nxp1>>nyp1>>nft1>>nc1;
        _in>>nxp2>>nyp2>>nft2>>nc2;

        _clients[client]->set_playerTableField((FieldType)nft1,nc1,nxp1,nyp1);
        _clients[client]->set_playerTableField((FieldType)nft2,nc2,nxp2,nyp2);


    }

    else if(type == Signals::request_player1){

        std::cout<<"Treba da pokazem polja playera 1"<<std::endl;


        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        out.setVersion(QDataStream::Qt_5_9);

        Player *p = _clients[client];

        int counter = 0;
        bool found = false;
        auto it = _clients.begin();
        for(it = _clients.begin(); it != _clients.end(); it++){
            if((*it)->get_id() != p->get_id()){
                counter++;
                if(counter == 1){
                    found = true;
                    break;
                }
            }
        }
        if(!found){
            std::cout<<"Player not found"<<std::endl;
            out<<Signals::player_not_found;
            client->write(block);
            return;
        }
        std::cout<<"Player found!"<<std::endl;

        int nxp1;
        int nyp1;
        int nft1;
        int nc1;

        out<<Signals::sending_table;

        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){


                nxp1 = i;
                nyp1 = j;
                nft1 = static_cast<int>( (*it)->get_playerTableField(i,j).get_fType());
                nc1 =  (*it)->get_playerTableField(i,j).get_crownsNumber();

                out<<nxp1<<nyp1<<nft1<<nc1;
            }
        }

        client->write(block);

    }

    if(!_in.commitTransaction()){
        return;
    }

}

void server::socketStateChanged(QAbstractSocket::SocketState state)
{
    QTcpSocket* client =qobject_cast<QTcpSocket*>(QObject::sender());
    QString socketIpAdress = client->peerAddress().toString();
    int port =client->peerPort();

    //QString data = QString(client->readAll());

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
