#ifndef LANGBUTTON_H
#define LANGBUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "QWidget"

class LangButton : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    QGraphicsTextItem *text;

    LangButton(QString name, QGraphicsItem *parent = nullptr);

    void mousePressEvent (QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent (QGraphicsSceneMouseEvent *event);
    void hoverLeaveEvent (QGraphicsSceneMouseEvent *event);
signals:
    void clicked();
};

#endif // LANGBUTTON_H
