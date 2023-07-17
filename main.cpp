//main.cpp
#include <conio.h>
#include "ship.h"
#include "renderer.h"
#include "bullet.h"
#include <vector>
#include "pig.h"
#include <string>

//bool operator==(const Bullet& lhs, const Bullet& rhs) { // для устранения ошибки
//    return lhs.bullet_x == rhs.bullet_x && lhs.bullet_y == rhs.bullet_y;
//}

int main()
{
    Ship ship(screenWidth / 2 - 6, screenHeight - 13, 3, shipHitX, shipHitY); // создание корабля с начальной позицией (10, 10)
    std::vector <Pig> pigs; // 
    std::vector <Bullet> bullets; // создание вектора для хранения пуль

    int score = 0; // 

    DWORD lastCollisionTime = 0; // 
    DWORD lastBulletStartTime = 0; // 
    DWORD lastPigStartTime = 0; //


    // инициализация переднего и заднего буферов
    for (int i = 0; i < screenWidth * screenHeight; i++)
    {
        backBuffer[i].Char.AsciiChar = ' ';
        backBuffer[i].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;

        frontBuffer[i].Char.AsciiChar = ' ';
        frontBuffer[i].Attributes = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED;
    }

    while (ship.health_lvl > 0) // игровой цикл
    {
        if (GetTickCount() - lastPigStartTime >= 10000) // если прошло достаточно времени с момента последнего вызова свиньи
        {
            pigs.push_back(Pig(30, 5, pigHitX, pigHitY, 10)); // создание новой пули с начальной позицией в корабле и скоростью (0, -1)
            lastPigStartTime = GetTickCount(); // обновление времени последнего выстрела
        }

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
            else if (key == ' ') // если нажата клавиша пробела (выстрел)
            {
                if (GetTickCount() - lastBulletStartTime >= 700) // если прошло достаточно времени с момента последнего выстрела
                {
                    bullets.push_back(Bullet(ship.x + 7, ship.y, bulletHitX, bulletHitY)); // создание новой пули с начальной позицией в корабле и скоростью (0, -1)
                    lastBulletStartTime = GetTickCount(); // обновление времени последнего выстрела
                }
            }
        }

        for (Pig& pig : pigs) // поведение при столкновении свиньи и корабля
        {
            if (checkCollision(ship.x, ship.y, shipHitX, shipHitY, pig.X, pig.Y, pigHitX, pigHitY)) {
                if (GetTickCount() - lastCollisionTime > 1000) {
                    ship.healthDown();
                    lastCollisionTime = GetTickCount(); // обновите время последнего столкновения
                }
            }
        }
        

        // Отображение игрового экрана

        ship.draw(); // отобразить корабль на экране

        for (Pig& pig : pigs) // обход всех свиней в векторе
        {
            pig.moving(); // перемещение свиньи
            pig.draw(); // отображение свиньи на экране
        }

        for (Bullet& bullet : bullets) // обновление позиции и отрисовка всех пуль
        {
            bullet.shot();
            bullet.drawBullet();// Обновите положение пули

            for (Pig& pig : pigs)
            {
                if (checkCollision(bullet.bullet_x, bullet.bullet_y, bulletHitX, bulletHitY, pig.X, pig.Y, pigHitX, pigHitY)) {
                    bullets.erase(std::remove(bullets.begin(), bullets.end(), bullet), bullets.end());
                    pig.health_down();
                }
            }
        }
        
        for (auto it = pigs.begin(); it != pigs.end(); ) // обход всех свиней
        {
            if (it->health_lvl <= 0) // если здоровье свиньи равно 0 или меньше
            {
                it = pigs.erase(it); // удаление свиньи из вектора
                score++;
            }
            else
            {
                ++it;
            }
        }



        // рамки и контекст
        for (int i = 0; i <= screenWidth; i++) {
            for (int j = 0; j <= screenHeight; j++) {
                if (i == 0 || j == 0 || i == screenWidth - 1 || j == screenHeight - 1 || i == screenWidth - 49)
                    drawString(i, j, "*", frontBuffer, FOREGROUND_GREEN | FOREGROUND_RED);
                if (i == screenWidth - 45 && j == 10) {
                    int num = ship.health_lvl;
                    std::string str = "Health level: " + std::to_string(num);
                    const char* cstr = str.c_str();
                    drawString(i, j, cstr, frontBuffer, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                }
                if (i == screenWidth - 45 && j == 15) {
                    std::string str = "Your score: " + std::to_string(score);
                    const char* scoreText = str.c_str();
                    drawString(i, j, scoreText, frontBuffer, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                }
                if (i == screenWidth - 45 && j == 20) {
                    int num = pigs.back().health_lvl;
                    std::string str = "Pig`s health level: " + std::to_string(num);
                    const char* cstr = str.c_str();
                    drawString(i, j, cstr, frontBuffer, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
                }
            }
        }

        // обмен местами переднего и заднего буферов
        swapBuffers();
        // отображение содержимого заднего буфера на экране
        displayBackBuffer();

        Sleep(1000 / 60); // задержка для управления скоростью игрового цикла
    }

    return 0;
}