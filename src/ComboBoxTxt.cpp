/**
 * @file ComboBoxTxt.cpp
 * @author Michal Mastej
 * @brief This is a ComboBoxTxt with text source file. Contains code for all the functions from header file.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../inc/ComboBoxTxt.h"
#include "QDebug"

ComboBoxTxt::ComboBoxTxt(QStringList list, QString text, int x, int y, Health *health, Player *player) {

    this->combo_box = new QComboBox();

    for (auto item : list) {
        this->combo_box->addItem(item);
    }

    QFont text_font("Times[Adobe]", 12);
    text_font.setBold(true);

    this->combo_box->setFont(text_font);
    this->combo_box->setStyleSheet("QComboBox { border: 2px solid grey; }");
    this->combo_box->setFixedWidth(130);

    this->text = new QGraphicsTextItem(text);
    this->text->setPos(x, y);
    this->text->setDefaultTextColor(Qt::white);
    this->text->setFont(QFont("Times[Adobe]", 9));

    this->health = health;
    this->player = player;
}

void ComboBoxTxt::change_item(int index) {
    if (index == 0) {
        this->health->set_heath(5);
    }
    else if (index == 1) {
        this->health->set_heath(3);
    }
    else {
        this->health->set_heath(1);
    }
    this->player->setFocus();
}

void ComboBoxTxt::change_language(int index) {
    if (index == 0) {
        qDebug() << "Zmieniono język na Polski";
    }
    else {
        qDebug() << "Changed language to english";
    }

    this->player->setFocus();
}
