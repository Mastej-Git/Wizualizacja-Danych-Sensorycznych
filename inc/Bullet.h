/**
 * @file Bullet.h
 * @author Michal Mastej
 * @brief This is a Bullet header file. Contains deffinition of a bullet class.
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
