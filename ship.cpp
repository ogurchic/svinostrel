//ship.cpp
#include "ship.h"
#include "renderer.h"


Ship::Ship(int startX, int startY, char healthLevel, int hitX, int hitY) // конструктор
{
    x = startX;
    y = startY;
    health_lvl = healthLevel;
}

void Ship::moveLeft() // переместить корабль влево
{
    if (x > 2)
        x-=2;
}

void Ship::moveRight() // переместить корабль вправо
{
    if (x <= screenWidth - 66)
        x+=2;
}

void Ship::moveUp() // переместить корабль вверх
{
    if (y > 1)
        y--;
}

void Ship::moveDown() // переместить корабль вниз
{
    if (y < screenHeight - 13)
        y++;
}

void Ship::healthDown()
{
    health_lvl--;
}

void Ship::draw() // отобразить корабль на экране
{
    drawString(x, y, "       !       ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 1, "      /-\\     ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 2, "     |--o|    ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 3, "     |---|    ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 4, "    /.....\\   ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 5, "   |   U   |  ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 6, "   |   S   |  ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 7, "   |   S   |  ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 8, "  /|   R   |\\ ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 9, " / |_______| \\ ", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 10, "####|@|#|@|####", frontBuffer, FOREGROUND_RED);
    drawString(x, y + 11, "     @   @     ", frontBuffer, FOREGROUND_RED);
}
