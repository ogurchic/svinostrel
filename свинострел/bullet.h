// bullet.h
#ifndef BULLET_H
#define BULLET_H

class Bullet
{
public:
    int bullet_x, bullet_y; // ������� �� ���� X � Y

    Bullet(int startX, int startY); // �����������

    void shot();
    void drawBullet();
};

#endif