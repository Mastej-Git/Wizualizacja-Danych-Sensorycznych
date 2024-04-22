/**
 * @file EnemySentients.h
 * @author Michal Mastej
 * @brief This is an EnemySentient header file. Contains deffinition of an EnemySentient class
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
