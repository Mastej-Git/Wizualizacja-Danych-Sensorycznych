#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <time.h>
#include "Enemy.h"

Enemy::Enemy() {

    srand(time(NULL));

    int rand_numb = rand() % 700;
    setPos(rand_numb, 0);

    setRect(0, 0, 100, 100);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}

void Enemy::move() {
    setPos(x(), y() + rand() % 5 + 3);
    if (pos().y() + rect().height() < 0) {
        scene()->removeItem(this);
        delete this;
    }
}
