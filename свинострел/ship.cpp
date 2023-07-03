// ship.cpp
#include "ship.h"
#include <iostream>
using namespace std;



#include <windows.h>

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
    gotoxy(x, y);
    cout << "       !       \n";
    gotoxy(x, y + 1);
    cout << "      / \\     \n";
    gotoxy(x, y + 2);
    cout << "     |--o|    \n";
    gotoxy(x, y + 3);
    cout << "     |---|    \n";
    gotoxy(x, y + 4);
    cout << "    /     \\   \n";
    gotoxy(x, y + 5);
    cout << "   |   U   |  \n";
    gotoxy(x, y + 6);
    cout << "   |   S   |  \n";
    gotoxy(x, y + 7);
    cout << "   |   S   |  \n";
    gotoxy(x, y + 8);
    cout << "  /|   R   |\\ \n";
    gotoxy(x, y + 9);
    cout << " / |_______| \\ \n";
    gotoxy(x, y + 10);
    cout << "####|@|#|@|####\n";
    gotoxy(x, y + 11);
    cout << "     @   @     \n";
}
