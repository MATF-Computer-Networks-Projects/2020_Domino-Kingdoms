#include "mainwindow.h"
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

int backIndex = 0;
Domino* dominoes[48];
std::unordered_set<Domino*> deckSet;
std::vector<DominoField*> firstRowDF;
std::vector<DominoField*> secondRowDF;

QGraphicsView *tableView;
QGraphicsView *dominoView;
TableScene *tableScene;
DominoScene *dominoScene;

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

    Player *player1 = new Player("prvi", 1);
    Player *player2 = new Player("prvi", 2);
    Player *player3 = new Player("prvi", 3);
    Player *player4 = new Player("prvi", 4);

    srand(time(0));

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
    tableView = new QGraphicsView(ui->mainScreen);
    dominoView = new QGraphicsView(ui->mainScreen);
    tableScene = new TableScene(ui->mainScreen);
    dominoScene = new DominoScene(ui->mainScreen);
    tableScene->setView(tableView);
    dominoScene->setView(dominoView);

    tableScene->setP1(player1);
    dominoScene->setP1(player1);
    tableScene->setOtherScene(dominoScene);
    dominoScene->setOtherScene(tableScene);

    /* Initializing Dominoes */
    dominoes[0] = new Domino(0, 0, FieldType::Wheat, FieldType::Wheat, 1, Board_Status::InDeck);
    dominoes[1] = new Domino(0, 0, FieldType::Wheat, FieldType::Wheat, 2, Board_Status::InDeck);
    dominoes[2] = new Domino(0, 0, FieldType::Forest, FieldType::Forest, 3, Board_Status::InDeck);
    dominoes[3] = new Domino(0, 0, FieldType::Forest, FieldType::Forest, 4, Board_Status::InDeck);
    dominoes[4] = new Domino(0, 0, FieldType::Forest, FieldType::Forest, 5, Board_Status::InDeck);
    dominoes[5] = new Domino(0, 0, FieldType::Forest, FieldType::Forest, 6, Board_Status::InDeck);
    dominoes[6] = new Domino(0, 0, FieldType::Water, FieldType::Water, 7, Board_Status::InDeck);
    dominoes[7] = new Domino(0, 0, FieldType::Water, FieldType::Water, 8, Board_Status::InDeck);
    dominoes[8] = new Domino(0, 0, FieldType::Water, FieldType::Water, 9, Board_Status::InDeck);
    dominoes[9] = new Domino(0, 0, FieldType::Meadow, FieldType::Meadow, 10, Board_Status::InDeck);
    dominoes[10] = new Domino(0, 0, FieldType::Meadow, FieldType::Meadow, 11, Board_Status::InDeck);
    dominoes[11] = new Domino(0, 0, FieldType::Swamp, FieldType::Swamp, 12, Board_Status::InDeck);
    dominoes[12] = new Domino(0, 0, FieldType::Wheat, FieldType::Forest, 13, Board_Status::InDeck);
    dominoes[13] = new Domino(0, 0, FieldType::Wheat, FieldType::Water, 14, Board_Status::InDeck);
    dominoes[14] = new Domino(0, 0, FieldType::Wheat, FieldType::Meadow, 15, Board_Status::InDeck);
    dominoes[15] = new Domino(0, 0, FieldType::Wheat, FieldType::Swamp, 16, Board_Status::InDeck);
    dominoes[16] = new Domino(0, 0, FieldType::Forest, FieldType::Water, 17, Board_Status::InDeck);
    dominoes[17] = new Domino(0, 0, FieldType::Forest, FieldType::Meadow, 18, Board_Status::InDeck);
    dominoes[18] = new Domino(1, 0, FieldType::Wheat, FieldType::Forest, 19, Board_Status::InDeck);
    dominoes[19] = new Domino(1, 0, FieldType::Wheat, FieldType::Water, 20, Board_Status::InDeck);
    dominoes[20] = new Domino(1, 0, FieldType::Wheat, FieldType::Meadow, 21, Board_Status::InDeck);
    dominoes[21] = new Domino(1, 0, FieldType::Wheat, FieldType::Swamp, 22, Board_Status::InDeck);
    dominoes[22] = new Domino(1, 0, FieldType::Wheat, FieldType::Quarry, 23, Board_Status::InDeck);
    dominoes[23] = new Domino(1, 0, FieldType::Forest, FieldType::Wheat, 24, Board_Status::InDeck);
    dominoes[24] = new Domino(1, 0, FieldType::Forest, FieldType::Wheat, 25, Board_Status::InDeck);
    dominoes[25] = new Domino(1, 0, FieldType::Forest, FieldType::Wheat, 26, Board_Status::InDeck);
    dominoes[26] = new Domino(1, 0, FieldType::Forest, FieldType::Wheat, 27, Board_Status::InDeck);
    dominoes[27] = new Domino(1, 0, FieldType::Forest, FieldType::Water, 28, Board_Status::InDeck);
    dominoes[28] = new Domino(1, 0, FieldType::Forest, FieldType::Meadow, 29, Board_Status::InDeck);
    dominoes[29] = new Domino(1, 0, FieldType::Water, FieldType::Wheat, 30, Board_Status::InDeck);
    dominoes[30] = new Domino(1, 0, FieldType::Water, FieldType::Wheat, 31, Board_Status::InDeck);
    dominoes[31] = new Domino(1, 0, FieldType::Water, FieldType::Forest, 32, Board_Status::InDeck);
    dominoes[32] = new Domino(1, 0, FieldType::Water, FieldType::Forest, 33, Board_Status::InDeck);
    dominoes[33] = new Domino(1, 0, FieldType::Water, FieldType::Forest, 34, Board_Status::InDeck);
    dominoes[34] = new Domino(1, 0, FieldType::Water, FieldType::Forest, 35, Board_Status::InDeck);
    dominoes[35] = new Domino(0, 1, FieldType::Wheat, FieldType::Meadow, 36, Board_Status::InDeck);
    dominoes[36] = new Domino(0, 1, FieldType::Water, FieldType::Meadow, 37, Board_Status::InDeck);
    dominoes[37] = new Domino(0, 1, FieldType::Wheat, FieldType::Swamp, 38, Board_Status::InDeck);
    dominoes[38] = new Domino(0, 1, FieldType::Meadow, FieldType::Swamp, 39, Board_Status::InDeck);
    dominoes[39] = new Domino(1, 0, FieldType::Quarry, FieldType::Wheat, 40, Board_Status::InDeck);
    dominoes[40] = new Domino(0, 2, FieldType::Wheat, FieldType::Meadow, 41, Board_Status::InDeck);
    dominoes[41] = new Domino(0, 2, FieldType::Water, FieldType::Meadow, 42, Board_Status::InDeck);
    dominoes[42] = new Domino(0, 2, FieldType::Wheat, FieldType::Swamp, 43, Board_Status::InDeck);
    dominoes[43] = new Domino(0, 2, FieldType::Meadow, FieldType::Swamp, 44, Board_Status::InDeck);
    dominoes[44] = new Domino(2, 0, FieldType::Quarry, FieldType::Wheat, 45, Board_Status::InDeck);
    dominoes[45] = new Domino(0, 2, FieldType::Swamp, FieldType::Quarry, 46, Board_Status::InDeck);
    dominoes[46] = new Domino(0, 2, FieldType::Swamp, FieldType::Quarry, 47, Board_Status::InDeck);
    dominoes[47] = new Domino(0, 3, FieldType::Wheat, FieldType::Quarry, 48, Board_Status::InDeck);

    std::random_shuffle(std::begin(dominoes), std::end(dominoes));

    for(int i = 0; i < 48; i++)
        deckSet.insert(dominoes[i]);

    /* Initializing domino fields */
    for(int i = 0; i < 4; i++)
        firstRowDF.push_back(new DominoField(0, 200*i, 100, 200*i));
    for(int i = 0; i < 4; i++)
        secondRowDF.push_back(new DominoField(300, 200*i, 400, 200*i));

    dominoScene->setFirstRow(&firstRowDF);
    dominoScene->setSecondRow(&secondRowDF);

    /* Setting up scenes */
    CastleDomino *castle = new CastleDomino(2);
    tableScene->addItem(castle);
    player1->set_playerTableField(FieldType::Castle, 0, 2, 2);


    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            tableScene->addRect(150*i, 150*j, 150, 150);

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
    connect(optionsButton, &QPushButton::clicked, this, &MainWindow::optionsButton_clicked);
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
    connect(deckButton, &QPushButton::clicked, this, &MainWindow::take_cards_from_deck);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::back_clicked(){
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
    this->showFullScreen();
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

void MainWindow::take_cards_from_deck(){
    if(firstRowDF[0]->getIsEmpty() && firstRowDF[1]->getIsEmpty() &&
            firstRowDF[2]->getIsEmpty() && firstRowDF[3]->getIsEmpty()){

        for(int i = 0; i < 4; i++){
            auto it = deckSet.begin();
            firstRowDF[i]->setDomino(*it);
            deckSet.erase(it);
        }
        for(int i = 0; i < 4; i++){
            auto it = deckSet.begin();
            secondRowDF[i]->setDomino(*it);
            deckSet.erase(it);
        }
        for(int i = 0; i < 4; i++){
            firstRowDF[i]->getDomino()->setXP1(firstRowDF[i]->getX1());
            firstRowDF[i]->getDomino()->setYP1(firstRowDF[i]->getY1());
            firstRowDF[i]->getDomino()->setXP2(firstRowDF[i]->getX2());
            firstRowDF[i]->getDomino()->setYP2(firstRowDF[i]->getY2());
            firstRowDF[i]->getDomino()->setBoardStatus(Board_Status::OnBoard);
            dominoScene->addItem(firstRowDF[i]->getDomino());
            firstRowDF[i]->setIsEmpty(false);
            secondRowDF[i]->getDomino()->setXP1(secondRowDF[i]->getX1());
            secondRowDF[i]->getDomino()->setYP1(secondRowDF[i]->getY1());
            secondRowDF[i]->getDomino()->setXP2(secondRowDF[i]->getX2());
            secondRowDF[i]->getDomino()->setYP2(secondRowDF[i]->getY2());
            secondRowDF[i]->getDomino()->setBoardStatus(Board_Status::OnBoard);
            dominoScene->addItem(secondRowDF[i]->getDomino());
            secondRowDF[i]->setIsEmpty(false);
        }
    }
    dominoScene->update(dominoView->rect());
}
