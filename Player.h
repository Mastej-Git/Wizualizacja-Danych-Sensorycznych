#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QtGamepad/QGamepad>

class Player : public QObject, public QGraphicsRectItem  {
    Q_OBJECT
public:

    bool keyLeftPressed;
    bool keyRightPressed;
    bool keyUpPressed;
    bool keyDownPressed;
    bool keySpacebarPressed;
    bool keyFlamePressed;
    bool keyLaserPressed;

    Player();

    void keyPressEvent (QKeyEvent *event);
    void keyReleaseEvent (QKeyEvent *event);

public slots:
    void spawn();
    void updatePlayerPosition ();
    void updatePlayerBullets ();
};

#endif // MYRECT_H
