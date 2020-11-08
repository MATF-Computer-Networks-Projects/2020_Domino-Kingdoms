/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_8;
    QStackedWidget *stackedWidget;
    QWidget *menuScreen;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *menuScreenTitle;
    QPushButton *newGameButton;
    QPushButton *optionsButton;
    QPushButton *exitButton;
    QWidget *loginScreen;
    QVBoxLayout *verticalLayout_7;
    QFormLayout *formLayout;
    QLabel *nameForm;
    QLabel *roomCodeForm;
    QTextEdit *textEditRoomCode;
    QTextEdit *textEditName;
    QPushButton *backLoginButton;
    QPushButton *startLoginButton;
    QWidget *optionsScreen;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QSlider *horizontalSlider;
    QPushButton *rulesOptionsButton;
    QPushButton *backOptionsButton;
    QWidget *rulesScreen;
    QLabel *label_5;
    QPushButton *backRulesButton;
    QWidget *mainScreen;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(955, 685);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_8 = new QVBoxLayout(centralWidget);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        menuScreen = new QWidget();
        menuScreen->setObjectName(QStringLiteral("menuScreen"));
        verticalLayout_4 = new QVBoxLayout(menuScreen);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(8);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(30, 0, 30, 50);
        menuScreenTitle = new QLabel(menuScreen);
        menuScreenTitle->setObjectName(QStringLiteral("menuScreenTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuScreenTitle->sizePolicy().hasHeightForWidth());
        menuScreenTitle->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        menuScreenTitle->setFont(font);
        menuScreenTitle->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(menuScreenTitle);

        newGameButton = new QPushButton(menuScreen);
        newGameButton->setObjectName(QStringLiteral("newGameButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(newGameButton->sizePolicy().hasHeightForWidth());
        newGameButton->setSizePolicy(sizePolicy1);
        newGameButton->setMinimumSize(QSize(0, 0));
        newGameButton->setMaximumSize(QSize(155151, 1515115));
        QFont font1;
        font1.setPointSize(24);
        newGameButton->setFont(font1);
        newGameButton->setAutoRepeatInterval(97);

        verticalLayout_5->addWidget(newGameButton);

        optionsButton = new QPushButton(menuScreen);
        optionsButton->setObjectName(QStringLiteral("optionsButton"));
        sizePolicy1.setHeightForWidth(optionsButton->sizePolicy().hasHeightForWidth());
        optionsButton->setSizePolicy(sizePolicy1);
        optionsButton->setFont(font1);

        verticalLayout_5->addWidget(optionsButton);

        exitButton = new QPushButton(menuScreen);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        sizePolicy1.setHeightForWidth(exitButton->sizePolicy().hasHeightForWidth());
        exitButton->setSizePolicy(sizePolicy1);
        exitButton->setFont(font1);

        verticalLayout_5->addWidget(exitButton);


        verticalLayout_4->addLayout(verticalLayout_5);

        stackedWidget->addWidget(menuScreen);
        loginScreen = new QWidget();
        loginScreen->setObjectName(QStringLiteral("loginScreen"));
        verticalLayout_7 = new QVBoxLayout(loginScreen);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        nameForm = new QLabel(loginScreen);
        nameForm->setObjectName(QStringLiteral("nameForm"));

        formLayout->setWidget(0, QFormLayout::LabelRole, nameForm);

        roomCodeForm = new QLabel(loginScreen);
        roomCodeForm->setObjectName(QStringLiteral("roomCodeForm"));

        formLayout->setWidget(1, QFormLayout::LabelRole, roomCodeForm);

        textEditRoomCode = new QTextEdit(loginScreen);
        textEditRoomCode->setObjectName(QStringLiteral("textEditRoomCode"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEditRoomCode);

        textEditName = new QTextEdit(loginScreen);
        textEditName->setObjectName(QStringLiteral("textEditName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEditName);

        backLoginButton = new QPushButton(loginScreen);
        backLoginButton->setObjectName(QStringLiteral("backLoginButton"));
        sizePolicy1.setHeightForWidth(backLoginButton->sizePolicy().hasHeightForWidth());
        backLoginButton->setSizePolicy(sizePolicy1);

        formLayout->setWidget(3, QFormLayout::FieldRole, backLoginButton);

        startLoginButton = new QPushButton(loginScreen);
        startLoginButton->setObjectName(QStringLiteral("startLoginButton"));

        formLayout->setWidget(2, QFormLayout::FieldRole, startLoginButton);


        verticalLayout_7->addLayout(formLayout);

        stackedWidget->addWidget(loginScreen);
        optionsScreen = new QWidget();
        optionsScreen->setObjectName(QStringLiteral("optionsScreen"));
        verticalLayout_6 = new QVBoxLayout(optionsScreen);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_4 = new QLabel(optionsScreen);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(30);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_4);

        horizontalSlider = new QSlider(optionsScreen);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(horizontalSlider);

        rulesOptionsButton = new QPushButton(optionsScreen);
        rulesOptionsButton->setObjectName(QStringLiteral("rulesOptionsButton"));
        sizePolicy1.setHeightForWidth(rulesOptionsButton->sizePolicy().hasHeightForWidth());
        rulesOptionsButton->setSizePolicy(sizePolicy1);
        rulesOptionsButton->setFont(font1);

        verticalLayout_6->addWidget(rulesOptionsButton);

        backOptionsButton = new QPushButton(optionsScreen);
        backOptionsButton->setObjectName(QStringLiteral("backOptionsButton"));
        sizePolicy1.setHeightForWidth(backOptionsButton->sizePolicy().hasHeightForWidth());
        backOptionsButton->setSizePolicy(sizePolicy1);
        backOptionsButton->setFont(font1);

        verticalLayout_6->addWidget(backOptionsButton);

        stackedWidget->addWidget(optionsScreen);
        rulesScreen = new QWidget();
        rulesScreen->setObjectName(QStringLiteral("rulesScreen"));
        label_5 = new QLabel(rulesScreen);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(5, 5, 211, 121));
        backRulesButton = new QPushButton(rulesScreen);
        backRulesButton->setObjectName(QStringLiteral("backRulesButton"));
        backRulesButton->setGeometry(QRect(690, 510, 231, 71));
        stackedWidget->addWidget(rulesScreen);
        mainScreen = new QWidget();
        mainScreen->setObjectName(QStringLiteral("mainScreen"));
        stackedWidget->addWidget(mainScreen);

        verticalLayout_8->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 955, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        menuScreenTitle->setText(QApplication::translate("MainWindow", "DOMINO KINGDOMS", Q_NULLPTR));
        newGameButton->setText(QApplication::translate("MainWindow", "NEW GAME", Q_NULLPTR));
        optionsButton->setText(QApplication::translate("MainWindow", "OPTIONS", Q_NULLPTR));
        exitButton->setText(QApplication::translate("MainWindow", "EXIT", Q_NULLPTR));
        nameForm->setText(QApplication::translate("MainWindow", "Name:", Q_NULLPTR));
        roomCodeForm->setText(QApplication::translate("MainWindow", "Room code:", Q_NULLPTR));
        backLoginButton->setText(QApplication::translate("MainWindow", "BACK", Q_NULLPTR));
        startLoginButton->setText(QApplication::translate("MainWindow", "START", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "VOLUME", Q_NULLPTR));
        rulesOptionsButton->setText(QApplication::translate("MainWindow", "GAME RULES", Q_NULLPTR));
        backOptionsButton->setText(QApplication::translate("MainWindow", "BACK", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "GAME RULES:", Q_NULLPTR));
        backRulesButton->setText(QApplication::translate("MainWindow", "BACK", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
