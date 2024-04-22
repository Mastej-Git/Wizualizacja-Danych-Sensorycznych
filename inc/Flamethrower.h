/**
 * @file Flamethrower.h
 * @author Michal Mastej
 * @brief This is a Flamethrower weapon header file. Contains deffinition of an Flamethrower class
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
