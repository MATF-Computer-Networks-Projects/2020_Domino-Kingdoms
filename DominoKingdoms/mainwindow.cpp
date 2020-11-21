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
#include <QPainter>
#include "domino.hpp"
#include "castle_domino.hpp"

int backIndex = 0;

QPushButton* initializeButton(QString text){
    QPushButton *button = new QPushButton(text);
    button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    return button;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    /* Initializing buttons */
    QGridLayout *mainScreenLayout = new QGridLayout();
    QPushButton *player1button = initializeButton("p1Button");
    QPushButton *player2button = initializeButton("p2Button");
    QPushButton *player3button = initializeButton("p3Button");
    QPushButton *deckButton = initializeButton("Deck");
    QPushButton *optionsButton = initializeButton("Options");
    QPushButton *quitButton = initializeButton("Quit");

    /* Initializing score label */
    QLabel *scores = new QLabel(ui->mainScreen);
    scores->setText("SCORES");
    scores->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    /* Initializing views and scenes */
    QGraphicsView *tableView = new QGraphicsView(ui->mainScreen);
    QGraphicsView *dominoView = new QGraphicsView(ui->mainScreen);
    QGraphicsScene *tableScene = new QGraphicsScene(ui->mainScreen);
    QGraphicsScene *dominoScene = new QGraphicsScene(ui->mainScreen);

    /* Initializing Dominos */

    /* Setting up scenes */
    Domino *d3 = new Domino(200,200,400,200,200,200,0,0,2,1,false,Board_Status::InDeck,FieldType::Water,FieldType::Water);
    tableScene->addItem(d3);

    CastleDomino *castle = new CastleDomino(2);
    tableScene->addItem(castle);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            tableScene->addRect(200*i, 200*j, 200, 200);

    for(int i = 0; i < 4; i++){
        dominoScene->addRect(0, 200*i, 100, 100);
        dominoScene->addRect(100, 200*i, 100, 100);
        dominoScene->addRect(300, 200*i, 100, 100);
        dominoScene->addRect(400, 200*i, 100, 100);
    }

    /* Setting scenes to views */
    tableView->setScene(tableScene);
    dominoView->setScene(dominoScene);

    /* Setting up layout */
    mainScreenLayout->addWidget(player1button, 11, 0, 2, 1);
    mainScreenLayout->addWidget(player2button, 11, 1, 2, 1);
    mainScreenLayout->addWidget(player3button, 11, 2, 2, 1);
    mainScreenLayout->addWidget(deckButton, 0, 9, 1, 1);
    mainScreenLayout->addWidget(optionsButton, 11, 9, 1, 1);
    mainScreenLayout->addWidget(quitButton, 12, 9, 1, 1);
    mainScreenLayout->addWidget(scores, 2, 9, 4, 1);
    mainScreenLayout->addWidget(tableView, 0, 0, 10, 5);
    mainScreenLayout->addWidget(dominoView, 0, 6, 10, 3);

    ui->mainScreen->setLayout(mainScreenLayout);

    /* Connecting buttons */
    connect(player1button, &QPushButton::clicked, this, &MainWindow::optionsButton_clicked);
    connect(quitButton, &QPushButton::clicked, this, &MainWindow::back_to_menu);
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
