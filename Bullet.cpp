#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"

extern Game *game;

Bullet::Bullet() {
    setRect(50 - rect().width()/2, 0, 10, 50);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Bullet::move() {

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (auto elem : colliding_items) {
        if (typeid(*(elem)) == typeid(Enemy)) {

            game->score->increase();

            scene()->removeItem(elem);
            scene()->removeItem(this);

            delete elem;
            delete this;

            return;
        }
    }

    setPos(x(), y() - 10);
    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
