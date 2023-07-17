//pig.cpp
#include "pig.h"
#include "renderer.h"
#include <cmath> 


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
    if (Y < screenHeight)
    {
        Y += round((rand() % 3) * 10) / 200;
        if (X < screenWidth)
            X += round((rand() % 3 - 1) * 10) / 200;
    }
}

void Pig::draw() // отобразить свина на экране
{
    drawString(X, Y, "  ^..^ ", frontBuffer, FOREGROUND_GREEN);
    drawString(X, Y + 1, "/      \\", frontBuffer, FOREGROUND_GREEN);
    drawString(X, Y + 2, "|  (oo)|", frontBuffer, FOREGROUND_GREEN);
    drawString(X, Y + 3, "\\  __  /", frontBuffer, FOREGROUND_GREEN);
}

void Pig::health_down()
{
    health_lvl--;
}