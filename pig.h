//svin.h
#ifndef PIG_H
#define PIG_H

const int pigHitX = 8, pigHitY = 4; // �������

class Pig
{
public:
    int x, y; // ������� ����� �� ���� X � Y
    double X, Y;

    Pig(int startX, int startY, int hitx, int hitY); // �����������
    void moving(); // ����������� ����� (����)
    void draw(); // ���������� ����� �� ������
};
#endif