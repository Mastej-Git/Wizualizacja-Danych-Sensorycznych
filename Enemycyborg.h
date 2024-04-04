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
