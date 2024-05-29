/**
 * @file ControllerManager.h
 * @author your name (you@domain.com)
 * @brief ControllerManager header file. Circular indicator showing controller connection
 * @version 0.1
 * @date 2024-05-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef CONTROLLERMANAGER_H
#define CONTROLLERMANAGER_H

#include <QGraphicsEllipseItem>
#include <QtGamepad/QGamepadManager>

/**
 * @brief Circular indicator of controller conection in upper right corner.
 * 
 */

class ControllerManager : public QObject {
    Q_OBJECT
public:
    QGamepadManager *controller_manager;
    QGraphicsEllipseItem *indicator;

    ControllerManager(QGraphicsEllipseItem *indicator);
public slots:
    void is_controller_connected();
};

#endif // CONTROLLERMANAGER_H
