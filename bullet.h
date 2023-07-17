// bullet.h
#ifndef BULLET_H
#define BULLET_H
#include <vector>

const int bulletHitX = 1, bulletHitY = 1; // хитбокс

class Bullet{
public:
    int bullet_x, bullet_y; // позиция по осям X и Y

    Bullet(int startX, int startY, int hitX, int hitY); // конструктор

    void shot();
    void drawBullet();

};

#endif