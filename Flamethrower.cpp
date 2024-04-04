#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Flamethrower.h"
#include "Enemy.h"
#include "Game.h"

extern Game *game;

Flamethrower::Flamethrower(double x_move, double y_move) {
    setRect(50 - rect().width()/2, 0, 10, 10);

    this->x_move = x_move;
    this->y_move = y_move;

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

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
