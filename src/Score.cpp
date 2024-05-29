/**
 * @file Score.cpp
 * @author Michal Mastej
 * @brief Score weapon source file. Contains code for all the functions from header file.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <QFont>

#include "../inc/Score.h"

/**
 * @brief Construct a new Score:: Score object
 * 
 * @param parent 
 */
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    this->score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(this->score));
    setDefaultTextColor(Qt::cyan);
    QGraphicsTextItem::setFont(QFont("Times[Adobe]", 16));
}

/**
 * @brief Returns health number
 * 
 * @return int 
 */
void Score::increase() {
    this->score += 10;
    setPlainText(QString("Score: ") + QString::number(this->score));
}

/**
 * @brief Sets health points
 * 
 * @param health 
 */
int Score::get_score() {
    return this->score;
}

//void Score::resizeEvent(QResizeEvent* event) {
//        QGraphicsView::resizeEvent(event);
//        QRect viewportRect = viewport()->rect();
//        QPointF newPos = QGraphicsView::mapToScene(viewportRect.topLeft() + QPoint(10, 10)); // Adjust these coordinates as needed
//        setPos(newPos);
//    }
