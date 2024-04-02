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
