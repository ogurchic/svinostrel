// ship.h
#ifndef SHIP_H
#define SHIP_H

const int shipHitX = 15, shipHitY = 12; // размер объекта

class Ship
{
public:
    int x, y; // позиция корабля по осям X и Y
    char health_lvl; // уровень здоровья
    
    Ship(int startX, int startY, char healthLevel, int hitX, int hitY); // конструктор

    void moveLeft(); // переместить корабль влево
    void moveRight(); // переместить корабль вправо
    void moveUp(); // переместить корабль вверх
    void moveDown(); // переместить корабль вниз
    void healthDown();
    void draw(); // отобразить корабль на экране
};

#endif