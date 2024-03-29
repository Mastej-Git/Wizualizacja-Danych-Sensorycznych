#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QColor>

#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game : public QGraphicsView {
public:
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;

    Game(QWidget *parent = 0);
};

#endif // GAME_H
