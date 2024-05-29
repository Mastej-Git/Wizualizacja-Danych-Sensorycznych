/**
 * @file AxisPlot.h
 * @author your name (you@domain.com)
 * @brief AxisPlot header file. Plot widget using qcustomplot for thumbstick axis data.
 * @version 0.1
 * @date 2024-05-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef AXISPLOT_H
#define AXISPLOT_H

#include "qcustomplot.h"
#include "Player.h"

/**
 * @brief Uses qcustomplot to reprezent thumbstick axis info on a graph.
 * 
 */

class AxisPlot : public QObject {
Q_OBJECT
public:
    QCustomPlot *plot;
    Player *player;
    double time;

    AxisPlot(Player *player);
public slots:
    void updateGraph();
};

#endif // AXISPLOT_H
