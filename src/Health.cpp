/**
 * @file Health.cpp
 * @author Michal Mastej
 * @brief This is a Health source file. Contains code for all the functions from header file.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <QFont>

#include "../inc/Health.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    this->health = 5;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(this->health));
    setPos(0, 25);
    setDefaultTextColor(Qt::red);
    setFont(QFont("Times[Adobe]", 16));
}

void Health::decrease() {
    this->health--;
    setPlainText(QString("Health: ") + QString::number(this->health));
}

int Health::get_health() {
    return this->health;
}

void Health::set_heath(int health) {
    this->health = health;
    setPlainText(QString("Health: ") + QString::number(this->health));
}
