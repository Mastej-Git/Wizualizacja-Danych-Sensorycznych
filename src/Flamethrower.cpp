/**
 * @file Flamethrower.cpp
 * @author Michal Mastej
 * @brief This is a Flamethrower weapon source file. Contains code for all the functions from header file.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include "../inc/Flamethrower.h"
#include "../inc/Enemy.h"
#include "../inc/Game.h"

extern Game *game;

/**
 * @brief Construct a new Flamethrower:: Flamethrower object
 * 
 * @param x_move describes which way should the Flamethrower particle go on X axis
 * @param y_move describes which way should the Flamethrower particle go on Y axis
 */
Flamethrower::Flamethrower(double x_move, double y_move) {
    setRect(50 - rect().width()/2, 0, 10, 10);

    this->x_move = x_move;
    this->y_move = y_move;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

/**
 * @brief Function to move the Flamthrower and check for collision with other objects or boundries of the screen.
 * 
 */
void Flamethrower::move() {

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
        else if (typeid(*(elem)) != typeid(Enemy) && typeid(*(elem)) != typeid(Player) && typeid(*(elem)) != typeid(Flamethrower)) {
            scene()->removeItem(this);
            delete this;

            return;
        }
    }

    setPos(x() + this->x_move, y() + this->y_move);
    if (pos().y() + rect().height() < 0 || pos().y() > 600 || pos().x() + rect().width() < 0 || pos().x() > 800) {
        scene()->removeItem(this);
        delete this;
    }
}
