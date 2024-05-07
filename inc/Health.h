/**
 * @file Health.h
 * @author Michal Mastej
 * @brief Health header file. Adds info how many health point does player have. Is located in top left corner how. 
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
    int *language_ptr;

    Health(QGraphicsItem *parent = 0);
    void decrease();
    int get_health();
    void set_heath(int health);
};

#endif // HEALTH_H
