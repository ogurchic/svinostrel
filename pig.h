//svin.h
#ifndef PIG_H
#define PIG_H

const int pigHitX = 8, pigHitY = 4; // хитбокс

class Pig
{
public:
    int x, y; // позици€ свина по ос€м X и Y
    double X, Y;

    Pig(int startX, int startY, int hitx, int hitY); // конструктор
    void moving(); // перемещение свина (авто)
    void draw(); // отобразить свина на экране
};
#endif