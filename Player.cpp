#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <math.h>
#include "Player.h"
#include "Bullet.h"
#include "Flamethrower.h"
#include "Enemy.h"

Player::Player() {
    this->keyLeftPressed = false;
    this->keyRightPressed = false;
    this->keyUpPressed = false;
    this->keyDownPressed = false;
    this->keySpacebarPressed = false;
    this->keyFlamePressed = false;
}

void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        this->keyLeftPressed = true;
    } else if (event->key() == Qt::Key_Right) {
        this->keyRightPressed = true;
    } else if (event->key() == Qt::Key_Up) {
        this->keyUpPressed = true;
    } else if (event->key() == Qt::Key_Down) {
        this->keyDownPressed = true;
    } else if (event->key() == Qt::Key_Space) {
        this->keySpacebarPressed = true;
    } else if (event->key() == Qt::Key_Backspace) {
        this->keyFlamePressed = true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event) {
    // Clear flags when keys are released
    if (event->key() == Qt::Key_Left) {
        this->keyLeftPressed = false;
    } else if (event->key() == Qt::Key_Right) {
        this->keyRightPressed = false;
    } else if (event->key() == Qt::Key_Up) {
        this->keyUpPressed = false;
    } else if (event->key() == Qt::Key_Down) {
        this->keyDownPressed = false;
    } else if (event->key() == Qt::Key_Space) {
        this->keySpacebarPressed = false;
    } else if (event->key() == Qt::Key_Backspace) {
        this->keyFlamePressed = false;
    }
}

void Player::updatePlayerPosition() {
    int dx = 0;
    int dy = 0;

    // Calculate movement in both x and y directions
    if (keyLeftPressed && pos().x() > 0) {
        dx -= 5;
    }
    if (keyRightPressed && pos().x() + rect().width() < 800) {
        dx += 5;
    }
    if (keyUpPressed && pos().y() > 0) {
        dy -= 5;
    }
    if (keyDownPressed && pos().y() + rect().height() < 600) {
        dy += 5;
    }

    // Update player position
    setPos(x() + dx, y() + dy);
}

void Player::updatePlayerBullets() {
    if (keySpacebarPressed) {
        Bullet *bullet = new Bullet();
        bullet->setPos(x(), y());
        bullet->setBrush(Qt::yellow);
        scene()->addItem(bullet);
    }
    if (keyFlamePressed) {
        Flamethrower **flamethrower = new Flamethrower*[5];
        flamethrower[0] = new Flamethrower(-5, -3);
        flamethrower[1] = new Flamethrower(-3, -5);
        flamethrower[2] = new Flamethrower(0, -5);
        flamethrower[3] = new Flamethrower(3, -5);
        flamethrower[4] = new Flamethrower(5, -3);

        for (int i = 0; i < 5; ++i) {
            flamethrower[i]->setPos(x(), y());
            flamethrower[i]->setBrush(Qt::cyan);
            scene()->addItem((flamethrower[i]));
        }
    }
}

//void Player::keyPressEvent(QKeyEvent *event) {
//    if (event->key() == Qt::Key_Left && pos().x() > 0) {
//        setPos(x() - 10, y());
//    }
//    if (event->key() == Qt::Key_Right && pos().x() + rect().width() < 800) {
//        setPos(x() + 10, y());
//    }
//    if (event->key() == Qt::Key_Up && pos().y() > 0) {
//        setPos(x(), y() - 10);
//    }
//    if (event->key() == Qt::Key_Down && pos().y() + rect().height() < 600) {
//        setPos(x(), y() + 10);
//    }

//    if (event->key() == Qt::Key_Space) {
//        Bullet *bullet = new Bullet();
//        bullet->setPos(x(), y());
//        scene()->addItem(bullet);
//    }
//}

void Player::spawn() {
    Enemy *enemy = new Enemy();
    enemy->setBrush(Qt::blue);
    scene()->addItem(enemy);
}
