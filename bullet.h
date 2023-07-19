// bullet.h
#ifndef BULLET_H
#define BULLET_H
#include <vector>

const int bulletHitX = 1, bulletHitY = 1; // ������� ����

class Bullet{
public:
    int bullet_x, bullet_y; // ������� �� ���� X � Y

    Bullet(int startX, int startY, int hitX, int hitY); // �����������

    void shot(); // ����� ����
    void drawBullet(); // ��������� ����
};
#endif