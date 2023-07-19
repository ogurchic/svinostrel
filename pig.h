//pig.h
#ifndef PIG_H
#define PIG_H

const int pigHitX = 14, pigHitY = 9; // хитбокс
const int bigpigHitX = 31, bigpigHitY = 16; // хитбокс

class Pig
{
public:
    int x, y; // позиция свина по осям X и Y
    double X, Y; // для функции перемещения
    char health_lvl; // уровень здоровья свиньи

    Pig(int startX, int startY, int hitx, int hitY, int health); // конструктор
    void moving(); // перемещение свина (авто)
    void draw(); // отобразить свина на экране
    void health_down(); // уменьшение здоровья
};
#endif