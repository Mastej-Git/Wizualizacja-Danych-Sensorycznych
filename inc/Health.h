/**
 * @file Health.h
 * @author Michal Mastej
 * @brief This is an Health header file. Contains deffinition of an Health class.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsRectItem>
#include <QObject>

class Health: public QGraphicsTextItem {
private:
    int health;
public:
    Health(QGraphicsItem *parent = 0);
    void decrease();
    int get_health();
    void set_heath(int health);
};

#endif // HEALTH_H
