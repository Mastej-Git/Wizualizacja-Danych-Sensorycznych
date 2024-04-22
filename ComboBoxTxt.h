#ifndef COMBOBOXTXT_H
#define COMBOBOXTXT_H

#include <QComboBox>
#include <QGraphicsTextItem>

#include "Health.h"
#include "Player.h"

class ComboBoxTxt : public QObject {
    Q_OBJECT
public:

    QComboBox *combo_box;
    QGraphicsTextItem *text;
    Health *health;
    Player *player;

    ComboBoxTxt(QStringList list, QString text, int x, int y, Health *health, Player *player);

public slots:
    void change_item(int index);
    void change_language(int index);
};

#endif // COMBOBOXTXT_H
