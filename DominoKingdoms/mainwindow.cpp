#include "mainwindow.h"


int backIndex = 0;
//Domino* dominoes[48];
QSet<Domino*> deckSet;
std::vector<DominoField*> firstColumnDF;
std::vector<DominoField*> secondColumnDF;

QGraphicsView *tableView;
QGraphicsView *dominoView;
TableScene *tableScene;
DominoScene *dominoScene;
OtherScene *otherScene;
Player *player1;
Game *game;

QGraphicsView *otherView;

bool firstTime1 = true;
bool firstTime2 = true;

QPushButton* initializeButton(QString text){
    QPushButton *button = new QPushButton(text);
    button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    return button;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    setDeck();
    m_connected = false;

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

    player1 = new Player("maria", 1);

    game = new Game();

    srand(time(0));

    /* Initializing buttons */
    QGridLayout *mainScreenLayout = new QGridLayout();
    QPushButton *player1button = initializeButton("p1Button");
    QPushButton *player2button = initializeButton("p2Button");
    QPushButton *player3button = initializeButton("p3Button");
    QPushButton *throwOutButton = initializeButton("Throw Out");
    QPushButton *calculateButton = initializeButton("Calculate");
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
    otherView = new QGraphicsView(ui->mainScreen);

    tableScene = new TableScene(ui->mainScreen);
    dominoScene = new DominoScene(ui->mainScreen);
    otherScene = new OtherScene(ui->mainScreen);

    tableScene->setView(tableView);
    dominoScene->setView(dominoView);
    otherScene->setView(otherView);

    tableScene->setP1(player1);
    dominoScene->setP1(player1);
    otherScene->setP1(player1);

    tableScene->setOtherScene(dominoScene);
    dominoScene->setOtherScene(tableScene);



    QGridLayout *otherSceneLayout = new QGridLayout();
    QPushButton *otherBack = initializeButton("Back");

    otherSceneLayout->addWidget(otherView, 0, 0, 10, 5);
    otherSceneLayout->addWidget(otherBack, 10, 6, 1, 1);

    ui->OtherPlayerScreen->setLayout(otherSceneLayout);

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            otherScene->addRect(100*i, 100*j, 100, 100);

    otherView->setScene(otherScene);

    otherScene->update(otherView->rect());


//    for(int i = 0; i < 48; i++)
//        deckSet.insert(dominoes[i]);

    /* Initializing domino fields */
    for(int i = 0; i < 4; i++)
        firstColumnDF.push_back(new DominoField(0, 200*i, 100, 200*i));
    for(int i = 0; i < 4; i++)
        secondColumnDF.push_back(new DominoField(300, 200*i, 400, 200*i));

    dominoScene->setFirstRow(&firstColumnDF);
    dominoScene->setSecondRow(&secondColumnDF);
    tableScene->setCurrentPlayer(player1);

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
    mainScreenLayout->addWidget(throwOutButton, 11, 3, 2, 1);
    mainScreenLayout->addWidget(calculateButton, 11, 4, 2, 1);
    mainScreenLayout->addWidget(deckButton, 0, 9, 1, 1);
    mainScreenLayout->addWidget(optionsButton, 11, 9, 1, 1);
    mainScreenLayout->addWidget(quitButton, 12, 9, 1, 1);
    mainScreenLayout->addWidget(scores, 2, 9, 4, 1);
    mainScreenLayout->addWidget(tableView, 0, 0, 10, 5);
    mainScreenLayout->addWidget(dominoView, 0, 6, 10, 3);

    ui->mainScreen->setLayout(mainScreenLayout);
    ui->OtherPlayerScreen->setLayout(otherSceneLayout);



    otherScene->update(otherView->rect());

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
    connect(throwOutButton, &QPushButton::clicked, this, &MainWindow::throw_out_domino_clicked);
    connect(calculateButton, &QPushButton::clicked, this, &MainWindow::calculate_player_scores_clicked);
    connect(otherBack, &QPushButton::clicked, this, &MainWindow::back_to_game);

    connect(ui->pbJoin, &QPushButton::clicked, this, &MainWindow::joinServerClicked);

    connect(player1button,&QPushButton::clicked,this,&MainWindow::getPlayer1Clicked);
    connect(player2button,&QPushButton::clicked,this,&MainWindow::getPlayer2Clicked);
    connect(player3button,&QPushButton::clicked,this,&MainWindow::getPlayer3Clicked);

    connect(tableScene, &TableScene::updatedTable, this, &MainWindow::recieveUpdate);
    connect(dominoScene,&DominoScene::signalReservedDomino,this,&MainWindow::slotReserveDomino);

}

void MainWindow::slotReserveDomino()
{
    //komunikacija sa serverom
    int pid = dominoScene->sPlayerId;
    int row = dominoScene->sDominoFieldNumber;

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);

    out<<Signals::send_reserve;
    out<<pid<<row;

    clientsSocket->write(block);

}

void MainWindow::setDeck()
{
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
    otherScene->clear();
}

void MainWindow::back_to_menu(){
    ui->stackedWidget->setCurrentIndex(0);
}

