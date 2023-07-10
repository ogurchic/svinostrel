#include "ship.h"
#include "renderer.h"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

Ship::Ship(int startX, int startY) // конструктор
{
    x = startX;
    y = startY;
}

void Ship::moveLeft() // переместить корабль влево
{
    x--;
}

void Ship::moveRight() // переместить корабль вправо
{
    x++;
}

void Ship::moveUp() // переместить корабль вверх
{
    y--;
}

void Ship::moveDown() // переместить корабль вниз
{
    y++;
}

void Ship::draw() // отобразить корабль на экране
{
    drawString(x, y, "       !       ", frontBuffer);
    drawString(x, y + 1, "      / \\     ", frontBuffer);
    drawString(x, y + 2, "     |--o|    ", frontBuffer);
    drawString(x, y + 3, "     |---|    ", frontBuffer);
    drawString(x, y + 4, "    /     \\   ", frontBuffer);
    drawString(x, y + 5, "   |   U   |  ", frontBuffer);
    drawString(x, y + 6, "   |   S   |  ", frontBuffer);
    drawString(x, y + 7, "   |   S   |  ", frontBuffer);
    drawString(x, y + 8, "  /|   R   |\\ ", frontBuffer);
    drawString(x, y + 9, " / |_______| \\ ", frontBuffer);
    drawString(x, y + 10, "####|@|#|@|####", frontBuffer);
    drawString(x, y + 11, "     @   @     ", frontBuffer);
}
