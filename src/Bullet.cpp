/**
 * @file Bullet.cpp
 * @author Michal Mastej
 * @brief This is a Bullet source file. Contains code for all the functions from header file.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include "../inc/Bullet.h"
#include "../inc/EnemyCyborg.h"
#include "../inc/Game.h"
#include "../inc/Score.h"
#include "../inc/Health.h"

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

        if (typeid(*(elem)) == typeid(EnemyCyborg)) {

            game->score->increase();

            scene()->removeItem(elem);
            scene()->removeItem(this);

            delete elem;
            delete this;

            return;
        }

        else if (typeid(*(elem)) != typeid(EnemyCyborg) && typeid(*(elem)) != typeid(Player) && typeid(*(elem)) != typeid(Bullet)) {
            scene()->removeItem(this);
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
