/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelIme;
    QLineEdit *unosIme;
    QFrame *line;
    QPushButton *connectdisconnectDugme;
    QFrame *line_2;
    QLabel *labelTvojBroj;
    QTextEdit *tvojBroj;
    QPushButton *uvecajBrojDugme;
    QFrame *line_3;
    QPushButton *saznajDugme;
    QTextBrowser *brojeviSvihIgraca;
    QMenuBar *menuBar;
    QMenu *menuApp;
    QMenu *menuDisconnect;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QStringLiteral("client"));
        client->resize(409, 494);
        centralWidget = new QWidget(client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelIme = new QLabel(centralWidget);
        labelIme->setObjectName(QStringLiteral("labelIme"));

        verticalLayout->addWidget(labelIme);

        unosIme = new QLineEdit(centralWidget);
        unosIme->setObjectName(QStringLiteral("unosIme"));
        QPalette palette;
        QBrush brush(QColor(252, 233, 79, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        QBrush brush1(QColor(204, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Highlight, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        QBrush brush2(QColor(145, 141, 126, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Highlight, brush2);
        unosIme->setPalette(palette);
        unosIme->setAutoFillBackground(false);
        unosIme->setFrame(true);

        verticalLayout->addWidget(unosIme);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        connectdisconnectDugme = new QPushButton(centralWidget);
        connectdisconnectDugme->setObjectName(QStringLiteral("connectdisconnectDugme"));

        verticalLayout->addWidget(connectdisconnectDugme);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        labelTvojBroj = new QLabel(centralWidget);
        labelTvojBroj->setObjectName(QStringLiteral("labelTvojBroj"));

        verticalLayout->addWidget(labelTvojBroj);

        tvojBroj = new QTextEdit(centralWidget);
        tvojBroj->setObjectName(QStringLiteral("tvojBroj"));

        verticalLayout->addWidget(tvojBroj);

        uvecajBrojDugme = new QPushButton(centralWidget);
        uvecajBrojDugme->setObjectName(QStringLiteral("uvecajBrojDugme"));

        verticalLayout->addWidget(uvecajBrojDugme);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        saznajDugme = new QPushButton(centralWidget);
        saznajDugme->setObjectName(QStringLiteral("saznajDugme"));

        verticalLayout->addWidget(saznajDugme);

        brojeviSvihIgraca = new QTextBrowser(centralWidget);
        brojeviSvihIgraca->setObjectName(QStringLiteral("brojeviSvihIgraca"));

        verticalLayout->addWidget(brojeviSvihIgraca);

        client->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(client);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 409, 22));
        menuApp = new QMenu(menuBar);
        menuApp->setObjectName(QStringLiteral("menuApp"));
        menuDisconnect = new QMenu(menuBar);
        menuDisconnect->setObjectName(QStringLiteral("menuDisconnect"));
        client->setMenuBar(menuBar);
        mainToolBar = new QToolBar(client);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        client->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(client);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        client->setStatusBar(statusBar);

        menuBar->addAction(menuApp->menuAction());
        menuBar->addAction(menuDisconnect->menuAction());

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QMainWindow *client)
    {
        client->setWindowTitle(QApplication::translate("client", "client", Q_NULLPTR));
        labelIme->setText(QApplication::translate("client", "Ime:", Q_NULLPTR));
        connectdisconnectDugme->setText(QApplication::translate("client", "Konektuj se", Q_NULLPTR));
        labelTvojBroj->setText(QApplication::translate("client", "Tvoj broj:", Q_NULLPTR));
        uvecajBrojDugme->setText(QApplication::translate("client", "UvecajBroj", Q_NULLPTR));
        saznajDugme->setText(QApplication::translate("client", "Saznaj brojeve drugih", Q_NULLPTR));
        menuApp->setTitle(QApplication::translate("client", "App", Q_NULLPTR));
        menuDisconnect->setTitle(QApplication::translate("client", "Disco&nnect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
