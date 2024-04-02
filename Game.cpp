#include <QTimer>

#include "Game.h"
#include "Enemy.h"

Game::Game(QWidget *parent) {

    // create the scene
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0, 0, 800, 600);

    // set the scene
    setScene(this->scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);
    setBackgroundBrush(Qt::black);

    // create the player
    this->player = new Player();
    this->player->setRect(0, 0, 100, 100);
    this->player->setPos(800/2 - this->player->rect().height()/2, 600 - this->player->rect().height());
    this->player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->player->setFocus();
    this->player->setBrush(Qt::green);
    this->scene->addItem(this->player);

    // create the score
    this->score = new Score();
    this->scene->addItem(this->score);

    // create the health
    this->health = new Health();
    this->scene->addItem(this->health);

    // create the enemys
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // update player position
    QTimer *timer1 = new QTimer();
    QObject::connect(timer1, SIGNAL(timeout()), player, SLOT(updatePlayerPosition()));
    timer1->start(20);

    // update player bullets
    QTimer *timer2 = new QTimer();
    QObject::connect(timer2, SIGNAL(timeout()), player, SLOT(updatePlayerBullets()));
    timer2->start(100);
}
