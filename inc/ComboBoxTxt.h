/**
 * @file ComboBoxTxt.h
 * @author your name (you@domain.com)
 * @brief This is a ComboBoxTxt with text header file. Contains deffinition of a ComboBoxTxt class.
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
#include "Player.h"

class ComboBoxTxt : public QObject {
    Q_OBJECT
public:

    QComboBox *combo_box;
    QGraphicsTextItem *text;
    Health *health;
    Player *player;

    ComboBoxTxt(QStringList list, QString text, int x, int y, Health *health, Player *player);

public slots:
    void change_item(int index);
    void change_language(int index);
};

#endif // COMBOBOXTXT_H
