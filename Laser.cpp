#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Laser.h"
#include "EnemySentients.h"
#include "Game.h"

extern Game *game;

Laser::Laser() {

    setRect(10 - rect().width()/2, -500, 80, 500);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

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
