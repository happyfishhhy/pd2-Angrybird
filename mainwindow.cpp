#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Enable the event Filter
    qApp->installEventFilter(this);

    Exit = new QPushButton(this);
    Exit->setObjectName("E");
    Exit->setStyleSheet("#E{border-image: url(://image/BTN_BG_SW.png)}");
    Exit->setGeometry(QRect(QPoint(130,30), QSize(100,100)));
    connect(Exit,SIGNAL(released()),this,SLOT(QUIT()));
    restart = new QPushButton(this);
    restart->setObjectName("R");
    restart->setStyleSheet("#R{border-image: url(://image/BTN_TRACKPADMENU_RESTART_HIGHLIGHT.png)}");
    restart->setGeometry(QRect(QPoint(20,30), QSize(100,100)));
    connect(restart, SIGNAL(released()), this, SLOT(Restart()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    // Setting the QGraphicsScene
    scene = new QGraphicsScene(0,0,width(),ui->graphicsView->height());
    ui->graphicsView->setScene(scene);
    // Create world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    world2 = new b2World(b2Vec2(0.0f, 0.0f));
    // Setting Size
    GameItem::setGlobalSize(QSizeF(32,18),size());
    // Create ground (You can edit here)
    itemList.push_back(new BACKGROUND(16,9,32,18,QPixmap("://image/background.jpg").scaled(width(),height()),world,scene));
    itemList.push_back(new Land(16,-0.5,32,3,QPixmap(":/ground.png").scaled(width()/32.0*32,height()/18.0*3),world,scene));
    itemList.push_back(new Land(16,18.5,32,1,QPixmap(":/ground.png").scaled(width()/32.0*32,height()/18.0*1),world,scene));
    itemList.push_back(new Land(-0.5,10,1,18,QPixmap(":/ground.png").scaled(width()/32.0*1,height()/18.0*18),world,scene));
    itemList.push_back(new Land(32,10,1,18,QPixmap(":/ground.png").scaled(width()/32.0*1,height()/18.0*18),world,scene));
    //itemList.push_back(new land2(8,-0.5,1.5,3,QPixmap("://image/GROUND2.png").scaled(width()/10,height()/32*2.8),world,scene));

    // Create bird (You can edit here)
    birdie = new Bird(1.75f,10.0f,1.0f,&timer,QPixmap("://image/BIRD_SW_RED_BS_SCREAM.png").scaled(width()/32*2.0,height()/18*2.0),world2,scene);
    //birdie = new Bird(1.75f,2.75f,0.45f,&timer,QPixmap("://image/BIRD_SW_RED_BS_SCREAM.png").scaled(height()/9.0,height()/9.0),world,scene);
    birdie2 = new Bird2(2.5f,3.0f,1.0f,&timer,QPixmap("://image/BIRD_SW_YELLOW_CHEER_2.png").scaled(width()/32*2.0,height()/18*2.0),world,scene);
    birdie3 = new Bird3(5.5f,3.0f,1.5f,&timer,QPixmap("://image/BIRD_GREEN_YELL.png").scaled(width()/32*3.0,height()/18*3.0),world,scene);
    birdie4 = new Bird4(8.5f,3.0f,1.5f,&timer,QPixmap("://image/BIRD_BOOMERANG_COLLISION.png").scaled(width()/32*3.0,height()/18*3.0),world,scene);
    birdie5 = new Bird5(11.5f,3.0f,1.0f,&timer,QPixmap("://image/BIRD_GREY_YELL.png").scaled(width()/32*2.0,height()/18*2.0),world,scene);

    stone = new STONE(21.0f,10.0f,1.0,3.5,&timer,QPixmap("://image/BLOCK_WOOD_2_4.png").scaled(width()/32*1.0,height()/18*3.5),world,scene);
    stoneb = new STONE(25.0f,10.0f,1.0,3.5,&timer,QPixmap("://image/BLOCK_WOOD_2_4.png").scaled(width()/32*1.0,height()/18*3.5),world,scene);
    stonec = new STONE(23.0f,13.0f,6.0,1,&timer,QPixmap("://image/BLOCK_WOOD_1_5.png").scaled(width()/32*6.0,height()/18*1.5),world,scene);
    stoned = new STONE(19.0f,5.0f,1.0,5,&timer,QPixmap("://image/stone2.png").scaled(width()/32*1.0,height()/18*5),world,scene);
    stonee = new STONE(27.0f,5.0f,1.0,5,&timer,QPixmap("://image/stone2.png").scaled(width()/32*1.0,height()/18*5),world,scene);
    stonef = new STONE(23.0f,8.0f,9,1,&timer,QPixmap("://image/stone4.png").scaled(width()/32*9,height()/18*1),world,scene);
    //stoneb = new STONE(27.0f,5.5f,1.5,5,&timer,QPixmap(":/26_158.png").scaled(width()/32*1.5,height()/18*5),world,scene);
    pig = new PIG(23.0f,4.0f,2.0f,&timer,QPixmap("://image/PIGLETTE_KING_07_SMILE.png").scaled(width()/32*4.0,height()/18*4.0),world,scene);
    pig2 = new PIG(23.0f,9.0f,1.0f,&timer,QPixmap("://image/PIGLETTE_HELMET_01_SMILE.png").scaled(width()/32*2.0,height()/18*2.0),world,scene);




    // Setting the Velocity
    birdie->setLinearVelocity(b2Vec2(0,0));
    itemList.push_back(birdie);
    itemList.push_back(stone);
    itemList.push_back(stoneb);
    // Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quitGame()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    // Hint: Notice the Number of every event!
    if(event->type() == QEvent::MouseButtonPress)
    {
        /* TODO : add your code here */

        QMouseEvent *press = static_cast<QMouseEvent *>(event);
        ix = press->globalX();
        iy = press->globalY();
        //if(ix<600 && ix>550.0 && iy<750 && iy>700)
        //{
        //   void;
        //}
        //if(ix<650 && ix>600.0 && iy<750 && iy>700)
        //{
        //    birdieshoot = new BirdShoot(2.0f,10.0f,0.38f,&timer,QPixmap("://image/BIRD_SW_YELLOW_CHEER_2.png").scaled(height()/9.0,height()/9.0),world2,scene);
        //}
        //std::cout << "Press !" << std::endl ;
    }
    if(event->type() == QEvent::MouseMove)
    {
        /* TODO : add your code here */

        //std::cout << "Move !" << std::endl ;
    }
    if(event->type() == QEvent::MouseButtonRelease)
    {
        /* TODO : add your code here */
        presstime++;
        std::cout<<presstime<<std::endl;
        /*if(presstime==2)
        {
            birdieshoot = new BirdShoot(2.0f,10.0f,0.38f,&timer,QPixmap("://image/BIRD_SW_RED_BS_SCREAM.png").scaled(height()/9.0,height()/9.0),world2,scene);
            std::cout<<"new"<<std::endl;
            delete birdie;
        }*/

        /*if(presstime==6)
        {
            birdieshoot = new BirdShoot(2.0f,10.0f,0.38f,&timer,QPixmap("://image/BIRD_SW_YELLOW_CHEER_2.png").scaled(height()/9.0,height()/9.0),world2,scene);
            std::cout<<"new"<<std::endl;
            delete birdie2;
        }*/

        if(presstime==6)
        {
            birdie2->skill();
        }


        /*if(presstime==12)
        {
            birdieshoot = new BirdShoot(2.0f,10.0f,0.5f,&timer,QPixmap("://image/BIRD_GREEN_YELL.png").scaled(height()/7.0,height()/7.0),world2,scene);
            std::cout<<"new"<<std::endl;
            delete birdie3;
        }*/

        if(presstime==10)
        {
            birdie3->skill();
        }

        /*if(presstime==18)
        {
            birdieshoot = new BirdShoot(2.0f,10.0f,0.5f,&timer,QPixmap("://image/BIRD_BOOMERANG_COLLISION.png").scaled(height()/7.0,height()/7.0),world2,scene);
            std::cout<<"new"<<std::endl;
            delete birdie4;
        }*/

        if(presstime==14)
        {
            birdie4->skill();
        }
        if(presstime==18)
        {
            birdie5->skill();
        }

        if(presstime==2)
        {
        //if(ix<600 && ix>500.0 && iy<550 && iy>500)
        {
            delete birdie;

            birdie = new Bird(1.75f,10.0f,1.0f,&timer,QPixmap("://image/BIRD_SW_RED_BS_SCREAM.png").scaled(width()/32*2.0,height()/18*2.0),world,scene);

            QMouseEvent *press = static_cast<QMouseEvent *>(event);
            finalx = press->globalX();
            finaly = press->globalY();
            //if(presstime==4)
            //{
                //birdieshoot2 = new BirdShoot(2.0f,10.0f,0.38f,&timer,QPixmap("://image/BIRD_SW_RED_BS_SCREAM.png").scaled(height()/9.0,height()/9.0),world,scene);
                birdie->setLinearVelocity(b2Vec2((ix-finalx)/25,(finaly-iy)/25));
                //delete birdieshoot;
                std::cout<<"delete"<<std::endl;
                itemList.push_back(birdie);
                delete birdie2;
                birdie2 = new Bird2(1.75f,10.0f,1.0f,&timer,QPixmap("://image/BIRD_SW_YELLOW_CHEER_2.png").scaled(width()/32*2.0,height()/18*2.0),world2,scene);
            //}

        }
        }
        if(presstime==4)
        {
            //if(ix<600 && ix>500.0 && iy<630 && iy>500)
            {
                delete birdie2;
                birdie2 = new Bird2(1.75f,10.0f,1.0f,&timer,QPixmap("://image/BIRD_SW_YELLOW_CHEER_2.png").scaled(width()/32*2.0,height()/18*2.0),world,scene);

                QMouseEvent *press = static_cast<QMouseEvent *>(event);
                finalx = press->globalX();
                finaly = press->globalY();
                //if(presstime==8)
                //{
                //birdieshoot3 = new BirdShoot(2.0f,10.0f,0.45f,&timer,QPixmap("://image/BIRD_SW_YELLOW_CHEER_2.png").scaled(height()/9.0,height()/9.0),world,scene);
                birdie2->setLinearVelocity(b2Vec2((ix-finalx)/25,(finaly-iy)/25));
                //delete birdieshoot;
                std::cout<<"delete"<<std::endl;
                itemList.push_back(birdie2);
                delete birdie3;
                birdie3 = new Bird3(1.75f,10.0f,1.5f,&timer,QPixmap("://image/BIRD_GREEN_YELL.png").scaled(width()/32*3.0,height()/18*3.0),world2,scene);
            }
        }
        if(presstime==8)
        {
            //if(ix<600 && ix>500.0 && iy<630 && iy>500)
            {
                delete birdie3;
                birdie3 = new Bird3(1.75f,10.0f,1.5f,&timer,QPixmap("://image/BIRD_GREEN_YELL.png").scaled(width()/32*3.0,height()/18*3.0),world,scene);
                QMouseEvent *press = static_cast<QMouseEvent *>(event);
                finalx = press->globalX();
                finaly = press->globalY();
                //if(presstime==8)
                //{
                //birdieshoot4 = new BirdShoot(2.0f,10.0f,0.5f,&timer,QPixmap("://image/BIRD_GREEN_YELL.png").scaled(height()/7.0,height()/7.0),world,scene);
                birdie3->setLinearVelocity(b2Vec2((ix-finalx)/25,(finaly-iy)/25));
                //delete birdieshoot;
                std::cout<<"delete"<<std::endl;
                itemList.push_back(birdie3);
                delete birdie4;
                birdie4 = new Bird4(1.75f,10.0f,1.5f,&timer,QPixmap("://image/BIRD_BOOMERANG_COLLISION.png").scaled(width()/32*3.0,height()/18*3.0),world2,scene);
            }
        }
        if(presstime==12)
        {
            //if(ix<600 && ix>500.0 && iy<630 && iy>500)
            {
                delete birdie4;
                birdie4 = new Bird4(1.75f,10.0f,1.5f,&timer,QPixmap("://image/BIRD_BOOMERANG_COLLISION.png").scaled(width()/32*3.0,height()/18*3.0),world,scene);
                QMouseEvent *press = static_cast<QMouseEvent *>(event);
                finalx = press->globalX();
                finaly = press->globalY();
                //if(presstime==8)
                //{
                //birdieshoot5 = new BirdShoot(2.0f,10.0f,0.5f,&timer,QPixmap("://image/BIRD_BOOMERANG_COLLISION.png").scaled(height()/7.0,height()/7.0),world,scene);
                birdie4->setLinearVelocity(b2Vec2((ix-finalx)/25,(finaly-iy)/25));
                //delete birdieshoot;
                std::cout<<"delete"<<std::endl;
                itemList.push_back(birdie4);
                delete birdie5;
                birdie5 = new Bird5(1.75f,10.0f,1.0f,&timer,QPixmap("://image/BIRD_GREY_YELL.png").scaled(width()/32*2.0,height()/18*2.0),world2,scene);
            }
        }
        if(presstime==16)
        {
            //if(ix<600 && ix>500.0 && iy<630 && iy>500)
            {
                delete birdie5;
                birdie5 = new Bird5(1.75f,10.0f,1.0f,&timer,QPixmap("://image/BIRD_GREY_YELL.png").scaled(width()/32*2.0,height()/18*2.0),world,scene);
                QMouseEvent *press = static_cast<QMouseEvent *>(event);
                finalx = press->globalX();
                finaly = press->globalY();
                //if(presstime==8)
                //{
                //birdieshoot4 = new BirdShoot(2.0f,10.0f,0.5f,&timer,QPixmap("://image/BIRD_GREEN_YELL.png").scaled(height()/7.0,height()/7.0),world,scene);
                birdie5->setLinearVelocity(b2Vec2((ix-finalx)/25,(finaly-iy)/25));
                //delete birdieshoot;
                std::cout<<"delete"<<std::endl;
                itemList.push_back(birdie5);
            }
        }
            //std::cout << "Release !" << std::endl ;
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    // Close event
    emit quitGame();
}

void MainWindow::tick()
{
    world->Step(1.0/60.0,6,2);
    scene->update();
}

void MainWindow::QUITSLOT()
{
    // For debug
    std::cout << "Quit Game Signal receive !" << std::endl ;
    exit(0);
}

void MainWindow::QUIT()
{
    emit quitGame();
}

void MainWindow::Restart()
{
    delete birdie;
    delete birdie2;
    delete birdie3;
    delete birdie4;
    delete birdie5;
    delete stone;
    delete stoneb;
    delete stonec;
    delete stoned;
    delete stonee;
    delete stonef;
    delete pig;
    delete pig2;
    birdie = new Bird(1.75f,10.0f,1.0f,&timer,QPixmap("://image/BIRD_SW_RED_BS_SCREAM.png").scaled(width()/32*2.0,height()/18*2.0),world2,scene);
    birdie2 = new Bird2(2.5f,3.0f,1.0f,&timer,QPixmap("://image/BIRD_SW_YELLOW_CHEER_2.png").scaled(width()/32*2.0,height()/18*2.0),world,scene);
    birdie3 = new Bird3(5.5f,3.0f,1.5f,&timer,QPixmap("://image/BIRD_GREEN_YELL.png").scaled(width()/32*3.0,height()/18*3.0),world,scene);
    birdie4 = new Bird4(8.5f,3.0f,1.5f,&timer,QPixmap("://image/BIRD_BOOMERANG_COLLISION.png").scaled(width()/32*3.0,height()/18*3.0),world,scene);
    birdie5 = new Bird5(11.5f,3.0f,1.0f,&timer,QPixmap("://image/BIRD_GREY_YELL.png").scaled(width()/32*2.0,height()/18*2.0),world,scene);
    stone = new STONE(21.0f,10.0f,1.0,3.5,&timer,QPixmap("://image/BLOCK_WOOD_2_4.png").scaled(width()/32*1.0,height()/18*3.5),world,scene);
    stoneb = new STONE(25.0f,10.0f,1.0,3.5,&timer,QPixmap("://image/BLOCK_WOOD_2_4.png").scaled(width()/32*1.0,height()/18*3.5),world,scene);
    stonec = new STONE(23.0f,13.0f,6.0,1,&timer,QPixmap("://image/BLOCK_WOOD_1_5.png").scaled(width()/32*6.0,height()/18*1.5),world,scene);
    stoned = new STONE(19.0f,5.0f,1.0,5,&timer,QPixmap("://image/stone2.png").scaled(width()/32*1.0,height()/18*5),world,scene);
    stonee = new STONE(27.0f,5.0f,1.0,5,&timer,QPixmap("://image/stone2.png").scaled(width()/32*1.0,height()/18*5),world,scene);
    stonef = new STONE(23.0f,8.0f,9,1,&timer,QPixmap("://image/stone4.png").scaled(width()/32*9,height()/18*1),world,scene);
    pig = new PIG(23.0f,4.0f,2.0f,&timer,QPixmap("://image/PIGLETTE_KING_07_SMILE.png").scaled(width()/32*4.0,height()/18*4.0),world,scene);
    pig2 = new PIG(23.0f,9.0f,1.0f,&timer,QPixmap("://image/PIGLETTE_HELMET_01_SMILE.png").scaled(width()/32*2.0,height()/18*2.0),world,scene);
    presstime=0;
}
