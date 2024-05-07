/**
 * @file EnemySentients.h
 * @author Michal Mastej
 * @brief EnemySentients header file. Third type of enemy that spawns randomly in the game. Is weak to Laser.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ENEMYSENTIENTS_H
#define ENEMYSENTIENTS_H

#include <QGraphicsRectItem>
#include <QObject>

class EnemySentients : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    EnemySentients();
public slots:
    void move();
};

#endif // ENEMYSENTIENTS_H
