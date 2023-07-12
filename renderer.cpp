//renderer.cpp
#include "renderer.h"

CHAR_INFO backBuffer[screenWidth * screenHeight];
CHAR_INFO frontBuffer[screenWidth * screenHeight];

void drawChar(int x, int y, char c, CHAR_INFO* buffer, WORD color)
{
    buffer[y * screenWidth + x].Char.AsciiChar = c;
    buffer[y * screenWidth + x].Attributes =  color;
}

void drawString(int x, int y, const char* str, CHAR_INFO* buffer, WORD color)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        drawChar(x + i, y, str[i], buffer, color);
    }
}

void swapBuffers()
{
    // копирование содержимого переднего буфера в задний
    memcpy(backBuffer, frontBuffer, sizeof(CHAR_INFO) * screenWidth * screenHeight);

    // очистка переднего буфера
    for (int i = 0; i < screenWidth * screenHeight; i++)
    {
        frontBuffer[i].Char.AsciiChar = ' ';
        frontBuffer[i].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
    }
}

void displayBackBuffer()
{
    COORD bufferSize = { screenWidth, screenHeight };
    COORD bufferCoord = { 0, 0 };
    SMALL_RECT writeRegion = { 0, 0, screenWidth - 1, screenHeight - 1 };

    WriteConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), backBuffer, bufferSize, bufferCoord, &writeRegion);
}
