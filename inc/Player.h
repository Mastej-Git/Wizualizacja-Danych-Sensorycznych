/**
 * @file Player.h
 * @author Michal Mastej
 * @brief Player header file. Player is controllabe character that user can play. It can shot at move.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QtGamepad/QGamepad>

class Player : public QObject, public QGraphicsRectItem  {
    Q_OBJECT
public:

    QGamepad *gamepad;

    bool keyLeftPressed;
    bool keyRightPressed;
    bool keyUpPressed;
    bool keyDownPressed;
    bool keySpacebarPressed;
    bool keyFlamePressed;
    bool keyLaserPressed;

    Player(QGamepad *gamepad);

    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void gamepadPressEvent();

public slots:
    void spawn();
    void updatePlayerPosition ();
    void updatePlayerBullets ();


    void handleButtonLeftChange();
    void handleButtonRightChange();
    void handleButtonUpChange();
    void handleButtonDownChange();

    void handleButtonXChange();
    void handleButtonSqChange();
    void handleButtonTrChange();

    void handleXAxisLeftThumbstick(double value);
    void handleYAxisLeftThumbstick(double value);
};

#endif // MYRECT_H
