//svin.h
#ifndef SVIN_H
#define SVIN_H
class Svin
{
public:
    double x, y; // ������� ����� �� ���� X � Y
    Svin(double startX, double startY); // �����������
    void moving(); // ����������� ����� (����)
    void draw(); // ���������� ����� �� ������
};
#endif