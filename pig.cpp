//svin.cpp
#include "pig.h"
#include "renderer.h"
#include <cmath> 

// МОЖНО ПЕРЕВОДИТЬ В ДАБЛ ПРЯМО ЗДЕСЬ |
//                                     \/
Pig::Pig(int startX, int startY, int hitX, int hitY) // конструктор
{
    x = startX;
    y = startY;
    X = x;
    Y = y;
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