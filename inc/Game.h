/**
 * @file Game.h
 * @author Michal Mastej
 * @brief This is a Game header file. Contains deffinition of an Game class.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QColor>
#include <QComboBox>
//#include <QGamepad>

#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "ComboBoxTxt.h"

class Game : public QGraphicsView {
public:
    QGraphicsScene *scene;
    Player *player;
    Score *score;
    Health *health;
    ComboBoxTxt *difficulty, *language;

    Game(QWidget *parent = 0);

    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    void drawGUI();
    void comboBoxChange(int index, QComboBox &language);
};

#endif // GAME_H
