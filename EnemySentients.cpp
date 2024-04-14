#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include "EnemySentients.h"
#include "Game.h"

extern Game *game;

EnemySentients::EnemySentients() {

    srand(time(NULL));

    int rand_numb = rand() % 700;
    setPos(rand_numb, 0);

    setRect(0, 0, 120, 80);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void EnemySentients::move() {
    setPos(x(), y() + rand() % 5 + 3);

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (auto elem : colliding_items) {
        if (typeid(*(elem)) == typeid(Player)) {

            game->health->decrease();
            scene()->removeItem(this);
            delete this;

            return;
        }
    }

    if (pos().y() > 600) {
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}
