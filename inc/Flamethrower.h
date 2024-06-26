/**
 * @file Flamethrower.h
 * @author Michal Mastej
 * @brief Flamethrower header file. Second weapons type that works on Enemy.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef FLAMETHROWER_H
#define FLAMETHROWER_H

#include <QGraphicsRectItem>
#include <QObject>

/**
 * @brief Second weapon type that Player can use to eliminate enemies. Works on Enemy.
 * 
 */

class Flamethrower : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    double x_move;
    double y_move;

    Flamethrower(double x_move, double y_move);
public slots:
    void move();
};

#endif // FLAMETHROWER_H
