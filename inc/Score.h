/**
 * @file Score.h
 * @author Michal Mastej
 * @brief This is an Score header file. Contains deffinition of an Health class.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem {
private:
    int score;
public:
    Score(QGraphicsItem *parent = 0);
    void increase();
    int get_score();
};

#endif // SCORE_H
