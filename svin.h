//svin.h
#ifndef SVIN_H
#define SVIN_H
class Svin
{
public:
    double x, y; // ������� ����� �� ���� X � Y
    const int hitX = 8, hitY = 4; // �������

    Svin(double startX, double startY); // �����������
    void moving(); // ����������� ����� (����)
    void draw(); // ���������� ����� �� ������
};
#endif