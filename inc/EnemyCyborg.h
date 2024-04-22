/**
 * @file EnemyCyborg.h
 * @author Michal Mastej
 * @brief This is an EnemyCyborg header file. Contains deffinition of an EnemyCyborg class
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef ENEMYCYBORG_H
#define ENEMYCYBORG_H

#include <QGraphicsRectItem>
#include <QObject>

class EnemyCyborg : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    EnemyCyborg();
public slots:
    void move();
};

#endif // ENEMYCYBORG_H
