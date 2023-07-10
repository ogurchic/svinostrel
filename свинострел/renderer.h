#ifndef RENDERER_H
#define RENDERER_H

#include <windows.h>

// размеры консольного окна
const int screenWidth = 172;
const int screenHeight = 40;

// создание двух буферов
extern CHAR_INFO backBuffer[screenWidth * screenHeight];
extern CHAR_INFO frontBuffer[screenWidth * screenHeight];

// функция для отрисовки символа в заданной позиции в заданном буфере
void drawChar(int x, int y, char c, CHAR_INFO* buffer);

// функция для отрисовки строки в заданной позиции в заданном буфере
void drawString(int x, int y, const char* str, CHAR_INFO* buffer);

// функция для обмена местами двух буферов
void swapBuffers();

// функция для отображения содержимого заднего буфера на экране
void displayBackBuffer();

#endif
