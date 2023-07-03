// main.cpp
#include <conio.h>
#include "ship.h"
#include <windows.h>

int main()
{
    Ship ship(10, 10); // создание корабля с начальной позицией (10, 10)

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
        }

        // Отображение игрового экрана
        system("cls"); // очистка экрана
        ship.draw(); // отобразить корабль на экране

        Sleep(50); // задержка для управления скоростью игрового цикла
    }

    return 0;
}
