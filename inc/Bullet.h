/**
 * @file Bullet.h
 * @author Michal Mastej
 * @brief Bullet header file. Basic weapon that user can shoot to eliminate enemies. Works on EnemyCyborg type.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

class Bullet : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Bullet();
public slots:
    void move();
};

#endif // BULLET_H
