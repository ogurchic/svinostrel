#ifndef RENDERER_H
#define RENDERER_H

#include <windows.h>

// ������� ����������� ����
const int screenWidth = 172;
const int screenHeight = 40;

// �������� ���� �������
extern CHAR_INFO backBuffer[screenWidth * screenHeight];
extern CHAR_INFO frontBuffer[screenWidth * screenHeight];

// ������� ��� ��������� ������� � �������� ������� � �������� ������
void drawChar(int x, int y, char c, CHAR_INFO* buffer);

// ������� ��� ��������� ������ � �������� ������� � �������� ������
void drawString(int x, int y, const char* str, CHAR_INFO* buffer);

// ������� ��� ������ ������� ���� �������
void swapBuffers();

// ������� ��� ����������� ����������� ������� ������ �� ������
void displayBackBuffer();

#endif