bool isEmptyColumn1(){
    if(firstColumnDF[0]->getIsEmpty() && firstColumnDF[1]->getIsEmpty() &&
            firstColumnDF[2]->getIsEmpty() && firstColumnDF[3]->getIsEmpty())
        return true;
    return false;
}

bool isEmptyColumn2(){
    if(secondColumnDF[0]->getIsEmpty() && secondColumnDF[1]->getIsEmpty() &&
            secondColumnDF[2]->getIsEmpty() && secondColumnDF[3]->getIsEmpty())
        return true;
    return false;
}

void MainWindow::take_cards_from_deck(){

    if(!isEmptyColumn1() && !isEmptyColumn2()){
        QMessageBox qmb;
        qmb.setText("Ne moze bez kabla");
        qmb.exec();
    }

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<<Signals::request_cards;

    clientsSocket->write(block);

//    if(deckSet.size() <= 0){
//        std::cout << "dosta ste se kartali" << std::endl;
//        return;
//    }

//    std::vector<Domino *> temp;
//    temp.clear();
//    if(isEmptyColumn1()){
//        for(int i = 0; i < 4; i++){
//            auto it = deckSet.begin();
//            temp.push_back(*it);
//            deckSet.erase(it);
//        }

//        std::sort(temp.begin(), temp.end(), [](Domino *d1, Domino *d2){
//            return d1->getValue() < d2->getValue();
//        });

//        for(int i = 0; i < 4; i++){
//            firstColumnDF[i]->setDomino(temp[i]);
//            firstColumnDF[i]->getDomino()->setXP1(firstColumnDF[i]->getX1());
//            firstColumnDF[i]->getDomino()->setYP1(firstColumnDF[i]->getY1());
//            firstColumnDF[i]->getDomino()->setXP2(firstColumnDF[i]->getX2());
//            firstColumnDF[i]->getDomino()->setYP2(firstColumnDF[i]->getY2());
//            firstColumnDF[i]->getDomino()->setBoardStatus(Board_Status::OnBoard);
////            firstColumnDF[i]->getDomino()->setPlayer(player1);
//            dominoScene->addItem(firstColumnDF[i]->getDomino());
//            firstColumnDF[i]->getDomino()->setS_id(i+1);
//            firstColumnDF[i]->setIsEmpty(false);
//        }
//        dominoScene->setActiveColumn(2);
//        if(!firstTime1){
//            game->setupQueue(secondColumnDF);
//            firstTime1 = false;
//        }
//    }
//    temp.clear();
//    if(isEmptyColumn2()){
//        for(int i = 0; i < 4; i++){
//            auto it = deckSet.begin();
//            temp.push_back(*it);
//            deckSet.erase(it);
//        }

//        std::sort(temp.begin(), temp.end(), [](Domino *d1, Domino *d2){
//            return d1->getValue() < d2->getValue();
//        });

//        for(int i = 0; i < 4; i++){
//            secondColumnDF[i]->setDomino(temp[i]);
//            secondColumnDF[i]->getDomino()->setXP1(secondColumnDF[i]->getX1());
//            secondColumnDF[i]->getDomino()->setYP1(secondColumnDF[i]->getY1());
//            secondColumnDF[i]->getDomino()->setXP2(secondColumnDF[i]->getX2());
//            secondColumnDF[i]->getDomino()->setYP2(secondColumnDF[i]->getY2());
//            secondColumnDF[i]->getDomino()->setBoardStatus(Board_Status::OnBoard);
////            secondColumnDF[i]->getDomino()->setPlayer(player1);
//            dominoScene->addItem(secondColumnDF[i]->getDomino());
//            secondColumnDF[i]->getDomino()->setS_id(i+5);
//            secondColumnDF[i]->setIsEmpty(false);
//        }
//        dominoScene->setActiveColumn(1);
//        if(!firstTime2){
//            game->setupQueue(firstColumnDF);
//            firstTime2 = false;
//        }
//    }
//    if(!isEmptyColumn1() && !isEmptyColumn2()){
//        std::cout << "Ne mozes da delis karte sad" << std::endl;
//        return;
//    }

//    dominoScene->update(dominoView->rect());
}

void MainWindow::throw_out_domino_clicked()
{
    if(tableScene->clickedDomino()->opacity() == 0.4)
        return;
    tableScene->removeItem(tableScene->clickedDomino());
    tableScene->clickedDomino()->hide();
    tableScene->setClickedDomino(nullptr);
    tableScene->update(tableScene->view()->rect());
    tableScene->currentPlayer()->setNextTask(NextTaskDomino::ReserveDomino);
}

void MainWindow::calculate_player_scores_clicked()
{
    int points = player1->calculatePoints();
    std::cout << points << std::endl;
}

