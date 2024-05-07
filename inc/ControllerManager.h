#ifndef CONTROLLERMANAGER_H
#define CONTROLLERMANAGER_H

#include <QGraphicsEllipseItem>
#include <QtGamepad/QGamepadManager>

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
