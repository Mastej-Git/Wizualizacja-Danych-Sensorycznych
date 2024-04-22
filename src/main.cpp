/**
 * @file main.cpp
 * @author Michal Mastej
 * @brief This is a main file.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <QApplication>

#include "../inc/Game.h"

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
