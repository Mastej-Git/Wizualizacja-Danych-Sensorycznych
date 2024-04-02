#include <QFont>

#include "Health.h"

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
