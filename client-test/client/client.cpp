#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    _connected = false;
    number = 1;
    should_wait = false;
}

client::~client()
{
    delete ui;
}

void client::on_connectdisconnectDugme_clicked()
{
    if(ui->unosIme->text().size() == 0){
        ui->unosIme->setPlaceholderText("UNESI IME!");
        return;
    }
    ui->labelTvojBroj->clear();


    if(!_connected){
        QString clientsName = ui->unosIme->text();
        name = QString(clientsName);

        clientSocket = new QTcpSocket();

        connect(clientSocket, SIGNAL(connected()), this, SLOT(socketConnected()));
        connect(clientSocket, SIGNAL(disconnected()), this, SLOT(socketDisconnected()));
        connect(clientSocket,SIGNAL(readyRead()), this, SLOT(socketReadyRead()));

//        qDebug() << name << " has joined the server";
        clientSocket->connectToHost("127.0.0.1", 8001);

        _connected = true;

        ui->connectdisconnectDugme->setText("Diskonektuj se");
        ui->tvojBroj->setText(QString::number(number));

    }
    else{ // client is connected
        ui->connectdisconnectDugme->setText("Konektuj se");

//        qDebug() << name << " has left the server";
        clientSocket->disconnectFromHost();

        _connected = false;
    }
}

void client::socketConnected()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<<Signals::send_name_init<<name.toUtf8();
    clientSocket->write(block);

    in.setDevice(clientSocket);
    in.setVersion(QDataStream::Qt_5_9);
}

void client::socketDisconnected()
{
//empty
}

void client::socketReadyRead()
{
    in.startTransaction();
    clientSocket->flush();

    int type;

    in>>type;


    if(type == Signals::send_number){
        int n_clients;
        in>>n_clients;
        msg = QString{};
        for (int i = 0;i<n_clients;i++){
            QString name;
            in >> name;
            int num;
            in >> num;
            msg += name + " : " + QString::number(num) + " \n ";
        }

    }

    if(!in.commitTransaction()){
        qDebug()<<"NIJE KOMITOVAO";
        return;
    }
    if(type == Signals::send_number){
        ui->brojeviSvihIgraca->append(msg);
    }
}

void client::on_uvecajBrojDugme_clicked()
{
    number++;
    ui->tvojBroj->clear();
    ui->tvojBroj->setText(QString::number(number));

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<<Signals::number_incremented;
    clientSocket->write(block);
    should_wait = true;
}

void client::on_saznajDugme_clicked()
{
//    if(should_wait){
//        ui->uvecajBrojDugme->setEnabled(false);
//        ui->saznajDugme->setEnabled(false);
//    }
//    ui->uvecajBrojDugme->setEnabled(true);
//    ui->saznajDugme->setEnabled(true);
//    if((ui->brojeviSvihIgraca->document()->blockCount())>6)
//        ui->brojeviSvihIgraca->clear();
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<<Signals::send_request;
    clientSocket->write(block);
    should_wait = true;


}
