#include <QGraphicsTextItem>
#include "LangButton.h"

LangButton::LangButton(QString name, QGraphicsItem *parent):
    QGraphicsRectItem(parent)
{

    setRect(0, 0, 200, 50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    this->text = new QGraphicsTextItem(name, this);
    int xPos = rect().width() / 2 - text->boundingRect().width()/2;
    int yPos = rect().height() / 2 - text->boundingRect().height()/2;
    text->setPos(xPos, yPos);

    setAcceptHoverEvents(true);
}

void LangButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked();
}

void LangButton::hoverEnterEvent(QGraphicsSceneMouseEvent *event) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void LangButton::hoverLeaveEvent(QGraphicsSceneMouseEvent *event) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}
