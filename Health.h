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
