#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QPushButton>
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
#include<QPainter>
#include "domino.hpp"

int backIndex = 0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QGridLayout *qgl = new QGridLayout();
    QPushButton *bt1 = new QPushButton("p1Button");
    QPushButton *bt2 = new QPushButton("p2Button");
    QPushButton *bt3 = new QPushButton("p3Button");
    QPushButton *bt4 = new QPushButton("Domino1");
    QPushButton *bt5 = new QPushButton("Domino2");
    QPushButton *bt6 = new QPushButton("Domino3");
    QPushButton *bt7 = new QPushButton("Domino4");
    QPushButton *bt8 = new QPushButton("Domino5");
    QPushButton *bt9 = new QPushButton("Domino6");
    QPushButton *bt10 = new QPushButton("Domino7");
    QPushButton *bt11 = new QPushButton("Domino8");
    QPushButton *bt12 = new QPushButton("Deck");
    QPushButton *bt13 = new QPushButton("Options");
    QPushButton *bt14 = new QPushButton("Quit");
    QLabel *scores = new QLabel(ui->mainScreen);
    scores->setText("SCORES");
    scores->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QGraphicsView *qgv = new QGraphicsView(ui->mainScreen);
    QGraphicsScene *qgs = new QGraphicsScene(ui->mainScreen);

    QPixmap pm(":/Images/Images/forest1.jpg");
    pm = pm.scaled(QSize(100,100));
    QGraphicsPixmapItem *qgpmi = qgs->addPixmap(pm);
    qgpmi->setPos(200,200);
/***********************************************************************/

    Domino *d1 = new Domino(500,500,500,600,100,100,2,3,1,0,
                      false,Board_Status::OnBoard,FieldType::Forest,FieldType::Swamp);
    Domino *d2 = new Domino(400,500,400,600,100,100,0,0,0,0,false,
                       Board_Status::InDeck,FieldType::Meadow,FieldType::Swamp);
    qgs->addItem(d1);
    qgs->addItem(d2);


/************************************************************************/

    for(int i = 0; i<19; i++){
        for(int j = 0; j<19; j++){
            QGraphicsItem *rectangle1 = qgs->addRect(100*i, 100*j, 100, 100);
        }
    }
    qgv->setScene(qgs);
    //qgv->fitInView(qgs->sceneRect(), Qt::KeepAspectRatioByExpanding);

    bt1->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt2->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt3->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt4->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt5->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt6->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt7->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt8->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt9->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt10->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt11->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt12->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt13->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    bt14->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    scores->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    qgl->addWidget(bt1, 11, 0, 2, 1);
    qgl->addWidget(bt2, 11, 1, 2, 1);
    qgl->addWidget(bt3, 11, 2, 2, 1);
    qgl->addWidget(bt4, 0, 6, 1, 2);
    qgl->addWidget(bt5, 2, 6, 1, 2);
    qgl->addWidget(bt6, 4, 6, 1, 2);
    qgl->addWidget(bt7, 6, 6, 1, 2);
    qgl->addWidget(bt8, 0, 8, 1, 2);
    qgl->addWidget(bt9, 2, 8, 1, 2);
    qgl->addWidget(bt10, 4, 8, 1, 2);
    qgl->addWidget(bt11, 6, 8, 1, 2);
    qgl->addWidget(bt12, 0, 10, 1, 2);
    qgl->addWidget(bt13, 11, 10, 1, 2);
    qgl->addWidget(bt14, 12, 10, 1, 2);
    qgl->addWidget(scores, 2, 10, 4, 2);

    qgl->addWidget(qgv, 0, 0, 10, 6);

    ui->mainScreen->setLayout(qgl);

    connect(bt13, &QPushButton::clicked, this, &MainWindow::optionsButton_clicked);
    connect(bt14, &QPushButton::clicked, this, &MainWindow::back_to_menu);
    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::newGameButton_clicked);
    connect(ui->optionsButton, &QPushButton::clicked, this, &MainWindow::optionsButton_clicked);
    connect(ui->exitButton, &QPushButton::clicked, this, &MainWindow::exitButton_clicked);
    connect(ui->joinLoginButton, &QPushButton::clicked, this, &MainWindow::startLoginButton_clicked);
    connect(ui->pbHost, &QPushButton::clicked, this, &MainWindow::startLoginButton_clicked);
    connect(ui->rulesOptionsButton, &QPushButton::clicked, this, &MainWindow::rulesOptionsButton_clicked);
    connect(ui->backLoginButton, &QPushButton::clicked, this, &MainWindow::back_clicked);
    connect(ui->backOptionsButton, &QPushButton::clicked, this, &MainWindow::back_clicked);
    connect(ui->backRulesButton, &QPushButton::clicked, this, &MainWindow::back_rules_clicked);
    connect(ui->pbBackNewGame, &QPushButton::clicked, this, &MainWindow::back_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::back_clicked(){
    std::cout << backIndex << std::endl;
    ui->stackedWidget->setCurrentIndex(backIndex);
}

void MainWindow::newGameButton_clicked(){
    backIndex = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::optionsButton_clicked(){
    backIndex = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::exitButton_clicked(){
    close();
}

void MainWindow::startLoginButton_clicked(){
    backIndex = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::rulesOptionsButton_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::back_rules_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::back_to_game(){
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::back_to_menu(){
    ui->stackedWidget->setCurrentIndex(0);
}