void MainWindow::getPlayer1Clicked()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<<Signals::request_player1;

    clientsSocket->write(block);

    backIndex = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::getPlayer2Clicked()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<<Signals::request_player2;

    clientsSocket->write(block);

    backIndex = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::getPlayer3Clicked()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<<Signals::request_player3;

    clientsSocket->write(block);

    backIndex = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::joinServerClicked()
{
    playerName = ui->leName->text();
    if(playerName == ""){
        ui->leName->setPlaceholderText("Provide a name");
        return;
    }

    backIndex = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(4);
    this->showFullScreen();
    std::cout << ui->leName->text().toStdString() << std::endl;

    clientsSocket = new QTcpSocket();

    connect(clientsSocket,SIGNAL(connected()),this,SLOT(socketConnected()));
    connect(clientsSocket,SIGNAL(disconnected()),this,SLOT(socketDisconnected()));
    connect(clientsSocket,SIGNAL(readyRead()),this,SLOT(socketReadyRead()));

    clientsSocket->connectToHost("192.168.1.15",8001);

}

void MainWindow::socketConnected()
{

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<<(int)Signals::send_name<<playerName.toUtf8();

    clientsSocket->write(block);

    m_in.setDevice(clientsSocket);
    m_in.setVersion(QDataStream::Qt_5_9);
}

void MainWindow::socketDisconnected()
{

}

void MainWindow::socketReadyRead()
{
    m_in.startTransaction();
    int type;
    m_in>>type;

    if(type == Signals::sending_table){
     //otherScene->clear();
        Field* field;
        int nxp1;
        int nyp1;
        int nft1;
        int nc1;
        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                m_in>>nxp1>>nyp1>>nft1>>nc1;
                std::cout<<nxp1<<nyp1<<nft1<<nc1<<std::endl;

                field = new Field((FieldType)nft1,nc1);
                field->setPos(j*100,i*100);
                otherScene->addItem(field);
            }
        }
        otherScene->update(otherScene->view()->rect());

    }

    else if(type == Signals::player_not_found){
        std::cout<<"dobio signal player not found"<<std::endl;
        QMessageBox mb;
        mb.setText("Player not found!");
        mb.setIcon(QMessageBox::Warning);
        mb.exec();
    }

    else if(type == Signals::send_reserve){
        int pid;
        m_in>>pid;
        int row;
        m_in>>row;

        if(row >= 1 && row <= 4)
            firstColumnDF[row-1]->getDomino()->setPlayer(new Player("que",pid));
        else if(row >= 5 && row <= 8)
            secondColumnDF[row-5]->getDomino()->setPlayer(new Player("por",pid));

        dominoScene->update(dominoScene->view()->rect());
    }

    else if(type == Signals::sending_cards){

        int value[4];
        for(int i = 0; i < 4; i++)
            m_in >> value[i];

        if(isEmptyColumn1()){
            for(int i = 0; i < 4; i++){
                firstColumnDF[i]->setDomino(dominoes[value[i]]);
                firstColumnDF[i]->getDomino()->setXP1(firstColumnDF[i]->getX1());
                firstColumnDF[i]->getDomino()->setYP1(firstColumnDF[i]->getY1());
                firstColumnDF[i]->getDomino()->setXP2(firstColumnDF[i]->getX2());
                firstColumnDF[i]->getDomino()->setYP2(firstColumnDF[i]->getY2());
                firstColumnDF[i]->getDomino()->setBoardStatus(Board_Status::OnBoard);
                dominoScene->addItem(firstColumnDF[i]->getDomino());
                firstColumnDF[i]->getDomino()->setS_id(i+1);
                firstColumnDF[i]->setIsEmpty(false);
            }
            dominoScene->setActiveColumn(2);
        }
        else if(isEmptyColumn2()){
            for(int i = 0; i < 4; i++){
                secondColumnDF[i]->setDomino(dominoes[value[i]]);
                secondColumnDF[i]->getDomino()->setXP1(secondColumnDF[i]->getX1());
                secondColumnDF[i]->getDomino()->setYP1(secondColumnDF[i]->getY1());
                secondColumnDF[i]->getDomino()->setXP2(secondColumnDF[i]->getX2());
                secondColumnDF[i]->getDomino()->setYP2(secondColumnDF[i]->getY2());
                secondColumnDF[i]->getDomino()->setBoardStatus(Board_Status::OnBoard);
                dominoScene->addItem(secondColumnDF[i]->getDomino());
                secondColumnDF[i]->getDomino()->setS_id(i+1);
                secondColumnDF[i]->setIsEmpty(false);
            }
            dominoScene->setActiveColumn(1);
        }

        dominoScene->update(dominoScene->view()->rect());
    }

    if(!m_in.commitTransaction()){
        return;
    }
}

void MainWindow::recieveUpdate()
{
    int nxp1 = tableScene->xp1;
    int nxp2 = tableScene->xp2;
    int nyp1 = tableScene->yp1;
    int nyp2 = tableScene->yp2;
    int nft1 = tableScene->ft1;
    int nft2 = tableScene->ft2;
    int nc1 = tableScene->c1;
    int nc2 = tableScene->c2;

    QByteArray block;
    QDataStream out(&block,QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_9);
    out<<Signals::send_update;
    out<<nxp1<<nyp1<<nft1<<nc1;
    out<<nxp2<<nyp2<<nft2<<nc2;

    clientsSocket->write(block);
}
