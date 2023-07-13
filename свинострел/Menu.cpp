#include <stdio.h>
#include <iostream>

void ShowMenu(int iItem)
{
    system("cls");
    printf("%s Продолжить\n", iItem == 1 ? ">" : " ");
    printf("%s Начать новую игру\n", iItem == 2 ? ">" : " ");
    printf("%s Сохранить\n", iItem == 3 ? ">" : " ");
    printf("%s Загрузить\n", iItem == 4 ? ">" : " ");
    printf("%s Выйти из игры\n", iItem == 5 ? ">" : " ");
}
