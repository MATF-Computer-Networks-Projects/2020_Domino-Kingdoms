#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <iostream>
#include <QPushButton>
#include <QPixmap>
#include <QStackedWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QScrollBar>
#include <QSizePolicy>
#include <QLabel>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPen>
#include <QBrush>
#include <Qt>
#include <QPainter>
#include <dominofield.h>
#include "domino.hpp"
#include "player.hpp"
#include "castle_domino.hpp"
#include <iterator>
#include <set>
#include <unordered_set>
#include <algorithm>
#include "dominoscene.h"
#include "tablescene.h"
#include "game.h"
#include <QSet>
#include <QTcpSocket>
#include <QDataStream>
#include <QMessageBox>
#include "otherscene.h"

#include "../DominoKingdomsServer/signals.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void newGameButton_clicked();
    void optionsButton_clicked();
    void exitButton_clicked();
    void startLoginButton_clicked();
    void back_clicked();
    void rulesOptionsButton_clicked();
    void back_rules_clicked();
    void back_to_menu();
    void back_to_game();
    void take_cards_from_deck();
    void throw_out_domino_clicked();
    void calculate_player_scores_clicked();

    void getPlayer1Clicked();
    void getPlayer2Clicked();
    void getPlayer3Clicked();


    void joinServerClicked();
    void socketConnected();
    void socketDisconnected();
    void socketReadyRead();

    void recieveUpdate();
    void setDeck();
    void slotReserveDomino();
    void slotUpdateColor();
    void slotChosenDomino();
    void slotMoveIsMade();
    void slotSendCalculatedPoints();

private:
    Ui::MainWindow *ui;

    bool m_connected;
    QTcpSocket *clientsSocket;
    Player *player1;
    QDataStream m_in;
    QString playerName;
    Domino* dominoes[48];
    int m_idOnServer;
    int m_counterTurns;

};

#endif // MAINWINDOW_H
