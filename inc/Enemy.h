/**
 * @file Enemy.h
 * @author Michal Mastej
 * @brief This is an Enemy header file. Contains deffinition of an Enemy class.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>
#include <QObject>

class Enemy : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
};

#endif // ENEMY_H
