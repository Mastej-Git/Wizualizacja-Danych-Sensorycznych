#include "../inc/AxisPlot.h"

AxisPlot::AxisPlot(Player *player) {
    this->plot = new QCustomPlot();
    this->plot->setGeometry(10, 10, 130, 180);
    this->plot->addGraph();
    this->plot->addGraph();
    this->plot->yAxis->setRange(-1, 1);

    this->plot->graph(0)->setPen(QPen(Qt::blue));
    this->plot->graph(1)->setPen(QPen(Qt::red));

    this->player = player;
}

void AxisPlot::updateGraph() {
    double key = time;
    double value = qSin(2 * M_PI * key);

    this->plot->graph(0)->addData(key, this->player->xAxisValue);
    this->plot->graph(0)->data()->removeBefore(key - 10);

    this->plot->graph(1)->addData(key, this->player->yAxisValue);
    this->plot->graph(1)->data()->removeBefore(key - 10);

    this->plot->xAxis->setRange(key, 10, Qt::AlignRight);
    this->plot->replot();
    time += 0.1;
}
