#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

Player::Player() {

}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left && pos().x() > 0) {
        setPos(x() - 10, y());
    } else if (event->key() == Qt::Key_Right && pos().x() + rect().width() < 800) {
        setPos(x() + 10, y());
    } else if (event->key() == Qt::Key_Up && pos().y() > 0) {
        setPos(x(), y() - 10);
    } else if (event->key() == Qt::Key_Down && pos().y() + rect().height() < 600) {
        setPos(x(), y() + 10);
    }

    if (event->key() == Qt::Key_Space) {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        scene()->addItem(bullet);
    }
}

void Player::spawn() {
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
