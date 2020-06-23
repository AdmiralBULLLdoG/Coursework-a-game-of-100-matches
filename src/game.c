#include "game.h"
#include "CIO.h"
#include "CLI.h"
#include <stdio.h>
#include <stdlib.h>

void start()
{
    char graphic_mode[255] = {0};
    int graphic_mode_int = 0;
    printf("Добро пожаловать в игру 100 спичек.\n");
    printf("Описание игры: из кучки, первоначально содержащей 100 спичек, двое "
           "играющих поочередно берут по несколько спичек: не менее одной и не "
           "более десяти. Выигрывает взявший последнюю спичку.\n");
    printf("\nВыберите интерфейс, в котором желаете начать игру. Введите "
           "цифру.\n");
    printf("1. CLI(интерфейс командной строки).\n");
    cio_read(graphic_mode);
    graphic_mode_int = atoi(graphic_mode);
    while (graphic_mode_int < 1 || graphic_mode_int > 1
           || graphic_mode_int == 0) {
        printf("\nНекорректный ввод, повторите попытку: ");
        cio_read(graphic_mode);
        graphic_mode_int = atoi(graphic_mode);
    }
    if (graphic_mode_int == 1)
        CLI_start();
}