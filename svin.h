//svin.h
#ifndef SVIN_H
#define SVIN_H
class Svin
{
public:
    double x, y; // позици€ свина по ос€м X и Y
    const int hitX = 8, hitY = 4; // хитбокс

    Svin(double startX, double startY); // конструктор
    void moving(); // перемещение свина (авто)
    void draw(); // отобразить свина на экране
};
#endif