/**
 * @file Laser.h
 * @author your name (you@domain.com)
 * @brief Laser header file. Third wapon type that player can use. Works on Enemy Sentients.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef LASER_H
#define LASER_H

#include <QGraphicsRectItem>
#include <QObject>

class Laser : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    Laser();
public slots:
    void move();
};

#endif // LASER_H
