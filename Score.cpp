#include <QFont>

#include "Score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent) {
    this->score = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(this->score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Times[Adobe]", 16));
}

void Score::increase() {
    this->score += 10;
    setPlainText(QString("Score: ") + QString::number(this->score));
}

int Score::get_score() {
    return this->score;
}
