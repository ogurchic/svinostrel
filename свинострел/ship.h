// ship.h
#ifndef SHIP_H
#define SHIP_H

class Ship
{
public:
    int x, y; // позиция корабля по осям X и Y

    Ship(int startX, int startY); // конструктор

    void moveLeft(); // переместить корабль влево
    void moveRight(); // переместить корабль вправо
    void moveUp(); // переместить корабль вверх
    void moveDown(); // переместить корабль вниз

    void draw(); // отобразить корабль на экране
};

#endif
