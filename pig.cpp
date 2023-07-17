//pig.cpp
#include "pig.h"
#include "renderer.h"
#include <cmath> 
#include <math.h>


Pig::Pig(int startX, int startY, int hitX, int hitY, int health) // конструктор
{
    x = startX;
    y = startY;
    X = x;
    Y = y;
    health_lvl = health;
}

void Pig::moving() // перемещение свина
{
    //if (Y < screenHeight)
    //{
        Y = screenHeight / 2.35 * cos(X / 10) + screenHeight / 2.2;
        //if (X < screenWidth)
            X += 0.2;
    //}
}

void Pig::draw() // отобразить свина на экране
{
    drawString(X, Y, "  /\\_____/\\", frontBuffer, FOREGROUND_GREEN);
    drawString(X, Y + 1, " / __    __\\", frontBuffer, FOREGROUND_GREEN);
    drawString(X, Y + 2, "|   @___@   |", frontBuffer, FOREGROUND_GREEN);
    drawString(X, Y + 3, "|    (oo)   |", frontBuffer, FOREGROUND_GREEN);
    drawString(X, Y + 4, " \\    -    /", frontBuffer, FOREGROUND_GREEN);
    drawString(X, Y + 5, "  /-------\\", frontBuffer, FOREGROUND_RED | FOREGROUND_INTENSITY);
    drawString(X, Y + 6, " / /     \\ \\", frontBuffer, FOREGROUND_RED | FOREGROUND_INTENSITY);
    drawString(X, Y + 7, "* / ~~~~~ \\ *", frontBuffer, FOREGROUND_RED | FOREGROUND_INTENSITY);
    drawString(X, Y + 8, "*~~########~~*", frontBuffer, FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void Pig::health_down()
{
    health_lvl--;
}