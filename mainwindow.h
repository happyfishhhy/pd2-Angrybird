#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QDesktopWidget>
#include <QTimer>
#include <Box2D/Box2D.h>
#include <QMouseEvent>
#include <iostream>

#include <gameitem.h>
#include <land.h>
#include <land2.h>
#include <bird.h>
#include <bird2.h>
#include <bird3.h>
#include <bird4.h>
#include <bird5.h>
#include <birdshoot.h>
#include<stone.h>
#include<stoneb.h>
#include<pig.h>
#include<background.h>
#include <QPushButton>
#include <QApplication>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int ix;
    int iy;
    int finalx;
    int finaly;
    int presstime=0;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
signals:
    // Signal for closing the game
    void quitGame();

private slots:
    void tick();
    // For debug slot
    void QUITSLOT();
    void Restart();
    void QUIT();
private:
    Bird *birdie;
    Bird2 *birdie2;
    Bird3 *birdie3;
    Bird4 *birdie4;
    Bird5 *birdie5;

    STONE *stone ;
    STONE *stoneb;
    STONE *stonec ;
    STONE *stoned;
    STONE *stonee ;
    STONE *stonef;
    PIG *pig;
    PIG *pig2;
    //BirdShoot *birdieshoot;
    //BirdShoot *birdieshoot2;
    //BirdShoot *birdieshoot3;
    //BirdShoot *birdieshoot4;
    //BirdShoot *birdieshoot5;

    QPushButton *restart;
    QPushButton *Exit;
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    b2World *world2;
    QList<GameItem *> itemList;
    QTimer timer;
};

#endif // MAINWINDOW_H
