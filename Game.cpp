#include <QTimer>
#include <QComboBox>
#include <QGraphicsProxyWidget>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

#include "Game.h"
#include "Enemy.h"
#include "LangButton.h"

Game::Game(QWidget *parent) {

    // create the scene
    this->scene = new QGraphicsScene();
    this->scene->setSceneRect(0, 0, 950, 600);

    // set the scene
    setScene(this->scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(950, 600);
    setBackgroundBrush(QColor("#050d33"));

    // create the player
    this->player = new Player();
    this->player->setRect(0, 0, 100, 100);
    this->player->setPos(800/2 - this->player->rect().height()/2, 600 - this->player->rect().height());
    this->player->setFlag(QGraphicsItem::ItemIsFocusable);
    this->player->setFocus();
    this->player->setBrush(Qt::green);
    this->scene->addItem(this->player);

    // create the score
    this->score = new Score();
    this->scene->addItem(this->score);

    // create the health
    this->health = new Health();
    this->scene->addItem(this->health);

    // create the enemys
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // update player position
    QTimer *timer1 = new QTimer();
    QObject::connect(timer1, SIGNAL(timeout()), player, SLOT(updatePlayerPosition()));
    timer1->start(20);

    // update player bullets
    QTimer *timer2 = new QTimer();
    QObject::connect(timer2, SIGNAL(timeout()), player, SLOT(updatePlayerBullets()));
    timer2->start(100);

    this->drawGUI();

    // create button
//    LangButton *langButton = new LangButton(QString("Language"));
//    int bxPos = this->width()/2 - langButton->boundingRect().width()/2;
//    int byPos = 275;
//    langButton->setPos(bxPos, byPos);
//    connect(langButton, SIGNAL(clicked()), this, SLOT(changeLanguage()));
    //    scene->addItem(langButton);
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity) {

    QGraphicsRectItem *panel = new QGraphicsRectItem(x, y, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::drawGUI() {
    this->drawPanel(800, 0, 150, 600, Qt::black, 1);


    // controller indicator circle
    QGraphicsEllipseItem *connection_indicator = new QGraphicsEllipseItem(810, 12, 20, 20);
    connection_indicator->setBrush(Qt::green);
    connection_indicator->setPen(QPen(Qt::white, 2));

    scene->addItem(connection_indicator);

    // controller indicator text
    QGraphicsTextItem *controller_text = new QGraphicsTextItem("Controller");
    controller_text->setPos(835, 8);
    controller_text->setDefaultTextColor(Qt::white);

    QFont controller_font("Times[Adobe]", 12);
    controller_font.setBold(true);
    controller_text->setFont(controller_font);

    scene->addItem(controller_text);

    // difficulty combo box
    QComboBox *difficulty = new QComboBox();
    difficulty->addItem("Easy");
    difficulty->addItem("Medium");
    difficulty->addItem("Hard");

    difficulty->setFont(controller_font);
    difficulty->setStyleSheet("QComboBox { border: 2px solid grey; }");
    difficulty->setFixedWidth(130);

    QGraphicsProxyWidget *proxy1 = scene->addWidget(difficulty);
    proxy1->setPos(810, 300);

    // difficulty combo box text

    QGraphicsTextItem *difficulty_text = new QGraphicsTextItem("Difficulty level");
    difficulty_text->setPos(807, 277);
    difficulty_text->setDefaultTextColor(Qt::white);

    QFont difficulty_font("Times[Adobe]", 9);
    difficulty_text->setFont(difficulty_font);

    scene->addItem(difficulty_text);

    // language combo box
    QComboBox *language = new QComboBox();
    language->addItem("Polski");
    language->addItem("English");

    language->setFont(controller_font);
    language->setStyleSheet("QComboBox { border: 2px solid grey; }");
    language->setFixedWidth(130);

    QGraphicsProxyWidget *proxy2 = scene->addWidget(language);
    proxy2->setPos(810, 570);

    // language combo box text

    QGraphicsTextItem *language_text = new QGraphicsTextItem("Language");
    language_text->setPos(807, 547);
    language_text->setDefaultTextColor(Qt::white);

    QFont language_font("Times[Adobe]", 9);
    language_text->setFont(language_font);

    scene->addItem(language_text);
}
