//main.cpp
#include <conio.h>
#include "ship.h"
#include "renderer.h"
#include "Svin.h"
#unclude "bullet.h"
#include <vector>

int main()
{
    Ship ship(screenWidth / 2 - 7, screenHeight - 13); // создание корабля с начальной позицией (10, 10)
    Svin svinka1(100, 5); // создание свинки с начальной позицией (100, 5)
    std::vector <Bullet> bullets; // создание вектора для хранения пуль
    
    // инициализация переднего и заднего буферов
    for (int i = 0; i < screenWidth * screenHeight; i++)
    {
        backBuffer[i].Char.AsciiChar = ' ';
        backBuffer[i].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;

        frontBuffer[i].Char.AsciiChar = ' ';
        frontBuffer[i].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
    }

    while (true) // бесконечный игровой цикл
    {
        // Обработка ввода от игрока
        if (_kbhit()) // если игрок нажал клавишу
        {
            int key = _getch(); // получить код нажатой клавиши
            if (key == 224) // если нажата клавиша со стрелкой
            {
                key = _getch(); // получить код нажатой клавиши со стрелкой
                if (key == 72) // если нажата клавиша со стрелкой вверх
                {
                    ship.moveUp(); // переместить корабль вверх
                }
                else if (key == 80) // если нажата клавиша со стрелкой вниз
                {
                    ship.moveDown(); // переместить корабль вниз
                }
                else if (key == 75) // если нажата клавиша со стрелкой влево
                {
                    ship.moveLeft(); // переместить корабль влево
                }
                else if (key == 77) // если нажата клавиша со стрелкой вправо
                {
                    ship.moveRight(); // переместить корабль вправо
                }
            }
            if (key == ' ') // если нажата клавиша пробела (выстрел)
            {
                bullets.push_back(Bullet(ship.x, ship.y)); // создание новой пули с начальной позицией в корабле и скоростью (0, -1)
            }
        }
        
        //перемещение свинки 
        svinka1.moving();

        //перемещение пули
        for (Bullet& bullet : bullets){
            bullet.shot();
            bullet.drawBullet();
        }
        
        // Отображение игрового экрана
        ship.draw(); // отобразить корабль на экране
        svinka1.draw(); // отобразить свинку на экране
        // обмен местами переднего и заднего буферов
        swapBuffers();

        // отображение содержимого заднего буфера на экране
        displayBackBuffer();

        Sleep(20); // задержка для управления скоростью игрового цикла
    }

    return 0;
}
