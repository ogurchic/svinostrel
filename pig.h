//pig.h
#ifndef PIG_H
#define PIG_H

const int pigHitX = 8, pigHitY = 4; // хитбокс

class Pig
{
public:
    int x, y; // позици€ свина по ос€м X и Y
    double X, Y;
    char health_lvl;

    Pig(int startX, int startY, int hitx, int hitY, int health); // конструктор
    void moving(); // перемещение свина (авто)
    void draw(); // отобразить свина на экране
    void health_down();
};
#endif