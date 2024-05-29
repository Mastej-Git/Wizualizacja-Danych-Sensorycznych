/**
 * @file Game.cpp
 * @author Michal Mastej
 * @brief Game source file. Contains code for all the functions from header file.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <QTimer>
#include <QComboBox>
#include <QGraphicsProxyWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QMainWindow>
#include <QDebug>
#include <QtGamepad/QGamepad>
#include <QtGamepad/QGamepadManager>

#include "../inc/Game.h"
#include "../inc/Enemy.h"
#include "../inc/qcustomplot.h"

/**
 * @brief Construct a new Game:: Game object. Crates and sets all the game components - scene, player, score, health, enemies, GUI. 
 * Also creates signals for enemy spawning, updating player position, updating player projectiles. 
 * 
 * @param parent 
 */
Game::Game(QWidget *parent) {

    // create the scene
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0, 0, 950, 600);

    // set the scene
    setScene(this->scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    setFixedSize(950, 600);
    setBackgroundBrush(QColor("#050d33"));

    // create the player

    QGamepadManager *gamepad_manager = QGamepadManager::instance();

    QGamepad *gamepad = new QGamepad(3302);

    this->player = new Player(gamepad);
//    this->player->setRect(0, 0, 100, 100);
    this->player->setPixmap(QPixmap(":/images/player_ship.png"));
//    this->player->setPos(800/2 - this->player->rect().height()/2, 600 - this->player->rect().height());
    this->player->setPos(800/2 - 50, 600 - 100);
    this->player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->player->setFocus();
//    this->player->setBrush(Qt::green);
    this->scene->addItem(this->player);

    // create the score
    this->score = new Score();
    this->scene->addItem(this->score);

    // create the health
    this->health = new Health();
    this->scene->addItem(this->health);

    // create the enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this->player, SLOT(spawn()));
    timer->start(2000);

    // update player position
    QTimer *timer1 = new QTimer();
    QObject::connect(timer1, SIGNAL(timeout()), this->player, SLOT(updatePlayerPosition()));
    timer1->start(20);

    // update player bullets
    QTimer *timer2 = new QTimer();
    QObject::connect(timer2, SIGNAL(timeout()), this->player, SLOT(updatePlayerBullets()));
    timer2->start(100);

    this->drawGUI();

    QGamepadManager *gamepadManager = QGamepadManager::instance();

        // Check if any gamepad is connected
        if (gamepadManager->connectedGamepads().count() > 0) {
            qDebug() << "At least one gamepad connected.";

            // You can retrieve the connected gamepads and their information
            QList<int> gamepadIds = gamepadManager->connectedGamepads();

            // For demonstration, print out the IDs of the connected gamepads
            qDebug() << "Connected Gamepad IDs:";
            for (int id : gamepadIds) {
                qDebug() << "Gamepad ID:" << id;
            }
        } else {
            qDebug() << "No gamepad connected.";
        }
}

/**
 * @brief Creates GUI background panel wothout any widgets.
 * 
 * @param x 
 * @param y 
 * @param width 
 * @param height 
 * @param color 
 * @param opacity 
 */
void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity) {

    QGraphicsRectItem *panel = new QGraphicsRectItem(x, y, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

/**
 * @brief Draws all the GUI widgets - controller indicator circle, difficulty ComboBoxTxt, language ComboBoxTxt, and all the texts. 
 * 
 */
void Game::drawGUI() {
    this->drawPanel(800, 0, 150, 600, Qt::black, 1);

    // controller indicator circle
    QGraphicsEllipseItem *connection_indicator = new QGraphicsEllipseItem(810, 12, 20, 20);
    connection_indicator->setBrush(Qt::green);
    connection_indicator->setPen(QPen(Qt::white, 2));

    scene->addItem(connection_indicator);

    this->manager = new ControllerManager(connection_indicator);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), this->manager, SLOT(is_controller_connected()));
    timer->start(20);

    // controller indicator text
    QGraphicsTextItem *controller_text = new QGraphicsTextItem("Controller");
    controller_text->setPos(835, 8);
    controller_text->setDefaultTextColor(Qt::white);

    QFont controller_font("Times[Adobe]", 12);
    controller_font.setBold(true);
    controller_text->setFont(controller_font);

    scene->addItem(controller_text);


    // plot
    this->axises_plot = new AxisPlot(this->player);

    QTimer *dataTimer = new QTimer(this);
    QObject::connect(dataTimer, SIGNAL(timeout()), this->axises_plot, SLOT(updateGraph()));
    dataTimer->start(100);

    QGraphicsProxyWidget *proxy3 = scene->addWidget(this->axises_plot->plot);
    proxy3->setPos(810, 70);

    // difficulty combobox and txt
    QStringList list = {"Easy", "Medium", "Hard"};
    this->difficulty = new ComboBoxTxt(list, "Difficulty level", 807, 277, this->health, this->score, this->player, nullptr);

    QGraphicsProxyWidget *proxy1 = scene->addWidget(this->difficulty->combo_box);
    proxy1->setPos(810, 300);
    scene->addItem(this->difficulty->text);

    QObject::connect(this->difficulty->combo_box, SIGNAL(currentIndexChanged(int)), this->difficulty, SLOT(change_item(int)));

    // language combobox and txt

    QGraphicsTextItem **txts_table = new QGraphicsTextItem*[5];
    txts_table[0] = controller_text;
    txts_table[1] = this->difficulty->text;

    QStringList list1 = {"English", "Polski"};
    this->language = new ComboBoxTxt(list1, "Language", 807, 517, this->health, this->score, this->player, txts_table);

    QGraphicsProxyWidget *proxy2 = scene->addWidget(this->language->combo_box);
    proxy2->setPos(810, 540);
    scene->addItem(this->language->text);

    QObject::connect(this->language->combo_box, SIGNAL(currentIndexChanged(int)), this->language, SLOT(change_language(int)));

    this->health->language_ptr = &(this->language->index);

    // chart
    QtCharts::QLineSeries *series = new QtCharts::QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);

    *series << QPointF(11, 1) << QPointF(13, 3) << QPointF(17, 6) << QPointF(18, 3) << QPointF(20, 2);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Axis position");

    QtCharts::QChartView *chartView = new QtCharts::QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
}

void Game::comboBoxChange(int index, QComboBox &language) {
    QString selected_item = language.itemText(index);
    qDebug() << "Selected item: " << selected_item;
}


void Game::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}
