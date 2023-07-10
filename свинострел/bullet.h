// bullet.h
#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:
    int bullet_x, bullet_y; // позиция по осям X и Y

    Bullet(int startX, int startY); // конструктор

    void shot();
    void drawBullet();
};

#endif