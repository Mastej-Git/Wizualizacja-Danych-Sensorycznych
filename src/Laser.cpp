/**
 * @file Laser.cpp
 * @author Michal Mastej
 * @brief Laser weapon source file. Contains code for all the functions from header file.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <QTimer>
#include <QGraphicsScene>
#include <QList>

#include "../inc/Laser.h"
#include "../inc/EnemySentients.h"
#include "../inc/Game.h"

extern Game *game;

/**
 * @brief Construct a new Laser:: Laser object
 * 
 */
Laser::Laser() {

    setRect(10 - rect().width()/2, -500, 80, 500);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

/**
 * @brief Function to move the Laser and check for collision with other objects or boundries of the screen.
 * 
 */
void Laser::move() {

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (auto elem : colliding_items) {
        if (typeid(*(elem)) == typeid(EnemySentients)) {

            game->score->increase();

            scene()->removeItem(elem);

            delete elem;

            return;
        }
    }

    setRect(50 - rect().width()/2, -500, rect().width() - 5, rect().height());
    if (rect().width() < 10) {
        scene()->removeItem(this);
        delete this;
    }

}
