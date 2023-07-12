//svin.h
#ifndef SVIN_H
#define SVIN_H
class Svin
{
public:
    double x, y; // позиция свина по осям X и Y
    Svin(double startX, double startY); // конструктор
    void moving(); // перемещение свина (авто)
    void draw(); // отобразить свина на экране
};
#endif