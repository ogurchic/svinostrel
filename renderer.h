//renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include <windows.h>

// ������� ����������� ����
const int screenWidth = 311;
const int screenHeight = 81;

// �������� ���� �������
extern CHAR_INFO backBuffer[screenWidth * screenHeight];
extern CHAR_INFO frontBuffer[screenWidth * screenHeight];

// ������� ��� ��������� ������� � �������� ������� � �������� ������
void drawChar(int x, int y, int c, CHAR_INFO* buffer, WORD color);

// ������� ��� ��������� ������ � �������� ������� � �������� ������
void drawString(int x, int y, const char* str, CHAR_INFO* buffer, WORD color);

// ������� ��� ������ ������� ���� �������
void swapBuffers();

// ������� ��� ����������� ����������� ������� ������ �� ������
void displayBackBuffer();

#endif
