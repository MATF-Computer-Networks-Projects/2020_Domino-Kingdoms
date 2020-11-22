#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
