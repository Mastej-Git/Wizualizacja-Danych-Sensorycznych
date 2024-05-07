#include <QDebug>
#include <QBrush>

#include "../inc/ControllerManager.h"

ControllerManager::ControllerManager(QGraphicsEllipseItem *indicator) {
    this->controller_manager = QGamepadManager::instance();
    this->indicator = indicator;
}

void ControllerManager::is_controller_connected() {
    if (this->controller_manager->connectedGamepads().count() > 0) {
        this->indicator->setBrush(Qt::green);

    }
    else {
        this->indicator->setBrush(Qt::red);
    }
}
