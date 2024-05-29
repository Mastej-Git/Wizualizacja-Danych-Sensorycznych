/**
 * @file main.cpp
 * @author Michal Mastej
 * @brief Main running Game class.
 * @version 0.1
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <QApplication>

#include "../inc/Game.h"

Game *game;

/**
 * @brief Main function that runs the Game class
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
