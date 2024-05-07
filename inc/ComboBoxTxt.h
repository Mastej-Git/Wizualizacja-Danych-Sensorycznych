/**
 * @file ComboBoxTxt.h
 * @author your name (you@domain.com)
 * @brief ComboBoxTxt header file. ComboBox with text above it for brief desription.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef COMBOBOXTXT_H
#define COMBOBOXTXT_H

#include <QComboBox>
#include <QGraphicsTextItem>

#include "Health.h"
#include "Score.h"
#include "Player.h"

class ComboBoxTxt : public QObject {
    Q_OBJECT
public:

    int index;

    QComboBox *combo_box;
    QGraphicsTextItem *text;
    Health *health;
    Score *score;
    Player *player;
    QGraphicsTextItem **texts_table;

    ComboBoxTxt(QStringList list, QString text, int x, int y, Health *health, Score *score, Player *player, QGraphicsTextItem **texts_table);

public slots:
    void change_item(int index);
    void change_language(int index);
};

#endif // COMBOBOXTXT_H
