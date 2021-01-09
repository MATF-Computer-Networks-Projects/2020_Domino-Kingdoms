#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include "../../../daLiSamRazumela/server/server/signals.h"

namespace Ui {
class client;
}


class client : public QMainWindow
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    ~client();

private slots:
    void on_connectdisconnectDugme_clicked();
    void socketConnected();
    void socketDisconnected();
    void socketReadyRead();

    void on_uvecajBrojDugme_clicked();

    void on_saznajDugme_clicked();

private:
    Ui::client *ui;
    bool _connected;
    QTcpSocket *clientSocket;
    QString name;
    QDataStream in;
    int number;
    bool should_wait;
    QString msg;
};

#endif // CLIENT_H
