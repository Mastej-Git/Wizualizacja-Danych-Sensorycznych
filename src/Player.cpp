/**
 * @file Player.cpp
 * @author Michal Mastej
 * @brief This is a Player source file. Contains code for all the functions from header file.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "../inc/Player.h"
#include "../inc/Bullet.h"
#include "../inc/Flamethrower.h"
#include "../inc/Laser.h"
#include "../inc/Enemy.h"
#include "../inc/EnemyCyborg.h"
#include "../inc/EnemySentients.h"

/**
 * @brief Construct a new Player:: Player object. Sets all the key flags to false
 * 
 */
Player::Player() {
    this->keyLeftPressed = false;
    this->keyRightPressed = false;
    this->keyUpPressed = false;
    this->keyDownPressed = false;
    this->keySpacebarPressed = false;
    this->keyFlamePressed = false;
    this->keyLaserPressed = false;
}

/**
 * @brief Listens and sets the key flags to true on press
 * 
 * @param event 
 */
void Player::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Left) {
        this->keyLeftPressed = true;
    } else if (event->key() == Qt::Key_Right) {
        this->keyRightPressed = true;
    } else if (event->key() == Qt::Key_Up) {
        this->keyUpPressed = true;
    } else if (event->key() == Qt::Key_Down) {
        this->keyDownPressed = true;
    } else if (event->key() == Qt::Key_Z) {
        this->keySpacebarPressed = true;
    } else if (event->key() == Qt::Key_X) {
        this->keyFlamePressed = true;
    } else if (event->key() == Qt::Key_C) {
        this->keyLaserPressed = true;
    }
}

/**
 * @brief Listens and sets the key flags to false on release
 * 
 * @param event 
 */
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
    } else if (event->key() == Qt::Key_Z) {
        this->keySpacebarPressed = false;
    } else if (event->key() == Qt::Key_X) {
        this->keyFlamePressed = false;
    } else if (event->key() == Qt::Key_C) {
        this->keyLaserPressed = false;
    }
}

/**
 * @brief Slot function to move the Player
 * 
 */
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

/**
 * @brief Slot function to move the bullets
 * 
 */
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

    if (keyLaserPressed) {
        Laser *laser = new Laser();
        laser->setPos(x(), y());
        laser->setBrush(Qt::magenta);
        scene()->addItem(laser);
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

/**
 * @brief Slot position to spawn all the enemy types
 * 
 */
void Player::spawn() {

    int rand_numb = rand() % 3 + 1;

    if (rand_numb == 1) {
        Enemy *enemy = new Enemy();
        enemy->setBrush(Qt::blue);
        scene()->addItem(enemy);
    }
    else if (rand_numb == 2) {
        EnemyCyborg *cyborg_enemy = new EnemyCyborg();
        cyborg_enemy->setBrush(Qt::lightGray);
        scene()->addItem(cyborg_enemy);
    }
    else if (rand_numb == 3) {
        EnemySentients *sentient_enemy = new EnemySentients();
        sentient_enemy->setBrush(Qt::darkRed);
        scene()->addItem(sentient_enemy);
    }

}