//svin.cpp
#include "Svin.h"
#include "renderer.h"
#include <cmath> 


Svin::Svin(double startX, double startY) // конструктор
{
    x = startX;
    y = startY;
}

void Svin::moving() // перемещение свина
{
    if (y < screenHeight)
    {
        y += round((rand() % 3) * 10) / 200;
        if (x < screenWidth)
            x += round((rand() % 3 - 1) * 10) / 200;
    }
}

void Svin::draw() // отобразить свина на экране
{
    drawString(x, y, "  ^..^ ", frontBuffer, FOREGROUND_GREEN);
    drawString(x, y + 1, "/      \\", frontBuffer, FOREGROUND_GREEN);
    drawString(x, y + 2, "|  (oo)|", frontBuffer, FOREGROUND_GREEN);
    drawString(x, y + 3, "\\  __  /", frontBuffer, FOREGROUND_GREEN);
}