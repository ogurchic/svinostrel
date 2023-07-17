//renderer.h
#ifndef RENDERER_H
#define RENDERER_H

#include <windows.h>

// размеры консольного окна
const int screenWidth = 311;
const int screenHeight = 81;

// создание двух буферов
extern CHAR_INFO backBuffer[screenWidth * screenHeight];
extern CHAR_INFO frontBuffer[screenWidth * screenHeight];

// функция для отрисовки символа в заданной позиции в заданном буфере
void drawChar(int x, int y, int c, CHAR_INFO* buffer, WORD color);

// функция для отрисовки строки в заданной позиции в заданном буфере
void drawString(int x, int y, const char* str, CHAR_INFO* buffer, WORD color);

// функция для обмена местами двух буферов
void swapBuffers();

// функция для отображения содержимого заднего буфера на экране
void displayBackBuffer();
// проверка столкновения
bool checkCollision(int x1, int y1, int width1, int height1, int x2, int y2, int width2, int height2);

#endif
