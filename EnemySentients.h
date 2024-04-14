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
