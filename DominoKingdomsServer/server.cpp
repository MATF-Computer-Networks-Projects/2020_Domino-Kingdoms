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
        setDeck();

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

    else if(type == Signals::request_player2){
        std::cout<<"Treba da pokazem polja playera 2"<<std::endl;


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
                if(counter == 2){
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

    else if(type == Signals::request_player3){
        std::cout<<"Treba da pokazem polja playera 3"<<std::endl;


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
                if(counter == 3){
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

    else if(type == Signals::send_reserve){
        int pid;
        _in>>pid;
        int row;
        _in>>row;

        auto it = _clients.begin();
        for(it = _clients.begin(); it != _clients.end(); it++){
            if((*it)->get_id() != pid){
                QByteArray block;
                QDataStream out(&block,QIODevice::WriteOnly);
                out.setVersion(QDataStream::Qt_5_9);

                out<<Signals::send_reserve<<pid<<row;

                _clients.key((*it))->write(block);
            }
        }


    }

    else if(type == Signals::request_cards){
        if(dominoes.size() <= 0){
            std::cout << "dosta ste se kartali" << std::endl;
            return;
        }

        std::vector<Domino *> temp;
        temp.clear();

        for(int i = 0; i < 4; i++){
            auto it = dominoes.back();
            temp.push_back(it);
            dominoes.pop_back();
        }

        std::sort(temp.begin(), temp.end(), [](Domino *d1, Domino *d2){
            return d1->getValue() < d2->getValue();
        });

        auto it = _clients.begin();
        for(it = _clients.begin(); it != _clients.end(); it++){

            QByteArray block;
            QDataStream out(&block,QIODevice::WriteOnly);
            out.setVersion(QDataStream::Qt_5_9);

            out<<Signals::sending_cards;

            for(int i = 0; i < 4; i++){
                out << temp[i]->getValue()-1;
            }

            _clients.key((*it))->write(block);
        }

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

void server::setDeck(){
    /* Initializing Dominoes */
    dominoes.push_back(new Domino(0, 0, FieldType::Wheat, FieldType::Wheat, 1, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Wheat, FieldType::Wheat, 2, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Forest, FieldType::Forest, 3, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Forest, FieldType::Forest, 4, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Forest, FieldType::Forest, 5, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Forest, FieldType::Forest, 6, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Water, FieldType::Water, 7, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Water, FieldType::Water, 8, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Water, FieldType::Water, 9, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Meadow, FieldType::Meadow, 10, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Meadow, FieldType::Meadow, 11, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Swamp, FieldType::Swamp, 12, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Wheat, FieldType::Forest, 13, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Wheat, FieldType::Water, 14, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Wheat, FieldType::Meadow, 15, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Wheat, FieldType::Swamp, 16, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Forest, FieldType::Water, 17, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 0, FieldType::Forest, FieldType::Meadow, 18, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Wheat, FieldType::Forest, 19, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Wheat, FieldType::Water, 20, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Wheat, FieldType::Meadow, 21, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Wheat, FieldType::Swamp, 22, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Wheat, FieldType::Quarry, 23, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Forest, FieldType::Wheat, 24, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Forest, FieldType::Wheat, 25, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Forest, FieldType::Wheat, 26, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Forest, FieldType::Wheat, 27, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Forest, FieldType::Water, 28, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Forest, FieldType::Meadow, 29, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Water, FieldType::Wheat, 30, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Water, FieldType::Wheat, 31, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Water, FieldType::Forest, 32, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Water, FieldType::Forest, 33, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Water, FieldType::Forest, 34, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Water, FieldType::Forest, 35, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 1, FieldType::Wheat, FieldType::Meadow, 36, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 1, FieldType::Water, FieldType::Meadow, 37, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 1, FieldType::Wheat, FieldType::Swamp, 38, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 1, FieldType::Meadow, FieldType::Swamp, 39, Board_Status::InDeck));
    dominoes.push_back(new Domino(1, 0, FieldType::Quarry, FieldType::Wheat, 40, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 2, FieldType::Wheat, FieldType::Meadow, 41, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 2, FieldType::Water, FieldType::Meadow, 42, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 2, FieldType::Wheat, FieldType::Swamp, 43, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 2, FieldType::Meadow, FieldType::Swamp, 44, Board_Status::InDeck));
    dominoes.push_back(new Domino(2, 0, FieldType::Quarry, FieldType::Wheat, 45, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 2, FieldType::Swamp, FieldType::Quarry, 46, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 2, FieldType::Swamp, FieldType::Quarry, 47, Board_Status::InDeck));
    dominoes.push_back(new Domino(0, 3, FieldType::Wheat, FieldType::Quarry, 48, Board_Status::InDeck));

    std::srand(unsigned(std::time(0)));
    std::random_shuffle(std::begin(dominoes), std::end(dominoes));
}
